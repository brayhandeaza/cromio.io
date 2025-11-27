//
// Created by Brayhan De Aza on 10/19/25.
//

#ifndef CROMIO_PARSER_LITERALS_H
#define CROMIO_PARSER_LITERALS_H

#include "GrammarVisitor.h"
#include "utils/Helpers.h"

namespace cromio
{
    class ParserLiterals : public virtual GrammarVisitor
    {
    public:
        std::any visitLiteral(Grammar::LiteralContext* ctx) override;
        std::any visitIntegerLiteral(Grammar::IntegerLiteralContext* ctx) override;

        std::any visitFloatLiteral(Grammar::FloatLiteralContext* ctx) override;

        std::any visitStringLiteral(Grammar::StringLiteralContext* ctx) override;

        std::any visitBooleanLiteral(Grammar::BooleanLiteralContext* ctx) override;

        std::any visitNoneLiteral(Grammar::NoneLiteralContext* ctx) override;

        std::any visitFormattedString(Grammar::FormattedStringContext* ctx) override;

        std::any visitFormattedStringContent(Grammar::FormattedStringContentContext* ctx) override;
    };

#endif //CROMIO_PARSER_LITERALS_H
}
