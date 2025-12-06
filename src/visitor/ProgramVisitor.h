//
// Created by Brayhan De Aza on 10/19/25.
//

#ifndef CROMIO_PROGRAM_VISITOR_H
#define CROMIO_PROGRAM_VISITOR_H

#include "BaseVisitor.h"
#include "ExpressionVisitor.h"
#include "LiteralsVisitor.h"
#include "VariablesVisitor.h"

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
