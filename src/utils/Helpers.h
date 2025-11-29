//
// Created by Brayhan De Aza on 10/19/25.
//

#ifndef CROMIO_HELPERS_H
#define CROMIO_HELPERS_H

#include "libs/json.hpp"
#include "antlr4-runtime.h"

using json = nlohmann::ordered_json;

namespace cromio::utils
{
    class Helpers
    {
        static json getPosition(const antlr4::Token* token);

    public:
        static json createNode(const std::string& raw, const std::string& kind, const antlr4::Token* start,
                               const antlr4::Token* stop);
        static long long parseInteger(std::string raw);
        static std::string parseString(const std::string& rawInput);
        static double parseFloat(std::string raw);

        // ---------------------------------------------
        // Entry cromio.cpp helpers
        // ---------------------------------------------
        static json feedFileContentToANTLR(const std::string& content);
    };
}


#endif //CROMIO_HELPERS_H
