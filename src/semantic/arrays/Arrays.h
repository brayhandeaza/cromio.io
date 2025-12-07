//
// Created by Brayhan De Aza on 12/2/25.
//

#ifndef CROMIO_ARRAYS_SEMANTIC_ANALYZE_H
#define CROMIO_ARRAYS_SEMANTIC_ANALYZE_H

#include "utils/utils.h"

namespace cromio::semantic {
    class Arrays {
       public:
        static json analyzeArrayDeclaration(json& node, const std::string& source);

       private:
        static bool checkDataType(const std::string& dataType, const std::string& returnType);
    };
} // namespace cromio::semantic

#endif // CROMIO_ARRAYS_SEMANTIC_ANALYZE_H
