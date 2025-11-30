//
// Created by Brayhan De Aza on 10/19/25.
//

#include "ParserVariables.h"
#include "utils/Error.h"

void cromio::parser::ParserVariables::analyzeVariableDeclaration(const json& node) const {
    const std::string identifier = node["Identifier"]["value"];
    const std::string dataType = node["DataType"]["value"];
    const std::string rValue = node["value"]["value"];
    const bool isNegative = !rValue.empty() && rValue[0] == '-';
    const bool isValidNumber = utils::Helpers::isValidNumber(rValue);

    // Limits as strings
    const std::string INT64_MAX_STR = "9223372036854775807";
    const std::string INT64_MIN_STR = "9223372036854775808"; // abs value
    const std::string UINT64_MAX_STR = "18446744073709551615";

    // ---------------------------------------------
    // SIGNED integers
    // ---------------------------------------------
    if (dataType == "int64") {
        if (!isValidNumber)
            utils::Error::throwTypeError("\033[1;31mvariable <" + identifier + "> expect" + "expect a 64-bit range signed integer", node, source);

        if (utils::Helpers::isGreaterSigned(rValue, INT64_MAX_STR, INT64_MIN_STR) || !isValidNumber)
            utils::Error::throwRangeError("<int64> type exceeds 64-bit range", node, source);
    }

    // ---------------------------------------------
    // UNSIGNED integers
    // ---------------------------------------------
    if (dataType == "uint64") {
        if (!isValidNumber)
            utils::Error::throwTypeError("\033[1;31mvariable <" + identifier + ">" + "expect a 64-bit range unsigned integer", node, source);

        if (isNegative)
            utils::Error::throwRangeError("<uint64> cannot be negative", node, source);

        if (utils::Helpers::isGreaterUnsigned(rValue, UINT64_MAX_STR))
            utils::Error::throwRangeError("<uint64> type exceeds unsigned 64-bit range", node, source);
    }

    const double value = std::stod(rValue);

    // ---------------------------------------------
    // Signed integers
    // ---------------------------------------------
    // validate data type
    if (dataType == "int8" && !isValidNumber)
        utils::Error::throwTypeError("\033[1;31mvariable <" + identifier + "> expect" + "expect a 8-bit range signed integer", node, source);

    if (dataType == "int16" && !isValidNumber)
        utils::Error::throwTypeError("\033[1;31mvariable <" + identifier + "> expect" + "expect a 16-bit range signed integer", node, source);

    if ((dataType == "int32" || dataType == "int") && !isValidNumber)
        utils::Error::throwTypeError("\033[1;31mvariable <" + identifier + "> expect" + "expect a 32-bit range signed integer", node, source);

    // validate variable value exceeds range
    if (dataType == "int8" && (value < INT8_MIN || value > INT8_MAX))
        utils::Error::throwRangeError("<int8> exceeds range", node, source);

    if (dataType == "int16" && (value < INT16_MIN || value > INT16_MAX))
        utils::Error::throwRangeError("<int16> exceeds range", node, source);

    if ((dataType == "int32" || dataType == "int") && (value < INT32_MIN || value > INT32_MAX))
        utils::Error::throwRangeError("<int32> exceeds range", node, source);

    // ---------------------------------------------
    // Unsigned integers
    // ---------------------------------------------
    // validate data type
    if (dataType == "uint8" && !isValidNumber)
        utils::Error::throwTypeError("\033[1;31mvariable <" + identifier + "> expect" + "expect a 8-bit range unsigned integer", node, source);

    if (dataType == "uint16" && !isValidNumber)
        utils::Error::throwTypeError("\033[1;31mvariable <" + identifier + "> expect" + "expect a 16-bit range unsigned integer", node, source);

    if ((dataType == "uint32" || dataType == "uint") && !isValidNumber)
        utils::Error::throwTypeError("\033[1;31mvariable <" + identifier + "> expect" + "expect a 32-bit range unsigned integer", node, source);

    // validate variable value exceeds range
    if (dataType == "uint8" && (value < 0 || value > UINT8_MAX))
        utils::Error::throwRangeError("<uint8> exceeds range", node, source);
    if (dataType == "uint16" && (value < 0 || value > UINT16_MAX))
        utils::Error::throwRangeError("<uint16> exceeds range", node, source);
    if ((dataType == "uint32" || dataType == "uint") && (value < 0 || value > UINT32_MAX))
        utils::Error::throwRangeError("<uint32> exceeds range", node, source);

    // ---------------------------------------------
    // FLOATS
    // ---------------------------------------------
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