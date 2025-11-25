//
// Created by Brayhan De Aza on 10/19/25.
//

#ifndef CROMIO_PARSER_H
#define CROMIO_PARSER_H

#include "ParserLiterals.h"
#include "GrammarVisitor.h"
#include "FormattedStringParser.h"
#include "helpers/Helpers.h"

class Parser final : public ParserLiterals, public FormattedStringParser {
public:
    std::any visitProgram(Grammar::ProgramContext* ctx) override {
        json node = Helpers::createNode("", "Program", ctx->start, ctx->stop);

        json body;
        for (const auto child : ctx->children) {
            const std::any statement = visit(child);

            if (statement.has_value()) {
                body.push_back(std::any_cast<json>(statement));
            }
        }

        node["Body"] = body;
        return node;
    }

    std::any visitStatement(Grammar::StatementContext* ctx) override {
        json node = Helpers::createNode("", "Statement", ctx->start, ctx->stop);
        if (ctx->expression()) {
            const std::any expression = visit(ctx->expression());

            node["Expression"] = std::any_cast<json>(expression);
            return node;
        }

        return json::object();
    }

    std::any visitExpression(Grammar::ExpressionContext* ctx) override {
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
        if (ctx->expression().size() == 1 && !op.empty()) {
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



            json node = Helpers::createNode(ctx->getText(), "Expression", ctx->start, ctx->stop);
            node["left"] = leftJson;
            node["operator"] = op;
            node["right"] = rightJson;
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
};

#endif //CROMIO_PARSER_H