//
// Created by Brayhan De Aza on 10/19/25.
//

#ifndef CROMIO_BASE_PARSER_H
#define CROMIO_BASE_PARSER_H

#include "ExpressionStatements.h"
#include "GrammarVisitor.h"
#include "ParserLiterals.h"
#include "ParserVariables.h"

namespace cromio::parser {
    class Parser final : public ParserLiterals, public ParserVariables, public ExpressionStatements {
       public:
        explicit Parser(std::string& source) : ParserLiterals(source), ParserVariables(source), ExpressionStatements(source), source(source) {}
        std::any visitProgram(Grammar::ProgramContext* ctx) override;
        std::any visitStatements(Grammar::StatementsContext* ctx) override;

       private:
        std::string& source;
    };
} // namespace cromio::parser

#endif // CROMIO_BASE_PARSER_H
