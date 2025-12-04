//
// Created by Brayhan De Aza on 10/19/25.
//

#include "ParserVariables.h"
#include "semantic/semantic.h"

std::any cromio::parser::ParserVariables::visitVariableDeclarationWithoutAssignment(Grammar::VariableDeclarationWithoutAssignmentContext* ctx) {
    json node = utils::Helpers::createNode("", "VariableDeclaration", ctx->start, ctx->stop);

    const auto visitDataType = visit(ctx->variableDataType());
    const auto jDataType = std::any_cast<json>(visitDataType);

    node["DataType"] = jDataType;
    node["Identifier"] = ctx->IDENTIFIER()->getText();

    return analyzeVariableWithoutAssignment(node, ctx->start, ctx->stop);;
}

std::any cromio::parser::ParserVariables::visitVariableDeclaration(Grammar::VariableDeclarationContext* ctx) {
    json node = utils::Helpers::createNode("", "VariableDeclaration", ctx->start, ctx->stop);

    const auto visitDataType = visit(ctx->variableDataType());
    const auto jDataType = std::any_cast<json>(visitDataType);

    const auto variableAssignment = visit(ctx->variableAssignment());
    const auto jVariableAssignment = std::any_cast<json>(variableAssignment);

    node["DataType"] = jDataType;
    node["Identifier"] = jVariableAssignment["Identifier"];
    node["value"] = jVariableAssignment["value"];


    return analyzeVariableDeclaration(node, source);
}

std::any cromio::parser::ParserVariables::visitVariableAssignment(Grammar::VariableAssignmentContext* ctx) {
    json node = utils::Helpers::createNode("", "VariableAssignment", ctx->start, ctx->stop);

    const auto expression = visit(ctx->expression());
    const auto jExpression = std::any_cast<json>(expression);

    json identifier = utils::Helpers::createNode("", "VariableIdentifier", ctx->IDENTIFIER()->getSymbol(), ctx->IDENTIFIER()->getSymbol());
    identifier["value"] = ctx->IDENTIFIER()->getText();

    node["Identifier"] = identifier;
    node["value"] = jExpression;

    return node;
}

std::any cromio::parser::ParserVariables::visitVariableDataType(Grammar::VariableDataTypeContext* ctx) {
    json node = utils::Helpers::createNode("", "DataType", ctx->start, ctx->stop);
    node["value"] = ctx->getText();

    return node;
}
