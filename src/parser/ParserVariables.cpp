//
// Created by Brayhan De Aza on 10/19/25.
//

#include "ParserVariables.h"
#include "utils/Error.h"

void cromio::parser::ParserVariables::analyzeVariableDeclaration(const json& node) const {
    const std::string dataType = node["DataType"]["value"];
    const long long value = node["value"]["value"];

    // ---------------------------------------------
    // sign integer range check
    // ---------------------------------------------

    if (dataType == "int" || dataType == "int32")
        if (value < INT32_MIN || value > INT32_MAX)
            utils::Error::throwRangeError("<int32> type exceeds 32-bit range", node, source);

    if (dataType == "int8")
        if (value < INT8_MIN || value > INT8_MAX)
            utils::Error::throwRangeError("<int8> type exceeds 8-bit range", node, source);

    if (dataType == "int16")
        if (value < INT16_MIN || value > INT16_MAX)
            utils::Error::throwRangeError("<int16> type exceeds 16-bit range", node, source);

    if (dataType == "int64")
        if (value < INT64_MIN || value > INT64_MAX)
            utils::Error::throwRangeError("<int64> type exceeds 64-bit range", node, source);

    // ---------------------------------------------
    // sign integer range check
    // ---------------------------------------------
}

std::any cromio::parser::ParserVariables::visitVariableDeclaration(Grammar::VariableDeclarationContext* ctx) {
    json node = utils::Helpers::createNode("", "VariableDeclaration", ctx->start, ctx->stop);

    const auto visitDataType = visit(ctx->variableDataType());
    const auto expression = visit(ctx->expression());

    json identifier = utils::Helpers::createNode("", "VariableIdentifier", ctx->IDENTIFIER()->getSymbol(), ctx->IDENTIFIER()->getSymbol());
    identifier["value"] = ctx->IDENTIFIER()->getText();

    node["DataType"] = std::any_cast<json>(visitDataType);
    node["Identifier"] = identifier;
    node["value"] = std::any_cast<json>(expression);

    analyzeVariableDeclaration(node);

    return node;
}

std::any cromio::parser::ParserVariables::visitVariableDataType(Grammar::VariableDataTypeContext* ctx) {
    json node = utils::Helpers::createNode("", "DataType", ctx->start, ctx->stop);
    node["value"] = ctx->getText();

    return node;
}