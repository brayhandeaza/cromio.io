//
// Created by Brayhan De Aza on 12/2/25.
//

#include "Scope.h"

namespace cromio::semantic {
    bool Scope::declareVariable(const std::string& name, const json& info) {
        if (symbols.contains(name))
            return false;
        symbols[name] = info;
        return true;
    }

    bool Scope::existsInCurrent(const std::string& name) const {
        return symbols.contains(name);
    }

    void Scope::updateVariable(const std::string& name, const json& info) {
        if (!symbols.contains(name))
            return;

        symbols[name] = info;
    }

    std::optional<json> Scope::lookup(const std::string& name) {
        if (symbols.contains(name))
            return symbols.at(name);
        if (parent)
            return parent->lookup(name);
        return std::nullopt;
    }


} // namespace cromio::semantic
