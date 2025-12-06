//
// Created by Brayhan De Aza on 10/19/25.
//

#ifndef CROMIO_PROGRAM_VISITOR_H
#define CROMIO_PROGRAM_VISITOR_H

#include "visitor/base/BaseVisitor.h"
#include "visitor/expressions/ExpressionVisitor.h"
#include "visitor/literals/LiteralsVisitor.h"
#include "visitor/variables/VariablesVisitor.h"

namespace cromio::visitor {
    class Visitor final : public LiteralsVisitor, public VariablesVisitor, public ExpressionVisitor {
       public:
        explicit Visitor(std::string& source) : BaseVisitor(source), LiteralsVisitor(source), VariablesVisitor(source), ExpressionVisitor(source), source(source) {}

        std::any visitProgram(Grammar::ProgramContext* ctx) override;
        std::any visitStatements(Grammar::StatementsContext* ctx) override;

       private:
        std::string& source;
    };
} // namespace cromio::visitor

#endif // CROMIO_PROGRAM_VISITOR_H
