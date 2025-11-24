//
// Created by Brayhan De Aza on 10/19/25.
//

#ifndef CROMIO_PARSER_H
#define CROMIO_PARSER_H

#include "ParserLiterals.h"
#include "GrammarVisitor.h"
#include "FormattedStringParser.h"


namespace cromio {
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
        if (ctx->literal()) {
            json expression = Helpers::createNode("", "Expression", ctx->start, ctx->stop);
            const std::any literal = visit(ctx->literal());

            return std::any_cast<json>(literal);
        }

        return json::object();
    }
};
} // namespace cromio
#endif //CROMIO_PARSER_H