
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

  virtual void enterStatements(Grammar::StatementsContext * /*ctx*/) override { }
  virtual void exitStatements(Grammar::StatementsContext * /*ctx*/) override { }

  virtual void enterDictionaryDeclaration(Grammar::DictionaryDeclarationContext * /*ctx*/) override { }
  virtual void exitDictionaryDeclaration(Grammar::DictionaryDeclarationContext * /*ctx*/) override { }

  virtual void enterDictionaryAssignmentBody(Grammar::DictionaryAssignmentBodyContext * /*ctx*/) override { }
  virtual void exitDictionaryAssignmentBody(Grammar::DictionaryAssignmentBodyContext * /*ctx*/) override { }

  virtual void enterDictionaryDeclarationType(Grammar::DictionaryDeclarationTypeContext * /*ctx*/) override { }
  virtual void exitDictionaryDeclarationType(Grammar::DictionaryDeclarationTypeContext * /*ctx*/) override { }

  virtual void enterDictionaryTypeElement(Grammar::DictionaryTypeElementContext * /*ctx*/) override { }
  virtual void exitDictionaryTypeElement(Grammar::DictionaryTypeElementContext * /*ctx*/) override { }

  virtual void enterDictionaryDeclarationTypeArray(Grammar::DictionaryDeclarationTypeArrayContext * /*ctx*/) override { }
  virtual void exitDictionaryDeclarationTypeArray(Grammar::DictionaryDeclarationTypeArrayContext * /*ctx*/) override { }

  virtual void enterDictionaryDataType(Grammar::DictionaryDataTypeContext * /*ctx*/) override { }
  virtual void exitDictionaryDataType(Grammar::DictionaryDataTypeContext * /*ctx*/) override { }

  virtual void enterExpression(Grammar::ExpressionContext * /*ctx*/) override { }
  virtual void exitExpression(Grammar::ExpressionContext * /*ctx*/) override { }

  virtual void enterConcatenationExpression(Grammar::ConcatenationExpressionContext * /*ctx*/) override { }
  virtual void exitConcatenationExpression(Grammar::ConcatenationExpressionContext * /*ctx*/) override { }

  virtual void enterBinaryExpression(Grammar::BinaryExpressionContext * /*ctx*/) override { }
  virtual void exitBinaryExpression(Grammar::BinaryExpressionContext * /*ctx*/) override { }

  virtual void enterLiteral(Grammar::LiteralContext * /*ctx*/) override { }
  virtual void exitLiteral(Grammar::LiteralContext * /*ctx*/) override { }

  virtual void enterNumberLiterals(Grammar::NumberLiteralsContext * /*ctx*/) override { }
  virtual void exitNumberLiterals(Grammar::NumberLiteralsContext * /*ctx*/) override { }

  virtual void enterStringLiterals(Grammar::StringLiteralsContext * /*ctx*/) override { }
  virtual void exitStringLiterals(Grammar::StringLiteralsContext * /*ctx*/) override { }

  virtual void enterFormattedString(Grammar::FormattedStringContext * /*ctx*/) override { }
  virtual void exitFormattedString(Grammar::FormattedStringContext * /*ctx*/) override { }

  virtual void enterFormattedStringContent(Grammar::FormattedStringContentContext * /*ctx*/) override { }
  virtual void exitFormattedStringContent(Grammar::FormattedStringContentContext * /*ctx*/) override { }

  virtual void enterStringLiteral(Grammar::StringLiteralContext * /*ctx*/) override { }
  virtual void exitStringLiteral(Grammar::StringLiteralContext * /*ctx*/) override { }

  virtual void enterIntegerLiteral(Grammar::IntegerLiteralContext * /*ctx*/) override { }
  virtual void exitIntegerLiteral(Grammar::IntegerLiteralContext * /*ctx*/) override { }

  virtual void enterFloatLiteral(Grammar::FloatLiteralContext * /*ctx*/) override { }
  virtual void exitFloatLiteral(Grammar::FloatLiteralContext * /*ctx*/) override { }

  virtual void enterBooleanLiteral(Grammar::BooleanLiteralContext * /*ctx*/) override { }
  virtual void exitBooleanLiteral(Grammar::BooleanLiteralContext * /*ctx*/) override { }

  virtual void enterNoneLiteral(Grammar::NoneLiteralContext * /*ctx*/) override { }
  virtual void exitNoneLiteral(Grammar::NoneLiteralContext * /*ctx*/) override { }

  virtual void enterIdentifierLiteral(Grammar::IdentifierLiteralContext * /*ctx*/) override { }
  virtual void exitIdentifierLiteral(Grammar::IdentifierLiteralContext * /*ctx*/) override { }

  virtual void enterVariables(Grammar::VariablesContext * /*ctx*/) override { }
  virtual void exitVariables(Grammar::VariablesContext * /*ctx*/) override { }

  virtual void enterVariableDeclaration(Grammar::VariableDeclarationContext * /*ctx*/) override { }
  virtual void exitVariableDeclaration(Grammar::VariableDeclarationContext * /*ctx*/) override { }

  virtual void enterVariableDeclarationWithoutAssignment(Grammar::VariableDeclarationWithoutAssignmentContext * /*ctx*/) override { }
  virtual void exitVariableDeclarationWithoutAssignment(Grammar::VariableDeclarationWithoutAssignmentContext * /*ctx*/) override { }

  virtual void enterVariableReAssignment(Grammar::VariableReAssignmentContext * /*ctx*/) override { }
  virtual void exitVariableReAssignment(Grammar::VariableReAssignmentContext * /*ctx*/) override { }

  virtual void enterVariableAccessToMember(Grammar::VariableAccessToMemberContext * /*ctx*/) override { }
  virtual void exitVariableAccessToMember(Grammar::VariableAccessToMemberContext * /*ctx*/) override { }

  virtual void enterVariableDataType(Grammar::VariableDataTypeContext * /*ctx*/) override { }
  virtual void exitVariableDataType(Grammar::VariableDataTypeContext * /*ctx*/) override { }

  virtual void enterArrayDeclaration(Grammar::ArrayDeclarationContext * /*ctx*/) override { }
  virtual void exitArrayDeclaration(Grammar::ArrayDeclarationContext * /*ctx*/) override { }

  virtual void enterArrayType(Grammar::ArrayTypeContext * /*ctx*/) override { }
  virtual void exitArrayType(Grammar::ArrayTypeContext * /*ctx*/) override { }

  virtual void enterArrayDeclarationTypeSize(Grammar::ArrayDeclarationTypeSizeContext * /*ctx*/) override { }
  virtual void exitArrayDeclarationTypeSize(Grammar::ArrayDeclarationTypeSizeContext * /*ctx*/) override { }

  virtual void enterArrayDataType(Grammar::ArrayDataTypeContext * /*ctx*/) override { }
  virtual void exitArrayDataType(Grammar::ArrayDataTypeContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

