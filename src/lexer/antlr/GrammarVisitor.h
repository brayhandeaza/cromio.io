
// Generated from Grammar.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "Grammar.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by Grammar.
 */
class  GrammarVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by Grammar.
   */
    virtual std::any visitProgram(Grammar::ProgramContext *context) = 0;

    virtual std::any visitStatement(Grammar::StatementContext *context) = 0;

    virtual std::any visitExpression(Grammar::ExpressionContext *context) = 0;

    virtual std::any visitLiteral(Grammar::LiteralContext *context) = 0;

    virtual std::any visitFormattedString(Grammar::FormattedStringContext *context) = 0;

    virtual std::any visitFormattedStringContent(Grammar::FormattedStringContentContext *context) = 0;

    virtual std::any visitIntegerLiteral(Grammar::IntegerLiteralContext *context) = 0;

    virtual std::any visitFloatLiteral(Grammar::FloatLiteralContext *context) = 0;

    virtual std::any visitStringLiteral(Grammar::StringLiteralContext *context) = 0;

    virtual std::any visitBooleanLiteral(Grammar::BooleanLiteralContext *context) = 0;

    virtual std::any visitNoneLiteral(Grammar::NoneLiteralContext *context) = 0;


};

