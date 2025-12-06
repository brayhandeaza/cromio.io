//
// Created by Brayhan De Aza on 10/19/25.
//

#ifndef CROMIO_BASE_VISITOR_H
#define CROMIO_BASE_VISITOR_H

#include "GrammarVisitor.h"
#include "semantic/semantic.h"

namespace cromio::visitor {

    class BaseVisitor : public GrammarVisitor, public utils::Error, public utils::Helpers, public semantic::VariablesSemanticAnalyze {
       protected:
        std::string& source;
        std::unique_ptr<semantic::Scope> rootScope;
        semantic::Scope* scope;

       public:
        explicit BaseVisitor(std::string& source) : source(source), rootScope(std::make_unique<semantic::Scope>(nullptr)), scope(rootScope.get()) {}

        void enterScope();
        void exitScope();

        semantic::Scope* getCurrentScope() const;
    };

} // namespace cromio::visitor

#endif // CROMIO_BASE_VISITOR_H
