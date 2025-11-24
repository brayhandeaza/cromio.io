//
// Created by Brayhan De Aza on 10/19/25.
//

#ifndef CROMIO_FORMATTED_STRING_PARSER_H
#define CROMIO_FORMATTED_STRING_PARSER_H

#include "GrammarVisitor.h"
#include "Helpers.h"

class FormattedStringParser : public virtual GrammarVisitor {
public:
    std::any visitFormattedString(Grammar::FormattedStringContext* ctx) override;
    std::any visitFormattedStringContent(Grammar::FormattedStringContentContext* ctx) override;
};

#endif // CROMIO_FORMATTED_STRING_PARSER_H