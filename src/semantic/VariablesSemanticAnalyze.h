//
// Created by Brayhan De Aza on 12/2/25.
//

#ifndef CROMIO_VARIABLES_SEMANTIC_ANALYZE_H
#define CROMIO_VARIABLES_SEMANTIC_ANALYZE_H

#include "utils/Helpers.h"
#include "libs/json.hpp"

namespace cromio::semantic {
class VariablesSemanticAnalyze {
public:
    static json analyzeVariableDeclaration(const json& node, const std::string& source);

	private:
    static json analyzeUnsignedInteger(const json& node, const std::string& source);
};
}

#endif // CROMIO_VARIABLES_SEMANTIC_ANALYZE_H
