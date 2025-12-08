//
// Created by Brayhan De Aza on 10/19/25.
//

#ifndef CROMIO_ARRAYS_VISITOR_H
#define CROMIO_ARRAYS_VISITOR_H

#include "GrammarVisitor.h"
#include "semantic/semantic.h"
#include "visitor/base/BaseVisitor.h"

namespace cromio::visitor {
    class ArraysVisitor : public virtual BaseVisitor {
       public:
        std::any visitArrayDeclaration(Grammar::ArrayDeclarationContext* ctx) override;
        std::any visitArrayDeclarationTypeSize(Grammar::ArrayDeclarationTypeSizeContext* ctx) override;
    };
} // namespace cromio::visitor

#endif // CROMIO_ARRAYS_VISITOR_H