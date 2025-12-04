//
// Created by Brayhan De Aza on 10/19/25.
//

#ifndef CROMIO_PARSER_VARIABLES_H
#define CROMIO_PARSER_VARIABLES_H

#include "GrammarVisitor.h"
#include "semantic/semantic.h"

namespace cromio::parser {
    class ParserVariables : public virtual GrammarVisitor, semantic::VariablesSemanticAnalyze {
       public:
        explicit ParserVariables(std::string& source) : source(source) {}
        std::any visitVariableDeclaration(Grammar::VariableDeclarationContext* ctx) override;
        std::any visitVariableDataType(Grammar::VariableDataTypeContext* ctx) override;
        std::any visitVariableAssignment(Grammar::VariableAssignmentContext* ctx) override;
        std::any visitVariableDeclarationWithoutAssignment(Grammar::VariableDeclarationWithoutAssignmentContext* ctx) override;
        std::any visitVariables(Grammar::VariablesContext* ctx) override;

       private:
        std::string& source;
    };
} // namespace cromio::parser

#endif // CROMIO_PARSER_VARIABLES_H