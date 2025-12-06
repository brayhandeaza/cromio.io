//
// Created by Brayhan De Aza on 10/19/25.
//

#ifndef CROMIO_VARIABLES_VISITOR_H
#define CROMIO_VARIABLES_VISITOR_H

#include "GrammarVisitor.h"
#include "semantic/semantic.h"

namespace cromio::visitor {
    class Parser;
    class VariablesVisitor : public virtual GrammarVisitor, semantic::VariablesSemanticAnalyze {
       public:
        explicit VariablesVisitor(std::string& source) : source(source) {}
        std::any visitVariableDeclaration(Grammar::VariableDeclarationContext* ctx) override;
        std::any visitVariableDataType(Grammar::VariableDataTypeContext* ctx) override;
        std::any visitVariableAssignment(Grammar::VariableAssignmentContext* ctx) override;
        std::any visitVariableDeclarationWithoutAssignment(Grammar::VariableDeclarationWithoutAssignmentContext* ctx) override;
        std::any visitVariables(Grammar::VariablesContext* ctx) override;
        std::any visitVariableAccessToMember(Grammar::VariableAccessToMemberContext* ctx) override;

       private:
        std::string& source;
    };
} // namespace cromio::visitor

#endif // CROMIO_VARIABLES_VISITOR_H