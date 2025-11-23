//
// Created by Brayhan De Aza on 10/19/25.
//

#ifndef CROMIO_FORMATTED_STRING_PARSER_H
#define CROMIO_FORMATTED_STRING_PARSER_H

#include "GrammarVisitor.h"
#include "Helpers.h"

class FormattedStringParser : public virtual GrammarVisitor {
public:
    // f"hello {x+1} world {32}"
    std::any visitFormattedString(Grammar::FormattedStringContext* ctx) override {
        json node = Helpers::createNode(
            ctx->getText(),
            "StringFormatted",
            ctx->start,
            ctx->stop
            );

        json params = json::array();

        for (auto child : ctx->children) {
            if (auto result = visit(child); result.has_value()) {
                params.push_back(std::any_cast<json>(result));
            }
        }

        node["params"] = params;
        return node;
    }


    // TEXT or { expression }
    std::any visitFormattedStringContent(Grammar::FormattedStringContentContext* ctx) override {
        // -------- CASE 1: { expression }
        if (ctx->formattedStringExpression()) {
            const auto expression = visit(ctx->formattedStringExpression());
            const auto node = std::any_cast<json>(expression);

            std::cout << "exprNode: " << node.dump(2) << std::endl;
            return visit(ctx->formattedStringExpression());
        }

        // -------- CASE 2: TEXT inside formatted string
        if (ctx->FORMATTED_STRING_TEXT()) {
            json node = Helpers::createNode(
                ctx->getText(),
                "StringFormattedText",
                ctx->start,
                ctx->stop
                );
            node["value"] = ctx->getText();
            return node;
        }

        // Fallback
        json unknown = Helpers::createNode(
            ctx->getText(),
            "UnknownFormattedContent",
            ctx->start,
            ctx->stop
            );
        return unknown;
    }


    // Handles ONLY: { expression }
    std::any visitFormattedStringExpression(Grammar::FormattedStringExpressionContext* ctx) override {
        // -------- CASE: {}
        if (ctx->expression() == nullptr) {
            json node = Helpers::createNode(
                ctx->getText(),
                "EmptyFormattedParam",
                ctx->start,
                ctx->stop
                );
            node["value"] = nullptr;
            return node;
        }


        // -------- CASE: { expression }
        const auto exprAny = visit(ctx->expression());
        const auto exprNode = std::any_cast<json>(exprAny);

        std::cout << "expression: " << exprNode  << std::endl;

        // Wrap expression in a formatted param
        json paramNode = Helpers::createNode(
            ctx->getText(),
            "FormattedParam",
            ctx->start,
            ctx->stop
            );


        // NOW THIS IS AN EXPRESSION (BinaryExpression, Literal, Identifier, etc.)
        paramNode["value"] = exprNode;

        return paramNode;
    }
};

#endif // CROMIO_FORMATTED_STRING_PARSER_H