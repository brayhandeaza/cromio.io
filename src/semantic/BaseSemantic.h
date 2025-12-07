//
// Created by Brayhan De Aza on 11/27/25.
//

#ifndef CROMIO_BASE_SEMANTIC_H
#define CROMIO_BASE_SEMANTIC_H

#include <string>
#include "utils/utils.h"

namespace cromio::semantic {
    class BaseSemantic {
       public:
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
    };
} // namespace cromio::semantic

#endif // CROMIO_BASE_SEMANTIC_H