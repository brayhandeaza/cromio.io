
// Generated from Grammar.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "GrammarListener.h"


/**
 * This class provides an empty implementation of GrammarListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  GrammarBaseListener : public GrammarListener {
public:

  virtual void enterProgram(Grammar::ProgramContext * /*ctx*/) override { }
  virtual void exitProgram(Grammar::ProgramContext * /*ctx*/) override { }

  virtual void enterStatement(Grammar::StatementContext * /*ctx*/) override { }
  virtual void exitStatement(Grammar::StatementContext * /*ctx*/) override { }

  virtual void enterExpression(Grammar::ExpressionContext * /*ctx*/) override { }
  virtual void exitExpression(Grammar::ExpressionContext * /*ctx*/) override { }

  virtual void enterLiteral(Grammar::LiteralContext * /*ctx*/) override { }
  virtual void exitLiteral(Grammar::LiteralContext * /*ctx*/) override { }

  virtual void enterFormattedString(Grammar::FormattedStringContext * /*ctx*/) override { }
  virtual void exitFormattedString(Grammar::FormattedStringContext * /*ctx*/) override { }

  virtual void enterFormattedStringContent(Grammar::FormattedStringContentContext * /*ctx*/) override { }
  virtual void exitFormattedStringContent(Grammar::FormattedStringContentContext * /*ctx*/) override { }

  virtual void enterIntegerLiteral(Grammar::IntegerLiteralContext * /*ctx*/) override { }
  virtual void exitIntegerLiteral(Grammar::IntegerLiteralContext * /*ctx*/) override { }

  virtual void enterFloatLiteral(Grammar::FloatLiteralContext * /*ctx*/) override { }
  virtual void exitFloatLiteral(Grammar::FloatLiteralContext * /*ctx*/) override { }

  virtual void enterStringLiteral(Grammar::StringLiteralContext * /*ctx*/) override { }
  virtual void exitStringLiteral(Grammar::StringLiteralContext * /*ctx*/) override { }

  virtual void enterBooleanLiteral(Grammar::BooleanLiteralContext * /*ctx*/) override { }
  virtual void exitBooleanLiteral(Grammar::BooleanLiteralContext * /*ctx*/) override { }

  virtual void enterNoneLiteral(Grammar::NoneLiteralContext * /*ctx*/) override { }
  virtual void exitNoneLiteral(Grammar::NoneLiteralContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

