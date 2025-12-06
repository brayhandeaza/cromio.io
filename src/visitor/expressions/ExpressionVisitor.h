//
// Created by Brayhan De Aza on 12/4/25.
//

#ifndef CROMIO_EXPRESSION_VISITOR_H
#define CROMIO_EXPRESSION_VISITOR_H

#include "GrammarVisitor.h"
#include "visitor/base/BaseVisitor.h"

namespace cromio::visitor {
    class ExpressionVisitor : public virtual BaseVisitor {
       public:
        explicit ExpressionVisitor(std::string& source) : source(source) {}
        std::any visitExpression(Grammar::ExpressionContext* ctx) override;

       private:
        std::string& source;
    };
} // namespace cromio::parser

#endif // CROMIO_EXPRESSION_VISITOR_H
