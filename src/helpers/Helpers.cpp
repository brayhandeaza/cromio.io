//
// Created by Brayhan De Aza on 10/19/25.
//

#include "helpers/Helpers.h"

double Helpers::parseFloat(std::string raw) {
    bool isNegative = false;

    // Detect negative sign
    if(!raw.empty() && raw[0] == '-') {
        isNegative = true;
        raw = raw.substr(1);
    }

    std::erase(raw, '_');

    double value = 0.0;
    value = std::stod(raw);

    if(isNegative) value = -value;
    return value;
}


std::string Helpers::parseString(const std::string &rawInput) {
    std::string raw = rawInput;

    // Helper lambdas for starts_with and ends_with (C++11 compatible)
    auto starts_with = [](const std::string &str, const std::string &prefix) {
        return str.size() >= prefix.size() && str.compare(0, prefix.size(), prefix) == 0;
    };
    auto ends_with = [](const std::string &str, const std::string &suffix) {
        return str.size() >= suffix.size() && str.compare(str.size() - suffix.size(), suffix.size(), suffix) == 0;
    };

    // 1️⃣ Detect triple-quoted string ("""...""" or '''...''')
    bool triple = false;
    if (raw.size() >= 6) {
        if ((starts_with(raw, R"(""")") && ends_with(raw, R"(""")")) || (starts_with(raw, "'''") && ends_with(raw, "'''"))) {
            triple = true;
            raw = raw.substr(3, raw.size() - 6);
        }
    }

    // 2️⃣ If not triple, strip single outer quotes
    if (!triple && raw.size() >= 2 && ((raw.front() == '"' && raw.back() == '"') || (raw.front() == '\'' && raw.back() == '\''))) {
        raw = raw.substr(1, raw.size() - 2);
    }

    // 3️⃣ Process escape sequences (skip for triple-quoted raw style)
    std::string result;
    result.reserve(raw.size());

    for (size_t i = 0; i < raw.size(); ++i) {
        if (!triple && raw[i] == '\\' && i + 1 < raw.size()) {
            char next = raw[++i];
            switch (next) {
                case 'n': result += '\n';
                    break;
                case 'r': result += '\r';
                    break;
                case 't': result += '\t';
                    break;
                case '\\': result += '\\';
                    break;
                case '"': result += '"';
                    break;
                case '\'': result += '\'';
                    break;
                case 'b': result += '\b';
                    break;
                case 'f': result += '\f';
                    break;
                case 'u':
                    result += '?'; // placeholder for \uXXXX
                    i += 4;
                    break;
                default:
                    result += next;
                    break;
            }
        } else {
            result += raw[i];
        }
    }

    // 4️⃣ Normalize line endings for triple-quoted strings (optional)
    if (triple) {
        std::string normalized;
        normalized.reserve(result.size());
        for (size_t i = 0; i < result.size(); ++i) {
            if (result[i] == '\r' && i + 1 < result.size() && result[i + 1] == '\n') continue;
            normalized += result[i];
        }
        return normalized;
    }

    return result;
}

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

    std::erase(raw, '_');

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

    if (raw.empty() != true) node["raw"] = raw;

    return node;
}
