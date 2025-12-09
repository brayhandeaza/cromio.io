//
// Created by Brayhan De Aza on 12/2/25.
//

#ifndef CROMIO_DICTIONARIES_SEMANTIC_ANALYZE_H
#define CROMIO_DICTIONARIES_SEMANTIC_ANALYZE_H

#include "semantic/BaseSemantic.h"
#include "utils/utils.h"

namespace cromio::semantic {
    class Dictionaries : public virtual BaseSemantic {
       public:
        static json analyzeDictionariesDeclaration(json& node, const std::string& source);
    };
} // namespace cromio::semantic

#endif // CROMIO_DICTIONARIES_SEMANTIC_ANALYZE_H
