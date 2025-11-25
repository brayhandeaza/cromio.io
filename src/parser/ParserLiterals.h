//
// Created by Brayhan De Aza on 10/19/25.
//

#ifndef CROMIO_PARSER_LITERALS_H
#define CROMIO_PARSER_LITERALS_H

#include "GrammarVisitor.h"
#include "helpers/Helpers.h"


class ParserLiterals : public virtual GrammarVisitor {
public:
    std::any visitLiteral(Grammar::LiteralContext* ctx) override {
        if (ctx->stringLiteral()) {
            json node = Helpers::createNode(ctx->getText(), "StringLiteral", ctx->start, ctx->stop);
            const std::any stringLiteral = visit(ctx->stringLiteral());

            node["value"] = std::any_cast<json>(stringLiteral);
            return node;
        }
        if (ctx->integerLiteral()) {
            const std::any integerLiteral = visit(ctx->integerLiteral());
            return std::any_cast<json>(integerLiteral);
        }
        if (ctx->floatLiteral()) {
            const std::any floatLiteral = visit(ctx->floatLiteral());
            return std::any_cast<json>(floatLiteral);
        }
        if (ctx->booleanLiteral()) {
            const std::any booleanLiteral = visit(ctx->booleanLiteral());
            return std::any_cast<json>(booleanLiteral);
        }
        if (ctx->noneLiteral()) {
            const std::any noneLiteral = visit(ctx->noneLiteral());
            return std::any_cast<json>(noneLiteral);
        }
        if (ctx->formattedString()) {
            const std::any formattedString = visit(ctx->formattedString());
            return std::any_cast<json>(formattedString);
        }

        json node = Helpers::createNode("", "None", ctx->start, ctx->stop);
        return node;
    }

    std::any visitIntegerLiteral(Grammar::IntegerLiteralContext* ctx) override {
        json node = Helpers::createNode(ctx->getText(), "IntegerLiteral", ctx->start, ctx->stop);
        node["value"] = Helpers::parseInteger(ctx->getText());

        return node;
    }

    std::any visitFloatLiteral(Grammar::FloatLiteralContext* ctx) override {
        json node = Helpers::createNode(ctx->getText(), "FloatLiteral", ctx->start, ctx->stop);
        node["value"] = Helpers::parseFloat(ctx->getText());

        return node;
    }

    std::any visitStringLiteral(Grammar::StringLiteralContext* ctx) override {
        json node = Helpers::createNode(ctx->getText(), "StringLiteral", ctx->start, ctx->stop);
        node["value"] = Helpers::parseString(ctx->getText());

        return node;
    }

    std::any visitBooleanLiteral(Grammar::BooleanLiteralContext* ctx) override {
        json node = Helpers::createNode(ctx->getText(), "BooleanLiteral", ctx->start, ctx->stop);
        node["value"] = ctx->getText() == "true";

        return node;
    }

    std::any visitNoneLiteral(Grammar::NoneLiteralContext* ctx) override {
        json node = Helpers::createNode(ctx->getText(), "NoneLiteral", ctx->start, ctx->stop);
        node["value"] = nullptr;

        return node;
    }
};

#endif //CROMIO_PARSER_LITERALS_H