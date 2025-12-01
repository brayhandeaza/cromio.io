//
// Created by Brayhan De Aza on 11/27/25.
//

#include "BaseParser.h"
#include "semantic/AST.h"

std::any cromio::parser::Parser::visitProgram(Grammar::ProgramContext* ctx) {
    json node = utils::Helpers::createNode("", "Program", ctx->start, ctx->stop);

    json body;
    for (const auto child : ctx->children) {
        if (const std::any statement = visit(child); statement.has_value()) {
            body.push_back(std::any_cast<json>(statement));
        }
    }

    node["Body"] = body;

    json ast = semantic::ASTAnalizy::analyze(node);
    return ast;
}

std::any cromio::parser::Parser::visitStatement(Grammar::StatementContext* ctx) {
    if (ctx->expression()) {
        const std::any expression = visit(ctx->expression());
        return std::any_cast<json>(expression);
    }

    if (ctx->variableDeclaration()) {
        const std::any variableDeclaration = visit(ctx->variableDeclaration());
        return std::any_cast<json>(variableDeclaration);
    }

    return json::object();
}

std::any cromio::parser::Parser::visitExpression(Grammar::ExpressionContext* ctx) {
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
        const json left = std::any_cast<json>(visit(ctx->expression(0)));
        const json right = std::any_cast<json>(visit(ctx->expression(1)));

        json node = utils::Helpers::createNode(ctx->getText(), "Expression", ctx->start, ctx->stop);
        node["left"] = left;
        node["right"] = right;
        node["operator"] = op;

        // Types allowed in arithmetic
        auto isAllowed = [&](const json& j) {
            std::string k = j["kind"].get<std::string>();
            return k == "IntegerLiteral" || k == "FloatLiteral" || k == "BooleanLiteral" || k == "NoneLiteral" || k == "Expression";
        };

        if (!isAllowed(left) || !isAllowed(right)) {
            node["error"] = "Arithmetic only allowed on numeric literals (int, float, bool, none)";
            return node;
        }

        // Convert JSON → double
        auto toDouble = [&](const json& j) -> double {
            std::string k = j["kind"];

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
            L = toDouble(left);
            R = toDouble(right);
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
        }

        else if (op == "%") {
            if (R == 0.0) {
                node["error"] = "Modulo by zero";
                return node;
            }

            // int % int
            if (L == (int)L && R == (int)R) {
                result = (int)L % (int)R;
            }
            // float modulo → fmod
            else {
                result = std::fmod(L, R);
            }
        }

        // -------------------------------------------------------
        // (6) Determine final data type
        // -------------------------------------------------------
        auto determineType = [&](double L, double R, const std::string& op, const json& left, const json& right) -> std::string {
            bool leftFloat = left["kind"] == "FloatLiteral";
            bool rightFloat = right["kind"] == "FloatLiteral";

            if (leftFloat || rightFloat)
                return "float";

            if (left["kind"] == "BooleanLiteral" || right["kind"] == "BooleanLiteral")
                return "int";

            if (left["kind"] == "NoneLiteral" || right["kind"] == "NoneLiteral")
                return "int";

            if (op == "%")
                return "int";

            if (op == "/")
                return "float";

            return "int";
        };

        std::string finalType = determineType(L, R, op, left, right);

        // -------------------------------------------------------
        // (7) Store results
        // -------------------------------------------------------
        node["value"] = result;
        node["stringValue"] = std::to_string(result);
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
