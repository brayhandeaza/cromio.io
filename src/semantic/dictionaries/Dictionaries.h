//
// Created by Brayhan De Aza on 12/2/25.
//

#ifndef CROMIO_DICTIONARIES_SEMANTIC_ANALYZE_H
#define CROMIO_DICTIONARIES_SEMANTIC_ANALYZE_H

#include "semantic/BaseSemantic.h"
#include "utils/utils.h"
#include <semantic/scopes/Scope.h>

namespace cromio::semantic {
    class Dictionaries : public virtual BaseSemantic {
       public:
        static json analyzeDictionariesDeclaration(json& node, const std::string& source);
        static json analyzeDictionaryItemsDataType(json& keyNode, json& valueNode, json& memberNode, Scope* scope, const std::string& source);
    };
} // namespace cromio::semantic

#endif // CROMIO_DICTIONARIES_SEMANTIC_ANALYZE_H
