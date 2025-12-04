//
// Created by Brayhan De Aza on 11/27/25.
//

#include "BaseParser.h"

std::any cromio::parser::Parser::visitProgram(Grammar::ProgramContext* ctx) {
    json node = utils::Helpers::createNode("", "Program", ctx->start, ctx->stop);

    json body;
    for (const auto child : ctx->children) {
        if (const std::any statement = visit(child); statement.has_value()) {
            body.push_back(std::any_cast<json>(statement));
        }
    }

    node["Body"] = body;
    return node;
}


std::any cromio::parser::Parser::visitStatements(Grammar::StatementsContext* ctx) {
    if (ctx->expression()) {
        const std::any expression = visit(ctx->expression());
        return std::any_cast<json>(expression);
    }

    if (ctx->variables()) {
        const std::any variableStatement = visit(ctx->variables());
        return std::any_cast<json>(variableStatement);
    }

    return json::object();
}
