//
// Created by Brayhan De Aza on 12/2/25.
//

#ifndef CROMIO_VARIABLES_SEMANTIC_ANALYZE_H
#define CROMIO_VARIABLES_SEMANTIC_ANALYZE_H

#include "utils/utils.h"

namespace cromio::semantic {
    class VariablesSemanticAnalyze {
       public:
        static json analyzeVariableDeclaration(json& node, const std::string& source);
        static json analyzeVariableWithoutAssignment(json& node, const antlr4::Token* start, const antlr4::Token* stop);

       private:
        static const std::string INT64_MAX_STR;
        static const std::string INT64_MIN_STR;
        static const std::string UINT64_MAX_STR;
        static const std::string FLOAT32_MAX_STR;
        static const std::string FLOAT32_MIN_STR;
        static const std::string FLOAT64_MAX_STR;
        static const std::string FLOAT64_MIN_STR;

        static void analyzeSignedInteger(const std::string& rValue, const std::string& dataType, const std::string& identifier, const std::string& source, const json& node);
        static void analyzeUnsignedInteger(const std::string& rValue, const std::string& dataType, const std::string& identifier, const std::string& source, const json& node);
        static void analyzeFloat(const std::string& rValue, const std::string& dataType, const std::string& source, const json& node);
        static void analyze64BitInteger(const std::string& rValue, const std::string& dataType, const std::string& identifier, const std::string& source, const json& node);

        static bool checkDataType(const std::string& dataType, const std::string& returnType);
    };
} // namespace cromio::semantic

#endif // CROMIO_VARIABLES_SEMANTIC_ANALYZE_H
