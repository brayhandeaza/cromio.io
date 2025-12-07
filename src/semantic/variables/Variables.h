//
// Created by Brayhan De Aza on 12/2/25.
//

#ifndef CROMIO_VARIABLES_SEMANTIC_ANALYZE_H
#define CROMIO_VARIABLES_SEMANTIC_ANALYZE_H

#include "../BaseSemantic.h"
#include "utils/utils.h"

namespace cromio::semantic {
    class Variables : public virtual BaseSemantic {
       public:

        static json analyzeVariableDeclaration(json& node, const std::string& source);
        static json analyzeVariableWithoutAssignment(json& node, const antlr4::Token* start, const antlr4::Token* stop);

        static json cleanASTExpression(const json& node);
        static bool checkDataType(const std::string& dataType, const std::string& returnType);
    };
} // namespace cromio::semantic

#endif // CROMIO_VARIABLES_SEMANTIC_ANALYZE_H
