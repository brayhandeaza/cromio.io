//
// Created by Brayhan De Aza on 10/19/25.
//

#include "ParserLiterals.h"


std::any cromio::ParserLiterals::visitLiteral(Grammar::LiteralContext* ctx) {
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

std::any cromio::ParserLiterals::visitIntegerLiteral(Grammar::IntegerLiteralContext* ctx) {
    json node = Helpers::createNode(ctx->getText(), "IntegerLiteral", ctx->start, ctx->stop);
    node["value"] = Helpers::parseInteger(ctx->getText());

    return node;
}

std::any cromio::ParserLiterals::visitFloatLiteral(Grammar::FloatLiteralContext* ctx) {
    json node = Helpers::createNode(ctx->getText(), "FloatLiteral", ctx->start, ctx->stop);
    node["value"] = Helpers::parseFloat(ctx->getText());

    return node;
}

std::any cromio::ParserLiterals::visitStringLiteral(Grammar::StringLiteralContext* ctx) {
    json node = Helpers::createNode(ctx->getText(), "StringLiteral", ctx->start, ctx->stop);
    node["value"] = Helpers::parseString(ctx->getText());

    return node;
}

std::any cromio::ParserLiterals::visitBooleanLiteral(Grammar::BooleanLiteralContext* ctx) {
    json node = Helpers::createNode(ctx->getText() == "true" ? "1" : "0",
                                    "BooleanLiteral",
                                    ctx->start,
                                    ctx->stop);
    node["value"] = ctx->getText() == "true";

    return node;
}

std::any cromio::ParserLiterals::visitNoneLiteral(Grammar::NoneLiteralContext* ctx) {
    json node = Helpers::createNode("0", "NoneLiteral", ctx->start, ctx->stop);
    node["value"] = nullptr;

    return node;
}

std::any cromio::ParserLiterals::visitFormattedString(Grammar::FormattedStringContext* ctx) {
    json node = Helpers::createNode(ctx->getText(), "StringFormatted", ctx->start, ctx->stop);
    json params = json::array();

    for (const auto child : ctx->formattedStringContent()) {
        if (auto result = visit(child); result.has_value()) {
            auto expression = std::any_cast<json>(result);
            params.push_back(expression);
        }
    }

    node["params"] = params;

    return node;
}

std::any cromio::ParserLiterals::visitFormattedStringContent(Grammar::FormattedStringContentContext* ctx) {
    // -------- CASE 1: { expression }
    if (ctx->expression()) {
        const auto expression = visit(ctx->expression());
        return std::any_cast<json>(expression);
    }

    // -------- CASE 2: TEXT inside formatted string
    if (ctx->FORMATTED_STRING_TEXT()) {
        json node = Helpers::createNode(ctx->getText(), "StringFormattedText", ctx->start, ctx->stop);
        node["value"] = ctx->getText();
        return node;
    }

    return json::object();
}