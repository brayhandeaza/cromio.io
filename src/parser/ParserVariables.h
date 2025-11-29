//
// Created by Brayhan De Aza on 10/19/25.
//

#ifndef CROMIO_PARSER_VARIABLES_H
#define CROMIO_PARSER_VARIABLES_H

#include "GrammarVisitor.h"
#include "utils/utils.h"

namespace cromio::parser {
    class ParserVariables : public virtual GrammarVisitor {
       public:
        explicit ParserVariables(std::string& source) : source(source) {}
        std::any visitVariableDeclaration(Grammar::VariableDeclarationContext* ctx) override;
        std::any visitVariableDataType(Grammar::VariableDataTypeContext* ctx) override;

       private:
        void analyzeVariableDeclaration(const json& node) const;
        std::string& source;
    };
} // namespace cromio::parser

#endif // CROMIO_PARSER_VARIABLES_H