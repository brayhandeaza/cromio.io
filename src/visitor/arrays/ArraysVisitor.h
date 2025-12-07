//
// Created by Brayhan De Aza on 10/19/25.
//

#ifndef CROMIO_ARRAYS_VISITOR_H
#define CROMIO_ARRAYS_VISITOR_H

#include "visitor/base/BaseVisitor.h"
#include "GrammarVisitor.h"
#include "semantic/semantic.h"

namespace cromio::visitor {
    class Parser;
    class ArraysVisitor : public virtual BaseVisitor {
       public:
        explicit ArraysVisitor(std::string& source) : BaseVisitor(source) {}
        std::any visitArrayDeclaration(Grammar::ArrayDeclarationContext* ctx) override;
        std::any visitArrayAssignment(Grammar::ArrayAssignmentContext* ctx) override;
        std::any visitArrayDeclarationTypeSize(Grammar::ArrayDeclarationTypeSizeContext* ctx) override;
    };
} // namespace cromio::visitor

#endif // CROMIO_ARRAYS_VISITOR_H