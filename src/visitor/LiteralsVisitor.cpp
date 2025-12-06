//
// Created by Brayhan De Aza on 10/19/25.
//

#include "LiteralsVisitor.h"
#include "utils/Error.h"

std::any cromio::visitor::LiteralsVisitor::visitLiteral(Grammar::LiteralContext* ctx) {
    if (ctx->stringLiteral()) {
        const std::any stringLiteral = visit(ctx->stringLiteral());
        return std::any_cast<json>(stringLiteral);
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

    json node = utils::Helpers::createNode("", "None", ctx->start, ctx->stop);
    return node;
}

std::any cromio::visitor::LiteralsVisitor::visitIntegerLiteral(Grammar::IntegerLiteralContext* ctx) {
    json node = utils::Helpers::createNode(ctx->getText(), "IntegerLiteral", ctx->start, ctx->stop);
    node["value"] = utils::Helpers::parseNumberString(ctx->getText());
    node["type"] = "int";
    node["stringValue"] = ctx->getText();
    node["numberValue"] = ctx->getText();

    return node;
}

std::any cromio::visitor::LiteralsVisitor::visitFloatLiteral(Grammar::FloatLiteralContext* ctx) {
    json node = utils::Helpers::createNode(ctx->getText(), "FloatLiteral", ctx->start, ctx->stop);
    node["value"] = utils::Helpers::parseFloat(ctx->getText());
    node["type"] = "float";
    node["stringValue"] = ctx->getText();
    node["numberValue"] = ctx->getText();

    return node;
}

std::any cromio::visitor::LiteralsVisitor::visitStringLiteral(Grammar::StringLiteralContext* ctx) {
    json node = utils::Helpers::createNode(ctx->getText(), "StringLiteral", ctx->start, ctx->stop);
    node["value"] = utils::Helpers::parseString(ctx->getText());
    node["type"] = "str";
    node["stringValue"] = ctx->getText();
    node["numberValue"] = ctx->getText();

    return node;
}

std::any cromio::visitor::LiteralsVisitor::visitBooleanLiteral(Grammar::BooleanLiteralContext* ctx) {
    json node = utils::Helpers::createNode(ctx->getText() == "true" ? "1" : "0", "BooleanLiteral", ctx->start, ctx->stop);
    node["value"] = ctx->getText();
    node["type"] = "bool";
    node["stringValue"] = ctx->getText();
    node["numberValue"] = ctx->getText() == "true" ? "1" : "0";

    return node;
}

std::any cromio::visitor::LiteralsVisitor::visitNoneLiteral(Grammar::NoneLiteralContext* ctx) {
    json node = utils::Helpers::createNode("0", "NoneLiteral", ctx->start, ctx->stop);
    node["value"] = ctx->getText();
    node["type"] = "none";
    node["stringValue"] = "none";
    node["numberValue"] = "0";

    return node;
}

std::any cromio::visitor::LiteralsVisitor::visitFormattedString(Grammar::FormattedStringContext* ctx) {
    json node = utils::Helpers::createNode(ctx->getText(), "StringFormatted", ctx->start, ctx->stop);
    json params = json::array();

    for (const auto child : ctx->formattedStringContent()) {
        if (auto result = visit(child); result.has_value()) {
            auto expression = std::any_cast<json>(result);
            params.push_back(expression);
        }
    }

    std::string value;
    for (const auto& param : params) {
        if (param["kind"] == "Expression") {
            value += std::to_string(static_cast<float>(param["value"]));
        } else {
            value += param["value"];
            node["stringValue"] += param["value"];
        }
    }

    node["value"] = value;
    node["stringValue"] = node["stringValue"];
    node["numberValue"] = value;
    node["type"] = "fstr";
    node["params"] = params;

    return node;
}

std::any cromio::visitor::LiteralsVisitor::visitFormattedStringContent(Grammar::FormattedStringContentContext* ctx) {
    // -------- CASE 1: { expression }
    if (ctx->expression()) {
        const auto expression = visit(ctx->expression());
        return std::any_cast<json>(expression);
    }

    // -------- CASE 2: TEXT inside formatted string
    if (ctx->FORMATTED_STRING_TEXT()) {
        json node = utils::Helpers::createNode(ctx->getText(), "StringFormattedText", ctx->start, ctx->stop);
        node["value"] = ctx->getText();
        node["stringValue"] = ctx->getText();
        return node;
    }

    return json::object();
}