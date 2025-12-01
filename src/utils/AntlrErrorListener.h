//
// Created by Brayhan De Aza on 11/30/25.
//

#ifndef CROMIO_ANTLR_ERROR_LISTENER_H
#define CROMIO_ANTLR_ERROR_LISTENER_H

#include "antlr4-runtime.h"
#include <iostream>
#include <string>

namespace cromio::utils {
    class AntlrErrorListener : public antlr4::BaseErrorListener {
    private:
        std::vector<std::string> lines;

    public:
        explicit AntlrErrorListener(const std::string& source);
        void syntaxError(antlr4::Recognizer *recognizer, antlr4::Token *offendingSymbol, size_t line, size_t charPos, const std::string &msg, std::exception_ptr) override;
    };

}

#endif // CROMIO_ANTLR_ERROR_LISTENER_H
