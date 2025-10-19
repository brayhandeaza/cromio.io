//
// Created by Brayhan De Aza on 10/19/25.
//

#include "Helpers.h"

long long Helpers::parseInteger(std::string raw) {
    bool isNegative = false;

    // Detect negative sign
    if (!raw.empty() && raw[0] == '-') {
        isNegative = true;
        raw = raw.substr(1); // remove the '-'
    }

    int base = 10;

    // Detect prefix
    if (raw.rfind("0x", 0) == 0 || raw.rfind("0X", 0) == 0) {
        base = 16;
        raw = raw.substr(2);
    } else if (raw.rfind("0b", 0) == 0 || raw.rfind("0B", 0) == 0) {
        base = 2;
        raw = raw.substr(2);
    } else if (raw.rfind("0o", 0) == 0 || raw.rfind("0O", 0) == 0) {
        base = 8;
        raw = raw.substr(2);
    } else if (raw.size() > 1 && raw[0] == '0' && std::isdigit(raw[1])) {
        base = 8; // old-style octal like 0755
    }

    // Remove underscores
    raw.erase(std::remove(raw.begin(), raw.end(), '_'), raw.end());

    long long value = std::stoll(raw, nullptr, base);
    if (isNegative) value = -value;

    return value;
}


json Helpers::getPosition(const antlr4::Token *token) {
    json pos;
    pos["line"] = token->getLine();
    pos["column"] = token->getCharPositionInLine();
    return pos;
}

json Helpers::createNode(const std::string &raw, const std::string &kind, const antlr4::Token *start, const antlr4::Token *stop) {
    json node;
    node["kind"] = kind;
    node["start"] = getPosition(start);
    node["end"] = getPosition(stop ? stop : start);

    if (raw.empty() != true)
        node["raw"] = raw;

    return node;
}


