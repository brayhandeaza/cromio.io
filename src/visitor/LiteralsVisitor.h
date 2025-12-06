//
// Created by Brayhan De Aza on 10/19/25.
//

#ifndef CROMIO_LITERALS_VISITOR_H
#define CROMIO_LITERALS_VISITOR_H

#include "GrammarVisitor.h"

namespace cromio::visitor {
    class LiteralsVisitor : public virtual GrammarVisitor {
       public:
        explicit LiteralsVisitor(std::string& source) : source(source) {}
        std::any visitLiteral(Grammar::LiteralContext* ctx) override;
        std::any visitIntegerLiteral(Grammar::IntegerLiteralContext* ctx) override;
        std::any visitFloatLiteral(Grammar::FloatLiteralContext* ctx) override;
        std::any visitStringLiteral(Grammar::StringLiteralContext* ctx) override;
        std::any visitBooleanLiteral(Grammar::BooleanLiteralContext* ctx) override;
        std::any visitNoneLiteral(Grammar::NoneLiteralContext* ctx) override;
        std::any visitFormattedString(Grammar::FormattedStringContext* ctx) override;
        std::any visitFormattedStringContent(Grammar::FormattedStringContentContext* ctx) override;

       private:
        std::string& source;
    };
} // namespace cromio::visitor

#endif // CROMIO_LITERALS_VISITOR_H
