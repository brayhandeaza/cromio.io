//
// Created by Brayhan De Aza on 12/4/25.
//

#ifndef CROMIO_EXPRESSION_STATEMENTS_H
#define CROMIO_EXPRESSION_STATEMENTS_H

#include "GrammarVisitor.h"
#include "ParserVariables.h"

namespace cromio::parser {
    class ExpressionStatements : public virtual GrammarVisitor {
       public:
        explicit ExpressionStatements(std::string& source) : source(source) {}
        std::any visitExpression(Grammar::ExpressionContext* ctx) override;

       private:
        std::string& source;
    };
} // namespace cromio::parser

#endif // CROMIO_EXPRESSION_STATEMENTS_H
