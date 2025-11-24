//
// Created by Brayhan De Aza on 10/19/25.
//

#ifndef CROMIO_FORMATTED_STRING_PARSER_H
#define CROMIO_FORMATTED_STRING_PARSER_H

#include "GrammarVisitor.h"
#include "Helpers.h"

class FormattedStringParser : public virtual GrammarVisitor {
public:
    std::any visitFormattedString(Grammar::FormattedStringContext* ctx) override {
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

    std::any visitFormattedStringContent(Grammar::FormattedStringContentContext* ctx) override {
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
};

#endif // CROMIO_FORMATTED_STRING_PARSER_H