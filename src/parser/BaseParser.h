//
// Created by Brayhan De Aza on 10/19/25.
//

#ifndef CROMIO_BASE_PARSER_H
#define CROMIO_BASE_PARSER_H

#include "GrammarVisitor.h"
#include "ParserLiterals.h"

namespace cromio::parser
{
    class Parser final : public ParserLiterals
    {
    public:
        std::any visitProgram(Grammar::ProgramContext* ctx) override;
        std::any visitStatement(Grammar::StatementContext* ctx) override;
        std::any visitExpression(Grammar::ExpressionContext* ctx) override;
    };
}


#endif //CROMIO_BASE_PARSER_H
