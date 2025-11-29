//
// Created by Brayhan De Aza on 10/19/25.
//

#ifndef CROMIO_PARSER_VARIABLES_H
#define CROMIO_PARSER_VARIABLES_H

#include "GrammarVisitor.h"
#include "utils/utils.h"

namespace cromio::parser
{
    class ParserVariables : public virtual GrammarVisitor
    {
    public:
        std::any visitVariableDeclaration(Grammar::VariableDeclarationContext* ctx) override;
        std::any visitVariableDataType(Grammar::VariableDataTypeContext* ctx) override;
    };
}

#endif //CROMIO_PARSER_VARIABLES_H