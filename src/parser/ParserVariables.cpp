//
// Created by Brayhan De Aza on 10/19/25.
//

#include "ParserVariables.h"
#include "utils/Error.h"

json cromio::parser::ParserVariables::analyzeVariableDeclaration(const json& node) const {
    if (node["value"].contains("error")) {
        const std::string error = node["value"]["error"];
        utils::Error::throwError("Error", error, node, source);
    }
    const std::string identifier = node["Identifier"]["value"];
    const std::string dataType = node["DataType"]["value"];
    const std::string rValue = node["value"]["numberValue"];
    const std::string returnType = node["value"]["type"];

    const bool isNegative = !rValue.empty() && rValue[0] == '-';

    if (!utils::Helpers::checkDataType(dataType, returnType))
        utils::Error::throwTypeError(identifier, dataType, node, source);

    // Limits as strings
    const std::string INT64_MAX_STR = "9223372036854775807";
    const std::string INT64_MIN_STR = "9223372036854775808"; // abs value
    const std::string UINT64_MAX_STR = "18446744073709551615";

    // ---------------------------------------------
    // SIGNED integers
    // ---------------------------------------------
    if (dataType == "int64") {
        const bool isValidNumber = utils::Helpers::isValidNumber(rValue);
        if (!isValidNumber)
            utils::Error::throwTypeError(identifier, dataType, node, source);

        if (utils::Helpers::isGreaterSigned(rValue, INT64_MAX_STR, INT64_MIN_STR) || !isValidNumber)
            utils::Error::throwRangeError("<int64> type exceeds 64-bit range", node, source);
    }

    // ---------------------------------------------
    // UNSIGNED integers
    // ---------------------------------------------
    if (dataType == "uint64") {
        if (const bool isValidNumber = utils::Helpers::isValidNumber(rValue); !isValidNumber)
            utils::Error::throwTypeError(identifier, dataType, node, source);

        if (isNegative)
            utils::Error::throwRangeError("<uint64> cannot be negative", node, source);

        if (utils::Helpers::isGreaterUnsigned(rValue, UINT64_MAX_STR))
            utils::Error::throwRangeError("<uint64> type exceeds unsigned 64-bit range", node, source);
    }

    // ---------------------------------------------
    // Unsigned integers
    // ---------------------------------------------
    if (dataType.contains("uint")) {
        const bool isValidNumber = utils::Helpers::isValidNumber(rValue);
        const auto value = utils::Helpers::parseFloat(rValue);

        // validate data type
        if (dataType == "uint8" && !isValidNumber)
            utils::Error::throwTypeError(identifier, dataType, node, source);

        if (dataType == "uint16" && !isValidNumber)
            utils::Error::throwTypeError(identifier, dataType, node, source);

        if ((dataType == "uint32" || dataType == "uint") && !isValidNumber)
            utils::Error::throwTypeError(identifier, dataType, node, source);

        // validate variable value exceeds range
        if (dataType == "uint8" && (value < 0 || value > UINT8_MAX))
            utils::Error::throwRangeError("Value exceeds 8-bit unsigned integer range", node, source);

        if (dataType == "uint16" && (value < 0 || value > UINT16_MAX))
            utils::Error::throwRangeError("Value exceeds 16-bit unsigned integer range", node, source);

        if ((dataType == "uint32" || dataType == "uint") && (value < 0 || value > UINT32_MAX))
            utils::Error::throwRangeError("Value exceeds 32-bit unsigned integer range", node, source);
    }
    // ---------------------------------------------
    // Signed integers
    // ---------------------------------------------
    else if (dataType.contains("int")) {
        const auto value = utils::Helpers::parseInteger(rValue);
        const bool isValidNumber = utils::Helpers::isValidNumber(std::to_string(value));

        // validate data type
        if (dataType == "int8" && !isValidNumber)
            utils::Error::throwTypeError(identifier, dataType, node, source);

        if (dataType == "int16" && !isValidNumber)
            utils::Error::throwTypeError(identifier, dataType, node, source);

        if ((dataType == "int32" || dataType == "int") && !isValidNumber)
            utils::Error::throwTypeError(identifier, dataType, node, source);

        // validate variable value exceeds range
        if (dataType == "int8" && (value < INT8_MIN || value > INT8_MAX))
            utils::Error::throwRangeError("Value exceeds 8-bit signed integer range", node, source);

        if (dataType == "int16" && (value < INT16_MIN || value > INT16_MAX))
            utils::Error::throwRangeError("Value exceeds 16-bit signed integer range", node, source);

        if ((dataType == "int32" || dataType == "int") && (value < INT32_MIN || value > INT32_MAX))
            utils::Error::throwRangeError("Value exceeds 32-bit signed integer range", node, source);
    }

    // ---------------------------------------------
    // FLOATS
    // ---------------------------------------------
    else if (dataType.contains("float")) {
        const std::string FLOAT32_MAX_STR = "3.4028235e38";
        const std::string FLOAT32_MIN_STR = "-3.4028235e38";
        const std::string FLOAT64_MAX_STR = "1.7976931348623157e308";
        const std::string FLOAT64_MIN_STR = "-1.7976931348623157e308";

        if (dataType == "float" || dataType == "float32") {
            if (utils::Helpers::isGreaterSigned(rValue, FLOAT32_MAX_STR, FLOAT32_MIN_STR))
                utils::Error::throwRangeError("<float32> type exceeds 32-bit float range", node, source);
        }

        if (dataType == "float64") {
            if (utils::Helpers::isGreaterSigned(rValue, FLOAT64_MAX_STR, FLOAT64_MIN_STR))
                utils::Error::throwRangeError("<float64> type exceeds 64-bit float range", node, source);
        }
    }

    // ---------------------------------------------
    // BOOLEAN
    // ---------------------------------------------
    else if (dataType == "bool") {
        if (rValue != "true" && rValue != "false")
            utils::Error::throwTypeError(identifier, dataType, node, source);
    }

    // ---------------------------------------------
    // STRING
    // ---------------------------------------------
    else if (dataType == "str" && returnType != "str") {
        utils::Error::throwTypeError(identifier, dataType, node, source);
    }

    return node;
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

    return analyzeVariableDeclaration(node);
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

