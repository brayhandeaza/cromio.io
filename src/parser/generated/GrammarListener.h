
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

  virtual void enterStatements(Grammar::StatementsContext *ctx) = 0;
  virtual void exitStatements(Grammar::StatementsContext *ctx) = 0;

  virtual void enterDictionaryDeclaration(Grammar::DictionaryDeclarationContext *ctx) = 0;
  virtual void exitDictionaryDeclaration(Grammar::DictionaryDeclarationContext *ctx) = 0;

  virtual void enterDictionaryAssignmentBody(Grammar::DictionaryAssignmentBodyContext *ctx) = 0;
  virtual void exitDictionaryAssignmentBody(Grammar::DictionaryAssignmentBodyContext *ctx) = 0;

  virtual void enterDictionaryDeclarationType(Grammar::DictionaryDeclarationTypeContext *ctx) = 0;
  virtual void exitDictionaryDeclarationType(Grammar::DictionaryDeclarationTypeContext *ctx) = 0;

  virtual void enterDictionaryTypeElement(Grammar::DictionaryTypeElementContext *ctx) = 0;
  virtual void exitDictionaryTypeElement(Grammar::DictionaryTypeElementContext *ctx) = 0;

  virtual void enterDictionaryDeclarationTypeArray(Grammar::DictionaryDeclarationTypeArrayContext *ctx) = 0;
  virtual void exitDictionaryDeclarationTypeArray(Grammar::DictionaryDeclarationTypeArrayContext *ctx) = 0;

  virtual void enterDictionaryDataType(Grammar::DictionaryDataTypeContext *ctx) = 0;
  virtual void exitDictionaryDataType(Grammar::DictionaryDataTypeContext *ctx) = 0;

  virtual void enterExpression(Grammar::ExpressionContext *ctx) = 0;
  virtual void exitExpression(Grammar::ExpressionContext *ctx) = 0;

  virtual void enterConcatenationExpression(Grammar::ConcatenationExpressionContext *ctx) = 0;
  virtual void exitConcatenationExpression(Grammar::ConcatenationExpressionContext *ctx) = 0;

  virtual void enterBinaryExpression(Grammar::BinaryExpressionContext *ctx) = 0;
  virtual void exitBinaryExpression(Grammar::BinaryExpressionContext *ctx) = 0;

  virtual void enterLiteral(Grammar::LiteralContext *ctx) = 0;
  virtual void exitLiteral(Grammar::LiteralContext *ctx) = 0;

  virtual void enterNumberLiterals(Grammar::NumberLiteralsContext *ctx) = 0;
  virtual void exitNumberLiterals(Grammar::NumberLiteralsContext *ctx) = 0;

  virtual void enterStringLiterals(Grammar::StringLiteralsContext *ctx) = 0;
  virtual void exitStringLiterals(Grammar::StringLiteralsContext *ctx) = 0;

  virtual void enterFormattedString(Grammar::FormattedStringContext *ctx) = 0;
  virtual void exitFormattedString(Grammar::FormattedStringContext *ctx) = 0;

  virtual void enterFormattedStringContent(Grammar::FormattedStringContentContext *ctx) = 0;
  virtual void exitFormattedStringContent(Grammar::FormattedStringContentContext *ctx) = 0;

  virtual void enterStringLiteral(Grammar::StringLiteralContext *ctx) = 0;
  virtual void exitStringLiteral(Grammar::StringLiteralContext *ctx) = 0;

  virtual void enterIntegerLiteral(Grammar::IntegerLiteralContext *ctx) = 0;
  virtual void exitIntegerLiteral(Grammar::IntegerLiteralContext *ctx) = 0;

  virtual void enterFloatLiteral(Grammar::FloatLiteralContext *ctx) = 0;
  virtual void exitFloatLiteral(Grammar::FloatLiteralContext *ctx) = 0;

  virtual void enterBooleanLiteral(Grammar::BooleanLiteralContext *ctx) = 0;
  virtual void exitBooleanLiteral(Grammar::BooleanLiteralContext *ctx) = 0;

  virtual void enterNoneLiteral(Grammar::NoneLiteralContext *ctx) = 0;
  virtual void exitNoneLiteral(Grammar::NoneLiteralContext *ctx) = 0;

  virtual void enterIdentifierLiteral(Grammar::IdentifierLiteralContext *ctx) = 0;
  virtual void exitIdentifierLiteral(Grammar::IdentifierLiteralContext *ctx) = 0;

  virtual void enterVariables(Grammar::VariablesContext *ctx) = 0;
  virtual void exitVariables(Grammar::VariablesContext *ctx) = 0;

  virtual void enterVariableDeclaration(Grammar::VariableDeclarationContext *ctx) = 0;
  virtual void exitVariableDeclaration(Grammar::VariableDeclarationContext *ctx) = 0;

  virtual void enterVariableDeclarationWithoutAssignment(Grammar::VariableDeclarationWithoutAssignmentContext *ctx) = 0;
  virtual void exitVariableDeclarationWithoutAssignment(Grammar::VariableDeclarationWithoutAssignmentContext *ctx) = 0;

  virtual void enterVariableReAssignment(Grammar::VariableReAssignmentContext *ctx) = 0;
  virtual void exitVariableReAssignment(Grammar::VariableReAssignmentContext *ctx) = 0;

  virtual void enterVariableAccessToMember(Grammar::VariableAccessToMemberContext *ctx) = 0;
  virtual void exitVariableAccessToMember(Grammar::VariableAccessToMemberContext *ctx) = 0;

  virtual void enterVariableDataType(Grammar::VariableDataTypeContext *ctx) = 0;
  virtual void exitVariableDataType(Grammar::VariableDataTypeContext *ctx) = 0;

  virtual void enterArrays(Grammar::ArraysContext *ctx) = 0;
  virtual void exitArrays(Grammar::ArraysContext *ctx) = 0;

  virtual void enterArrayDeclaration(Grammar::ArrayDeclarationContext *ctx) = 0;
  virtual void exitArrayDeclaration(Grammar::ArrayDeclarationContext *ctx) = 0;

  virtual void enterArrayItems(Grammar::ArrayItemsContext *ctx) = 0;
  virtual void exitArrayItems(Grammar::ArrayItemsContext *ctx) = 0;

  virtual void enterArrayReAssignment(Grammar::ArrayReAssignmentContext *ctx) = 0;
  virtual void exitArrayReAssignment(Grammar::ArrayReAssignmentContext *ctx) = 0;

  virtual void enterArrayType(Grammar::ArrayTypeContext *ctx) = 0;
  virtual void exitArrayType(Grammar::ArrayTypeContext *ctx) = 0;

  virtual void enterArrayDeclarationTypeSize(Grammar::ArrayDeclarationTypeSizeContext *ctx) = 0;
  virtual void exitArrayDeclarationTypeSize(Grammar::ArrayDeclarationTypeSizeContext *ctx) = 0;

  virtual void enterArrayDataType(Grammar::ArrayDataTypeContext *ctx) = 0;
  virtual void exitArrayDataType(Grammar::ArrayDataTypeContext *ctx) = 0;

  virtual void enterMemberExpression(Grammar::MemberExpressionContext *ctx) = 0;
  virtual void exitMemberExpression(Grammar::MemberExpressionContext *ctx) = 0;

  virtual void enterValueAtom(Grammar::ValueAtomContext *ctx) = 0;
  virtual void exitValueAtom(Grammar::ValueAtomContext *ctx) = 0;

  virtual void enterValuePostfix(Grammar::ValuePostfixContext *ctx) = 0;
  virtual void exitValuePostfix(Grammar::ValuePostfixContext *ctx) = 0;

  virtual void enterArgumentList(Grammar::ArgumentListContext *ctx) = 0;
  virtual void exitArgumentList(Grammar::ArgumentListContext *ctx) = 0;


};

