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

    // Select operator
    std::string op;
    if (ctx->PLUS())
        op = "+";
    else if (ctx->MINUS())
        op = "-";
    else if (ctx->MUL())
        op = "*";
    else if (ctx->DIV())
        op = "/";

    // -------------------------------------------------------
    // (2) Parenthesized expression: (expr)
    // -------------------------------------------------------
    if (ctx->expression().size() == 1 && op.empty()) {
        return visit(ctx->expression(0));
    }

    // -------------------------------------------------------
    // (3) Binary expression
    // -------------------------------------------------------
    if (!op.empty() && ctx->expression().size() >= 2) {
        json left = std::any_cast<json>(visit(ctx->expression(0)));
        json right = std::any_cast<json>(visit(ctx->expression(1)));

        json node = utils::Helpers::createNode(ctx->getText(), "Expression", ctx->start, ctx->stop);
        node["left"] = left;
        node["right"] = right;
        node["operator"] = op;

        // Allowed numeric literal types
        auto isAllowed = [&](const json& j) {
            std::string k = j["kind"].get<std::string>();
            return k == "IntegerLiteral" || k == "FloatLiteral" || k == "BooleanLiteral" || k == "NoneLiteral" || k == "Expression";
        };

        // Reject string or unsupported literal types
        if (!isAllowed(left) || !isAllowed(right)) {
            node["error"] = "Arithmetic only allowed on numeric literals (int, float, bool, none)";
            return node;
        }

        // Convert JSON literal to double
        auto toDouble = [&](const json& j) -> double {
            std::string k = j["kind"].get<std::string>();

            // Boolean → numeric
            if (k == "BooleanLiteral") {
                std::string v = j["value"].get<std::string>();
                return (v == "true") ? 1.0 : 0.0;
            }

            // NoneLiteral → numeric 0
            if (k == "NoneLiteral") {
                return 0.0;
            }

            // Integer / Float literal: string or number
            if (j["value"].is_number())
                return j["value"].get<double>();

            return std::stod(j["value"].get<std::string>());
        };

        double L = 0.0, R = 0.0;

        try {
            L = toDouble(left);
            R = toDouble(right);
        } catch (const std::exception& e) {
            node["error"] = std::string("Invalid numeric literal: ") + e.what();
            return node;
        }

        // ---------------------------------------------------
        // Perform arithmetic — ALWAYS error if dividing by 0
        // ---------------------------------------------------
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

        node["value"] = result;
        node["stringValue"] = std::to_string(result);
        return node;
    }

    // -------------------------------------------------------
    // (4) Fallback
    // -------------------------------------------------------
    if (!ctx->expression().empty())
        return visit(ctx->expression(0));

    return json::object();
}
