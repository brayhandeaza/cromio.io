//
// Created by Brayhan De Aza on 10/19/25.
//


#include "ParserVariables.h"


std::any cromio::parser::ParserVariables::visitVariableDeclaration(Grammar::VariableDeclarationContext* ctx) {
    json node = utils::Helpers::createNode("", "VariableDeclaration", ctx->start, ctx->stop);

    const auto visitDataType = visit(ctx->variableDataType());
    const auto expression = visit(ctx->expression());

    json identifier = utils::Helpers::createNode("", "VariableIdentifier", ctx->IDENTIFIER()->getSymbol(),ctx->IDENTIFIER()->getSymbol());
    identifier["value"] = ctx->IDENTIFIER()->getText();

    node["DataType"] = std::any_cast<json>(visitDataType);
    node["Identifier"] = identifier;
    node["value"] = std::any_cast<json>(expression);

    return node;
}


std::any cromio::parser::ParserVariables::visitVariableDataType(Grammar::VariableDataTypeContext* ctx) {
    json node = utils::Helpers::createNode("", "DataType", ctx->start, ctx->stop);
    node["value"] = ctx->getText();

    return node;
}