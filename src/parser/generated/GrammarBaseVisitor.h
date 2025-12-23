
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

  virtual std::any visitStatements(Grammar::StatementsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDictionaryDeclaration(Grammar::DictionaryDeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDictionaryAssignmentBody(Grammar::DictionaryAssignmentBodyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDictionaryDeclarationType(Grammar::DictionaryDeclarationTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDictionaryTypeElement(Grammar::DictionaryTypeElementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDictionaryDeclarationTypeArray(Grammar::DictionaryDeclarationTypeArrayContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDictionaryDataType(Grammar::DictionaryDataTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpression(Grammar::ExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitConcatenationExpression(Grammar::ConcatenationExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBinaryExpression(Grammar::BinaryExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLiteral(Grammar::LiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNumberLiterals(Grammar::NumberLiteralsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStringLiterals(Grammar::StringLiteralsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFormattedString(Grammar::FormattedStringContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFormattedStringContent(Grammar::FormattedStringContentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStringLiteral(Grammar::StringLiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIntegerLiteral(Grammar::IntegerLiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFloatLiteral(Grammar::FloatLiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBooleanLiteral(Grammar::BooleanLiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNoneLiteral(Grammar::NoneLiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIdentifierLiteral(Grammar::IdentifierLiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMemberExpression(Grammar::MemberExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitValuePostfix(Grammar::ValuePostfixContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArgumentList(Grammar::ArgumentListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitValueAtom(Grammar::ValueAtomContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVariables(Grammar::VariablesContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVariableDeclaration(Grammar::VariableDeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVariableDeclarationWithoutAssignment(Grammar::VariableDeclarationWithoutAssignmentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVariableReAssignment(Grammar::VariableReAssignmentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVariableValue(Grammar::VariableValueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVariableDataType(Grammar::VariableDataTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArrays(Grammar::ArraysContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArrayDeclaration(Grammar::ArrayDeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArrayItems(Grammar::ArrayItemsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArrayReAssignment(Grammar::ArrayReAssignmentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArrayType(Grammar::ArrayTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArrayDeclarationTypeSize(Grammar::ArrayDeclarationTypeSizeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArrayDataType(Grammar::ArrayDataTypeContext *ctx) override {
    return visitChildren(ctx);
  }


};

