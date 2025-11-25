
// Generated from Grammar.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "Grammar.h"


/**
 * This interface defines an abstract listener for a parse tree produced by Grammar.
 */
class  GrammarListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterProgram(Grammar::ProgramContext *ctx) = 0;
  virtual void exitProgram(Grammar::ProgramContext *ctx) = 0;

  virtual void enterStatement(Grammar::StatementContext *ctx) = 0;
  virtual void exitStatement(Grammar::StatementContext *ctx) = 0;

  virtual void enterExpression(Grammar::ExpressionContext *ctx) = 0;
  virtual void exitExpression(Grammar::ExpressionContext *ctx) = 0;

  virtual void enterLiteral(Grammar::LiteralContext *ctx) = 0;
  virtual void exitLiteral(Grammar::LiteralContext *ctx) = 0;

  virtual void enterFormattedString(Grammar::FormattedStringContext *ctx) = 0;
  virtual void exitFormattedString(Grammar::FormattedStringContext *ctx) = 0;

  virtual void enterFormattedStringContent(Grammar::FormattedStringContentContext *ctx) = 0;
  virtual void exitFormattedStringContent(Grammar::FormattedStringContentContext *ctx) = 0;

  virtual void enterIntegerLiteral(Grammar::IntegerLiteralContext *ctx) = 0;
  virtual void exitIntegerLiteral(Grammar::IntegerLiteralContext *ctx) = 0;

  virtual void enterFloatLiteral(Grammar::FloatLiteralContext *ctx) = 0;
  virtual void exitFloatLiteral(Grammar::FloatLiteralContext *ctx) = 0;

  virtual void enterStringLiteral(Grammar::StringLiteralContext *ctx) = 0;
  virtual void exitStringLiteral(Grammar::StringLiteralContext *ctx) = 0;

  virtual void enterBooleanLiteral(Grammar::BooleanLiteralContext *ctx) = 0;
  virtual void exitBooleanLiteral(Grammar::BooleanLiteralContext *ctx) = 0;

  virtual void enterNoneLiteral(Grammar::NoneLiteralContext *ctx) = 0;
  virtual void exitNoneLiteral(Grammar::NoneLiteralContext *ctx) = 0;


};

