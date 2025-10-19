//
// Created by Brayhan De Aza on 10/19/25.
//

#ifndef CROMIO_VISITOR_H
#define CROMIO_VISITOR_H

#include "GrammarVisitor.h"
#include "Helpers.h"

class Visitor final : public GrammarVisitor {
public:
    std::any visitProgram(Grammar::ProgramContext *ctx) override {
        json node = Helpers::createNode("", "Program", ctx->start, ctx->stop);

        json body;
        for (const auto child: ctx->children) {
            const std::any statement = visit(child);

            if (statement.has_value()) {
                body.push_back(std::any_cast<json>(statement));
            }
        }

        node["Body"] = body;
        return node;
    }

    std::any visitStatement(Grammar::StatementContext *ctx) override {
        json node = Helpers::createNode("", "Statement", ctx->start, ctx->stop);
        if (ctx->expression()) {
            const std::any expression = visit(ctx->expression());

            node["Expression"] = std::any_cast<json>(expression);
            return node;
        }

        return json::object();
    }

    std::any visitExpression(Grammar::ExpressionContext *ctx) override {
        if (ctx->literal()) {
            json expression = Helpers::createNode("", "Expression", ctx->start, ctx->stop);
            const std::any literal = visit(ctx->literal());

            return std::any_cast<json>(literal);
        }

        return json::object();
    }

    std::any visitLiteral(Grammar::LiteralContext *ctx) override {
        if (ctx->stringLiteral()) {
            json node = Helpers::createNode(ctx->getText(), "StringLiteral", ctx->start, ctx->stop);
            const std::any stringLiteral = visit(ctx->stringLiteral());

            node["value"] = std::any_cast<json>(stringLiteral);
            return node;
        }
        if (ctx->integerLiteral()) {
            json node = Helpers::createNode(ctx->getText(), "IntegerLiteral", ctx->start, ctx->stop);
            const std::any integerLiteral = visit(ctx->integerLiteral());

            return std::any_cast<json>(integerLiteral);
        }
        if (ctx->floatLiteral()) {
            json node = Helpers::createNode(ctx->getText(), "FloatLiteral", ctx->start, ctx->stop);
            const std::any floatLiteral = visit(ctx->floatLiteral());

            return std::any_cast<json>(floatLiteral);
        }
        if (ctx->booleanLiteral()) {
            json node = Helpers::createNode(ctx->getText(), "BooleanLiteral", ctx->start, ctx->stop);
            const std::any booleanLiteral = visit(ctx->booleanLiteral());

            return std::any_cast<json>(booleanLiteral);
        }
        if (ctx->noneLiteral()) {
            json node = Helpers::createNode(ctx->getText(), "NoneLiteral", ctx->start, ctx->stop);
            const std::any noneLiteral = visit(ctx->noneLiteral());

            return std::any_cast<json>(noneLiteral);
        }

        json node = Helpers::createNode("", "None", ctx->start, ctx->stop);
        return node;
    }

    std::any visitFormattedString(Grammar::FormattedStringContext *ctx) override {
        return visitChildren(ctx);
    }

    std::any visitFormattedStringContent(Grammar::FormattedStringContentContext *ctx) override {
        return visitChildren(ctx);
    }

    std::any visitFormattedStringExpression(Grammar::FormattedStringExpressionContext *ctx) override {
        return visitChildren(ctx);
    }

    std::any visitIntegerLiteral(Grammar::IntegerLiteralContext *ctx) override {
        json node = Helpers::createNode(ctx->getText(), "IntegerLiteral", ctx->start, ctx->stop);
        node["value"] = Helpers::parseInteger(ctx->getText());

        return node;
    }

    std::any visitFloatLiteral(Grammar::FloatLiteralContext *ctx) override {
        json node = Helpers::createNode(ctx->getText(), "FloatLiteral", ctx->start, ctx->stop);
        node["value"] = Helpers::parseFloat(ctx->getText());

        return node;
    }

    std::any visitStringLiteral(Grammar::StringLiteralContext *ctx) override {
        json node = Helpers::createNode(ctx->getText(), "StringLiteral", ctx->start, ctx->stop);
        node["value"] = Helpers::parseString(ctx->getText());

        return node;
    }

    std::any visitBooleanLiteral(Grammar::BooleanLiteralContext *ctx) override {
        json node = Helpers::createNode(ctx->getText(), "BooleanLiteral", ctx->start, ctx->stop);
        node["value"] = ctx->getText() == "true";

        return node;
    }

    std::any visitNoneLiteral(Grammar::NoneLiteralContext *ctx) override {
        json node = Helpers::createNode(ctx->getText(), "NoneLiteral", ctx->start, ctx->stop);
        node["value"] = nullptr;

        return node;
    }
};

#endif //CROMIO_VISITOR_H
