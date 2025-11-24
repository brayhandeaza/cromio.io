//
// Created by Brayhan De Aza on 11/23/25.
//

#include "Parser.h"
#include "FormattedStringParser.h"


std::any FormattedStringParser::visitFormattedString(Grammar::FormattedStringContext* ctx) {
    json node = Helpers::createNode(ctx->getText(), "StringFormatted", ctx->start, ctx->stop);
    json params = json::array();

    for (const auto child : ctx->formattedStringContent()) {
        if (auto result = visit(child); result.has_value()) {
            auto expression = std::any_cast<json>(result);
            // std::cout << "params: " << expression.dump(2) << std::endl;

            params.push_back(expression);
        }
    }

    node["params"] = params;

    return node;
}

std::any FormattedStringParser::visitFormattedStringContent(Grammar::FormattedStringContentContext* ctx) {
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