//
// Created by Brayhan De Aza on 10/19/25.
//

#ifndef CROMIO_BASE_PARSER_H
#define CROMIO_BASE_PARSER_H

#include "GrammarVisitor.h"
#include "ParserLiterals.h"
#include "ParserVariables.h"

namespace cromio::parser {
    class Parser final : public ParserLiterals, public ParserVariables {
       public:
        explicit Parser(std::string& source) : ParserLiterals(source), ParserVariables(source), source(source) {}
        std::any visitProgram(Grammar::ProgramContext* ctx) override;
        std::any visitStatement(Grammar::StatementContext* ctx) override;
        std::any visitExpression(Grammar::ExpressionContext* ctx) override;

    private:
        std::string& source;
    };
} // namespace cromio::parser

#endif // CROMIO_BASE_PARSER_H
