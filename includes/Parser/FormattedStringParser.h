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

        json params;
        for (const auto child : ctx->children) {
            if (const std::any content = visit(child); content.has_value()) {
                params.push_back(std::any_cast<json>(content));
            }
        }

        node["params"] = params;

        return node;
    }

    std::any visitFormattedStringContent(Grammar::FormattedStringContentContext* ctx) override {
        if (ctx->formattedStringExpression()) {
            const std::any expression = visit(ctx->formattedStringExpression());
            return std::any_cast<json>(expression);
        }
        if (ctx->FORMATTED_STRING_TEXT()) {
            json node = Helpers::createNode(ctx->getText(), "StringFormattedText", ctx->start, ctx->stop);
            node["value"] = ctx->getText();
            return node;
        }

        json node = Helpers::createNode(ctx->getText(), "UnownText", ctx->start, ctx->stop);
        return node;
    }

    std::any visitFormattedStringExpression(Grammar::FormattedStringExpressionContext* ctx) override {
        const std::any value = visit(ctx->expression());
        return std::any_cast<json>(value);
    }
};

#endif //CROMIO_FORMATTED_STRING_PARSER_H