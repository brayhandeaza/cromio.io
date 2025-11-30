//
// Created by Brayhan De Aza on 11/29/25.
//

#ifndef CROMIO_ERROR_H
#define CROMIO_ERROR_H

#include <string>
#include "utils/utils.h"

namespace cromio::utils {
    class Error {
       public:
        static void throwRangeError(const std::string& message, const json& node, const std::string& source);
        static void throwTypeError(const std::string& message, const json& node, const std::string& source);
        static void throwError(const std::string& errorType, const std::string& message, const json& node, const std::string& source);
    };
} // namespace cromio::utils

#endif // CROMIO_ERROR_H
