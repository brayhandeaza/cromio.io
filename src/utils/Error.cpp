//
// Created by Brayhan De Aza on 11/29/25.
//

#include "Error.h"

void cromio::utils::Error::throwRangeError(const std::string& message, const json& node, const std::string& source) {
    throwError("RangeError", message, node, source);
}

void cromio::utils::Error::throwTypeError(const std::string& message, const json& node, const std::string& source) {
    throwError("TypeError", message, node, source);
}

void cromio::utils::Error::throwError(const std::string& errorType, const std::string& message, const json& node, const std::string& source) {
    const int line = node["start"]["line"];
    const int col = node["start"]["column"];

    std::cerr << "\n\033[1;31m" + errorType + ":\033[0m " << message << "\n";

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
    std::cout << line << " | " << lineText << "\n";

    // Print arrow below the code
    std::cout << "    " << std::string(col, ' ') << "^";

    // If node spans more than 1 char, draw tildes
    if (const int width = node["end"]["column"].get<int>() - col; width > 0) {
        std::cout << std::string(width, '~');
    }

    std::cout << "\n";
    std::exit(1);
}