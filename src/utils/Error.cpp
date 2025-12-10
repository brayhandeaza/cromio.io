//
// Created by Brayhan De Aza on 11/29/25.
//

#include "Error.h"
#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>

namespace cromio::utils {

    // ------------------- Helper privado -------------------

    void Error::printContext(const json& node, const std::string& source, const std::string& hint , int context) {
        int startLine = node["start"]["line"];
        int startCol = node["start"]["column"];
        int endLine = node["end"]["line"];
        int endCol = node["end"]["column"];

        std::istringstream stream(source);
        std::string lineText;
        std::vector<std::string> lines;
        while (std::getline(stream, lineText))
            lines.push_back(lineText);

        const int totalLines = static_cast<int>(lines.size());

        int from = std::max(1, startLine - context);
        int to = std::min(totalLines, endLine + context);

        for (int i = from; i <= to; i++) {
            std::string prefix = i >= startLine && i <= endLine ? "\033[1;37m>" : " ";
            std::cout << prefix << " \033[36m" << i << " | \033[0m" << lines[i - 1] << "\n";

            if (i == startLine) {
                std::cout << "    ";
                int underlineStart = startCol;
                int underlineSize = startLine == endLine ? std::max(1, endCol - startCol + 1) : static_cast<int>(lines[i - 1].size()) - startCol;

                std::cout << std::string(underlineStart, ' ');
                std::cout << "\033[1;31m" << std::string(underlineSize, '^') << "\033[0m";

                if (!hint.empty()) {
                    std::cout << "    " << std::string(underlineStart, ' ') << "\033[33m\n";
                }
            }

            if (i > startLine && i <= endLine) {
                std::cout << "    " << std::string(0, ' ');
                std::cout << "\033[1;31m" << std::string(lines[i - 1].size(), '^') << "\033[0m";
            }
        }

        std::cout << "\n";
    }

    // ------------------- Errores -------------------
    void Error::throwError(const std::string& errorType, const std::string& message, const json& node, const std::string& source) {
        std::cerr << "\n\033[1;31m" << errorType << ": " << message << "\033[0m\n";
        printContext(node, source, message, 2);
        std::exit(1);
    }

    void Error::throwRangeError(const std::string& message, const json& node, const std::string& source) {
        throwError("RangeError", message, node, source);
    }

    void Error::throwScopeError(const std::string& message, const json& node, const std::string& source) {
        throwError("ScopeError", message, node, source);
    }

    void Error::throwTypeError(const std::string& identifier, const std::string& dataType, const json& node, const std::string& source) {
        std::string typeMsg = "";



        // SIGNED
        if (dataType == "int8")
            typeMsg = "signed 8-bit integer range";
        else if (dataType == "int16")
            typeMsg = "signed 16-bit integer range";
        else if (dataType == "int" || dataType == "int32")
            typeMsg = "signed 32-bit integer range";
        else if (dataType == "int64")
            typeMsg = "signed 64-bit integer range";

        // UNSIGNED
        else if (dataType == "uint8")
            typeMsg = "unsigned 8-bit integer range";
        else if (dataType == "uint16")
            typeMsg = "unsigned 16-bit integer range";
        else if (dataType == "uint" || dataType == "uint32")
            typeMsg = "unsigned 32-bit integer range";
        else if (dataType == "uint64")
            typeMsg = "unsigned 64-bit integer range";

        // FLOAT
        else if (dataType == "float" || dataType == "float32")
            typeMsg = "32-bit 'float'";
        else if (dataType == "'float64'")
            typeMsg = "64-bit 'float'";

        // BOOLEAN
        else if (dataType == "bool")
            typeMsg = "'boolean' type";

        // STRING
        else if (dataType == "str")
            typeMsg = "'string' type";

        // ARRAY
        else if (dataType == "int[]")
            typeMsg = "'int[]' array type";
        else if (dataType == "uint[]")
            typeMsg = "unsigned 'int[]' array type";
        else if (dataType == "float[]")
            typeMsg = "'float[]' array type";
        else if (dataType == "bool[]")
            typeMsg = "'bool[]' array type";
        else if (dataType == "str[]")
            typeMsg = "'str[]' array type";

        const std::string message = "'" + identifier + "' expects " + typeMsg;
        throwError("TypeError", message, node, source);
    }

} // namespace cromio::utils
