//
// Created by Brayhan De Aza on 12/4/25.
//

#include "ExpressionVisitor.h"

std::any cromio::visitor::ExpressionVisitor::visitExpression(Grammar::ExpressionContext* ctx) {
    // -------------------------------------------------------
    // (1) Literal → return literal node
    // -------------------------------------------------------
    if (ctx->literal()) {
        return visit(ctx->literal());
    }

    // -------------------------------------------------------
    // (2) Detect operator
    // -------------------------------------------------------
    std::string op;

    if (ctx->PLUS())
        op = "+";
    else if (ctx->MINUS())
        op = "-";
    else if (ctx->MUL())
        op = "*";
    else if (ctx->DIV())
        op = "/";
    else if (ctx->MOD())
        op = "%";

    // -------------------------------------------------------
    // (3) Parenthesized expression
    // -------------------------------------------------------
    if (ctx->expression().size() == 1 && op.empty()) {
        return visit(ctx->expression(0));
    }

    // -------------------------------------------------------
    // (4) Binary expression
    // -------------------------------------------------------
    if (!op.empty() && ctx->expression().size() >= 2) {
        json leftNode = std::any_cast<json>(visit(ctx->expression(0)));
        json rightNode = std::any_cast<json>(visit(ctx->expression(1)));

        // Resolve IdentifierLiteral values if they point to variables
        auto resolveIdentifier = [&](json& node) {
            if (node["kind"] == "IdentifierLiteral") {
                // Replace the value with the underlying literal
                if (node.contains("value")) {
                    node = node["value"];
                } else {
                    node["error"] = "Undefined identifier";
                }
            }
        };

        resolveIdentifier(leftNode);
        resolveIdentifier(rightNode);

        json node = createNode(ctx->getText(), "Expression", ctx->start, ctx->stop);
        node["left"] = leftNode;
        node["right"] = rightNode;
        node["operator"] = op;

        // Types allowed in arithmetic
        auto isAllowed = [&](const json& j) {
            const std::string k = j["kind"].get<std::string>();
            return k == "IntegerLiteral" || k == "IdentifierLiteral" || k == "FloatLiteral" || k == "BooleanLiteral" || k == "NoneLiteral" || k == "Expression";
        };

        if (!isAllowed(leftNode) || !isAllowed(rightNode)) {
            node["error"] = "Arithmetic only allowed on numeric literals (int, float, bool, none)";
            return node;
        }

        // Convert JSON → double
        auto toDouble = [&](const json& j) -> double {
            const std::string k = j["kind"];

            if (k == "BooleanLiteral")
                return j["value"] == "true" ? 1.0 : 0.0;

            if (k == "NoneLiteral")
                return 0.0;

            if (j["value"].is_number())
                return j["value"].get<double>();

            return std::stod(j["value"].get<std::string>());
        };

        double L = 0.0, R = 0.0;

        try {
            L = toDouble(leftNode);
            R = toDouble(rightNode);
        } catch (...) {
            node["error"] = "Invalid numeric literal";
            return node;
        }

        // -------------------------------------------------------
        // (5) Perform arithmetic
        // -------------------------------------------------------
        double result = 0.0;

        if (op == "+")
            result = L + R;
        else if (op == "-")
            result = L - R;
        else if (op == "*")
            result = L * R;
        else if (op == "/") {
            if (R == 0.0) {
                node["error"] = "Division by zero";
                return node;
            }
            result = L / R;
        } else if (op == "%") {
            if (R == 0.0) {
                node["error"] = "Modulo by zero";
                return node;
            }
            if (L == static_cast<int>(L) && R == static_cast<int>(R))
                result = static_cast<int>(L) % static_cast<int>(R);
            else
                result = std::fmod(L, R);
        }

        // -------------------------------------------------------
        // (6) Determine final data type
        // -------------------------------------------------------
        auto determineType = [&](const std::string& mOp, const json& mLeft, const json& mRight) -> std::string {
            const bool leftFloat = mLeft["kind"] == "FloatLiteral";
            const bool rightFloat = mRight["kind"] == "FloatLiteral";

            if (leftFloat || rightFloat)
                return "float";
            if (mLeft["kind"] == "BooleanLiteral" || mRight["kind"] == "BooleanLiteral")
                return "int";
            if (mLeft["kind"] == "NoneLiteral" || mRight["kind"] == "NoneLiteral")
                return "int";
            if (mOp == "%")
                return "int";
            if (mOp == "/")
                return "float";
            return "int";
        };

        std::string finalType = determineType(op, leftNode, rightNode);

        // -------------------------------------------------------
        // (7) Store results
        // -------------------------------------------------------
        node["value"] = result;
        node["stringValue"] = std::to_string(result);
        node["numberValue"] = std::to_string(result);
        node["type"] = finalType;

        return node;
    }

    // -------------------------------------------------------
    // (8) Fallback
    // -------------------------------------------------------
    if (!ctx->expression().empty())
        return visit(ctx->expression(0));

    return json::object();
}
