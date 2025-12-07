//
// Created by Brayhan De Aza on 12/2/25.
//

#ifndef CROMIO_SCOPE_H
#define CROMIO_SCOPE_H

#include <utils/utils.h>
#include <optional>
#include <string>
#include <unordered_map>
#include "semantic/BaseSemantic.h"

namespace cromio::semantic {
    class Scope : public virtual BaseSemantic {
       public:
        explicit Scope(Scope* parent = nullptr) : parent(parent) {}

        bool declareVariable(const std::string& name, const json& info);
        bool existsInCurrent(const std::string& name) const;

        std::optional<json> lookup(const std::string& name);

        // NEW
        Scope* createChild() {
            return new Scope(this);
        }

        Scope* getParent() const {
            return parent;
        }

       private:
        Scope* parent;
        std::unordered_map<std::string, json> symbols;
    };

} // namespace cromio::semantic

#endif // CROMIO_SCOPE_H
