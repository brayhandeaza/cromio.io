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
    // 1) Literal -> just visit the literal and return it
    if (ctx->literal()) {
        return visit(ctx->literal());
    }

    std::string op;
    if (ctx->PLUS())
        op = "+";
    else if (ctx->MINUS())
        op = "-";
    else if (ctx->MUL())
        op = "*";
    else if (ctx->DIV())
        op = "/";

    // 2) Parenthesized expression: usually represented as one child expression and no operator.
    //    Example: '(' expression ')'
    if (ctx->expression().size() == 1 && op.empty()) {
        return visit(ctx->expression(0));
    }

    // 3) Binary expression: operator present and at least two expression children
    if (!op.empty() && ctx->expression().size() >= 2) {
        // visit children (they should each return json wrapped in std::any)
        const auto leftAny = visit(ctx->expression(0));
        const auto rightAny = visit(ctx->expression(1));

        json leftJson = json::object();
        json rightJson = json::object();

        // be defensive about any_cast
        try {
            leftJson = std::any_cast<json>(leftAny);
        } catch (const std::bad_any_cast&) {
            // optionally try to handle other returned types or set an error marker
        }

        try {
            rightJson = std::any_cast<json>(rightAny);
        } catch (const std::bad_any_cast&) {
            // handle if needed
        }

        json node = utils::Helpers::createNode(ctx->getText(), "Expression", ctx->start, ctx->stop);
        node["left"] = leftJson;
        node["operator"] = op;
        node["right"] = rightJson;

        // Calculate the final value of the expression
        double finalValue = 0.0;
        bool hasValue = false;

        if (leftJson.contains("value") && rightJson.contains("value")) {
            try {
                double leftValue = 0.0;
                double rightValue = 0.0;

                // Handle both string and numeric values
                if (leftJson["value"].is_string()) {
                    leftValue = std::stod(leftJson["value"].get<std::string>());
                } else if (leftJson["value"].is_number()) {
                    leftValue = leftJson["value"].get<double>();
                }

                if (rightJson["value"].is_string()) {
                    rightValue = std::stod(rightJson["value"].get<std::string>());
                } else if (rightJson["value"].is_number()) {
                    rightValue = rightJson["value"].get<double>();
                }

                // Perform the operation
                if (op == "+") {
                    finalValue = leftValue + rightValue;
                    hasValue = true;
                } else if (op == "-") {
                    finalValue = leftValue - rightValue;
                    hasValue = true;
                } else if (op == "*") {
                    finalValue = leftValue * rightValue;
                    hasValue = true;
                } else if (op == "/") {
                    if (rightValue != 0.0) {
                        finalValue = leftValue / rightValue;
                        hasValue = true;
                    } else {
                        // Handle division by zero
                        node["error"] = "Division by zero";
                    }
                }
            } catch (const std::exception& e) {
                // Handle conversion errors
                node["error"] = std::string("Value calculation error: ") + e.what();
            }
        }

        // Store the calculated value
        if (hasValue)
            node["value"] = finalValue;

        return node;
    }

    // 4) Fallback: if grammar has other expression shapes (unary, etc.), try visiting children
    //    or return empty object (adjust to your needs)
    if (!ctx->expression().empty()) {
        // if there's a single child but operator was non-null (rare) or other shape, try to visit first child
        return visit(ctx->expression(0));
    }

    return json::object();
}