//
// Created by Brayhan De Aza on 12/2/25.
//

#include "Arrays.h"

namespace cromio::semantic {
    json Arrays::analyzeArrayDeclaration(json& node, const std::string& source) {
        const std::string type = node["DataType"]["value"].get<std::string>();
        const std::string size = node["ArraySize"]["raw"];
        const auto items = node["value"]["items"];
        const int length = items.size();

        if (size != "auto" && length > std::stoi(size)) {
            utils::Error::throwRangeError("Expected array size of " + size + ", but received " + std::to_string(length) + " elements.", items[0], source);
        }

        return node;
    }
} // namespace cromio::semantic