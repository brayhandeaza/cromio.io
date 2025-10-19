//
// Created by Brayhan De Aza on 10/19/25.
//

#ifndef CROMIO_HELPERS_H
#define CROMIO_HELPERS_H

#include "json.hpp"
#include "antlr4-runtime.h"
#include "Grammar.h"
#include "GrammarVisitor.h"

using json = nlohmann::ordered_json;


class Helpers {
    static json getPosition(const antlr4::Token *token);

public:
    static json createNode(const std::string &raw, const std::string &kind, const antlr4::Token *start, const antlr4::Token *stop);
    static long long parseInteger(std::string raw);
};

#endif //CROMIO_HELPERS_H
