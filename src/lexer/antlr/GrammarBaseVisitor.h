
// Generated from Grammar.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "GrammarVisitor.h"


/**
 * This class provides an empty implementation of GrammarVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  GrammarBaseVisitor : public GrammarVisitor {
public:

  virtual std::any visitProgram(Grammar::ProgramContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStatement(Grammar::StatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpression(Grammar::ExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLiteral(Grammar::LiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFormattedString(Grammar::FormattedStringContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFormattedStringContent(Grammar::FormattedStringContentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIntegerLiteral(Grammar::IntegerLiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFloatLiteral(Grammar::FloatLiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStringLiteral(Grammar::StringLiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBooleanLiteral(Grammar::BooleanLiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNoneLiteral(Grammar::NoneLiteralContext *ctx) override {
    return visitChildren(ctx);
  }


};

