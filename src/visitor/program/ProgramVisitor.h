//
// Created by Brayhan De Aza on 10/19/25.
//

#ifndef CROMIO_PROGRAM_VISITOR_H
#define CROMIO_PROGRAM_VISITOR_H

#include "visitor/arrays/ArraysVisitor.h"
#include "visitor/base/BaseVisitor.h"
#include "visitor/dictionary/DictionaryVisitor.h"
#include "visitor/expressions/ExpressionVisitor.h"
#include "visitor/literals/LiteralsVisitor.h"
#include "visitor/variables/VariablesVisitor.h"

namespace cromio::visitor {
    class Visitor final : public LiteralsVisitor, public ArraysVisitor, public VariablesVisitor, public DictionaryVisitor, public ExpressionVisitor {
       public:
        explicit Visitor(std::string& source, Grammar* parser) : BaseVisitor(source, parser), LiteralsVisitor(), ArraysVisitor(), VariablesVisitor(), DictionaryVisitor(), ExpressionVisitor(), source(source), parser(parser) {}

        std::any visitProgram(Grammar::ProgramContext* ctx) override;
        std::any visitStatements(Grammar::StatementsContext* ctx) override;

       private:
        std::string& source;
        Grammar* parser;
    };
} // namespace cromio::visitor

#endif // CROMIO_PROGRAM_VISITOR_H
