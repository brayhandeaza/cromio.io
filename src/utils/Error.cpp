//
// Created by Brayhan De Aza on 11/29/25.
//

#include "Error.h"

void cromio::utils::Error::throwRangeError(const std::string& message, const json& node, const std::string& source) {
    throwError("RangeError", message, node, source);
}

void cromio::utils::Error::throwScopeError(const std::string& message, const json& node, const std::string& source) {
    throwError("ScopeError", message, node, source);
}

void cromio::utils::Error::throwTypeError(const std::string& identifier, const std::string& dataType, const json& node, const std::string& source) {
    std::string type = "";

    // SIGNED
    if (dataType == "int8")
        type = "signed 8-bit integer range";

    else if (dataType == "int16")
        type = "signed 16-bit integer range";

    else if (dataType == "int" || dataType == "int32")
        type = "signed 32-bit integer range";

    else if (dataType == "int64")
        type = "signed 64-bit integer range";

    // UNSIGNED
    else if (dataType == "uint8")
        type = "unsigned 8-bit integer range";

    else if (dataType == "uint16")
        type = "unsigned 16-bit integer range";

    else if (dataType == "uint" || dataType == "uint32")
        type = "unsigned 32-bit integer range";

    else if (dataType == "uint64")
        type = "unsigned 64-bit integer range";

    // FLOAT
    else if (dataType == "float" || dataType == "float32")
        type = "float 32-bit float range";

    else if (dataType == "float64")
        type = "float 64-bit float range";

    // BOOLEAN
    else if (dataType == "bool")
        type = "type boolean ";

    // STRING
    else if (dataType == "str")
        type = "type string";

    const std::string message = "<" + identifier + "> expects " + type;

    throwError("TypeError", message, node, source);
}

void cromio::utils::Error::throwError(const std::string& errorType, const std::string& message, const json& node, const std::string& source) {
    const int line = node["start"]["line"];
    const int col = node["start"]["column"];

    std::cerr << "\n\033[1;31m" + errorType + ": " << message << "\n";

    // Split source into lines
    std::istringstream stream(source);
    std::string lineText;
    int current = 1;

    while (std::getline(stream, lineText)) {
        if (current == line)
            break;
        current++;
    }

    // Print line number + code
    std::cout << "\033[37m" << line << " | " << lineText << "\n";

    // Print arrow below the code
    std::cout << "    " << std::string(node["end"]["column"].get<int>(), ' ') << "^";

    // If node spans more than 1 char, draw tildes
    // if (const int width = node["end"]["column"].get<int>() - 4; width > 0) {
    //     std::cout << std::string(width, '');
    // }

    std::cout << "\n";
    std::exit(1);
}