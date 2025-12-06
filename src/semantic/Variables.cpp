//
// Created by Brayhan De Aza on 12/2/25.
//

#include "Variables.h"
// #include "utils/utils.h"

const std::string cromio::semantic::Variables::INT64_MAX_STR = "9223372036854775807";
const std::string cromio::semantic::Variables::INT64_MIN_STR = "9223372036854775808"; // abs value
const std::string cromio::semantic::Variables::UINT64_MAX_STR = "18446744073709551615";
const std::string cromio::semantic::Variables::FLOAT32_MAX_STR = "3.4028235e38";
const std::string cromio::semantic::Variables::FLOAT32_MIN_STR = "-3.4028235e38";
const std::string cromio::semantic::Variables::FLOAT64_MAX_STR = "1.7976931348623157e308";
const std::string cromio::semantic::Variables::FLOAT64_MIN_STR = "-1.7976931348623157e308";

json cromio::semantic::Variables::analyzeVariableWithoutAssignment(json& node, const antlr4::Token* start, const antlr4::Token* stop) {
    const std::string type = node["DataType"]["value"];

    if (type.contains("int")) {
        json value = utils::Helpers::createNode("", "IntegerLiteral", start, stop);
        value["value"] = 0;
        value["raw"] = "0";
        value["type"] = "int";
        value["stringValue"] = "0";
        value["numberValue"] = "0";
        node["value"] = value;

        return node;
    }
    if (type.contains("float")) {
        json value = utils::Helpers::createNode("", "FloatLiteral", start, stop);
        value["value"] = 0.0;
        value["raw"] = "0.0";
        value["type"] = "float";
        value["stringValue"] = "0.0";
        value["numberValue"] = "0.0";

        node["value"] = value;
        return node;
    }
    if (type.contains("str")) {
        json value = utils::Helpers::createNode("", "StringLiteral", start, stop);
        value["value"] = "";
        value["raw"] = "";
        value["type"] = "str";
        value["stringValue"] = "";
        value["numberValue"] = "";
        node["value"] = value;
        return node;
    }
    if (type.contains("bool")) {
        json value = utils::Helpers::createNode("", "BooleanLiteral", start, stop);
        value["value"] = false;
        value["raw"] = "false";
        value["type"] = "bool";
        value["stringValue"] = "false";
        value["numberValue"] = "0";
        node["value"] = value;
        return node;
    }

    node["value"] = nullptr;
    return node;
}

void cromio::semantic::Variables::analyzeSignedInteger(const std::string& rValue, const std::string& dataType, const std::string& identifier, const std::string& source, const json& node) {
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

void cromio::semantic::Variables::analyzeUnsignedInteger(const std::string& rValue, const std::string& dataType, const std::string& identifier, const std::string& source, const json& node) {
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

void cromio::semantic::Variables::analyzeFloat(const std::string& rValue, const std::string& dataType, const std::string& source, const json& node) {
    if (dataType == "float" || dataType == "float32") {
        if (utils::Helpers::isGreaterSigned(rValue, FLOAT32_MAX_STR, FLOAT32_MIN_STR))
            utils::Error::throwRangeError("<float32> type exceeds 32-bit float range", node, source);
    }

    if (dataType == "float64") {
        if (utils::Helpers::isGreaterSigned(rValue, FLOAT64_MAX_STR, FLOAT64_MIN_STR))
            utils::Error::throwRangeError("<float64> type exceeds 64-bit float range", node, source);
    }
}

void cromio::semantic::Variables::analyze64BitInteger(const std::string& rValue, const std::string& dataType, const std::string& identifier, const std::string& source, const json& node) {
    const bool isNegative = !rValue.empty() && rValue[0] == '-';

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
}

json cromio::semantic::Variables::analyzeVariableDeclaration(json& node, const std::string& source) {
    if (node["value"].contains("error")) {
        const std::string error = node["value"]["error"];
        utils::Error::throwError("Error", error, node, source);
    }
    const std::string identifier = node["Identifier"]["value"];
    const std::string dataType = node["DataType"]["value"];
    const std::string rValue = node["value"]["numberValue"];
    const std::string stringValue = node["value"]["stringValue"];
    const std::string returnType = node["value"]["type"];

    if (!checkDataType(dataType, returnType))
        utils::Error::throwTypeError(identifier, dataType, node, source);
    analyze64BitInteger(rValue, dataType, identifier, source, node);

    if (dataType.contains("uint"))
        analyzeUnsignedInteger(rValue, dataType, identifier, source, node);

    else if (dataType.contains("int"))
        analyzeSignedInteger(rValue, dataType, identifier, source, node);

    else if (dataType.contains("float"))
        analyzeFloat(rValue, dataType, source, node);

    else if (dataType == "str" && returnType != "str")
        utils::Error::throwTypeError(identifier, dataType, node, source);

    else if (dataType == "bool")
        if (stringValue != "true" && stringValue != "false")
            utils::Error::throwTypeError(identifier, dataType, node, source);

    if (dataType.contains("uint") || dataType.contains("int")) {
        node["value"]["raw"] = std::to_string(std::stoll(rValue));
        node["value"]["value"] = std::stoll(rValue);
        node["value"]["type"] = "int";
        node["value"]["stringValue"] = std::to_string(std::stoll(rValue));
        node["value"]["numberValue"] = std::to_string(std::stoll(rValue));
    }

    if (dataType.contains("float")) {
        node["value"]["raw"] = std::to_string(std::stof(rValue));
        node["value"]["value"] = std::stof(rValue);
        node["value"]["type"] = "float";
        node["value"]["stringValue"] = std::to_string(std::stof(rValue));
        node["value"]["numberValue"] = std::to_string(std::stof(rValue));
    }
    return node;
}

bool cromio::semantic::Variables::checkDataType(const std::string& dataType, const std::string& returnType) {
    if (dataType == "int" || dataType == "int8" || dataType == "int16" || dataType == "int32" || dataType == "int64") {
        if (returnType == "int" || returnType == "float")
            return true;

        return false;
    }

    if (dataType == "uint" || dataType == "uint8" || dataType == "uint16" || dataType == "uint32" || dataType == "uint64") {
        if (returnType == "int" || returnType == "float")
            return true;

        return false;
    }

    if (dataType == "float" || dataType == "float32" || dataType == "float64") {
        if (returnType == "float" || returnType == "int")
            return true;

        return false;
    }

    if (dataType == "bool") {
        if (returnType == "bool")
            return true;

        return false;
    }

    if (dataType == "str") {
        if (returnType == "str")
            return true;

        return false;
    }

    return false;
}