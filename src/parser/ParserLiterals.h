//
// Created by Brayhan De Aza on 10/19/25.
//

#ifndef CROMIO_PARSER_LITERALS_H
#define CROMIO_PARSER_LITERALS_H

#include "GrammarVisitor.h"
#include "utils/utils.h"

namespace cromio::parser {
    class ParserLiterals : public virtual GrammarVisitor {
       public:
        explicit ParserLiterals(std::string& source) : source(source) {}
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
} // namespace cromio::parser
#endif // CROMIO_PARSER_LITERALS_H
