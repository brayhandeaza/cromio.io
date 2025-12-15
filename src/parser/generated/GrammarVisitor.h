
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

    virtual std::any visitStatements(Grammar::StatementsContext *context) = 0;

    virtual std::any visitDictionaryDeclaration(Grammar::DictionaryDeclarationContext *context) = 0;

    virtual std::any visitDictionaryAssignmentBody(Grammar::DictionaryAssignmentBodyContext *context) = 0;

    virtual std::any visitDictionaryDeclarationType(Grammar::DictionaryDeclarationTypeContext *context) = 0;

    virtual std::any visitDictionaryTypeElement(Grammar::DictionaryTypeElementContext *context) = 0;

    virtual std::any visitDictionaryDeclarationTypeArray(Grammar::DictionaryDeclarationTypeArrayContext *context) = 0;

    virtual std::any visitDictionaryDataType(Grammar::DictionaryDataTypeContext *context) = 0;

    virtual std::any visitExpression(Grammar::ExpressionContext *context) = 0;

    virtual std::any visitConcatenationExpression(Grammar::ConcatenationExpressionContext *context) = 0;

    virtual std::any visitBinaryExpression(Grammar::BinaryExpressionContext *context) = 0;

    virtual std::any visitLiteral(Grammar::LiteralContext *context) = 0;

    virtual std::any visitNumberLiterals(Grammar::NumberLiteralsContext *context) = 0;

    virtual std::any visitStringLiterals(Grammar::StringLiteralsContext *context) = 0;

    virtual std::any visitFormattedString(Grammar::FormattedStringContext *context) = 0;

    virtual std::any visitFormattedStringContent(Grammar::FormattedStringContentContext *context) = 0;

    virtual std::any visitStringLiteral(Grammar::StringLiteralContext *context) = 0;

    virtual std::any visitIntegerLiteral(Grammar::IntegerLiteralContext *context) = 0;

    virtual std::any visitFloatLiteral(Grammar::FloatLiteralContext *context) = 0;

    virtual std::any visitBooleanLiteral(Grammar::BooleanLiteralContext *context) = 0;

    virtual std::any visitNoneLiteral(Grammar::NoneLiteralContext *context) = 0;

    virtual std::any visitIdentifierLiteral(Grammar::IdentifierLiteralContext *context) = 0;

    virtual std::any visitVariables(Grammar::VariablesContext *context) = 0;

    virtual std::any visitVariableDeclaration(Grammar::VariableDeclarationContext *context) = 0;

    virtual std::any visitVariableDeclarationWithoutAssignment(Grammar::VariableDeclarationWithoutAssignmentContext *context) = 0;

    virtual std::any visitVariableReAssignment(Grammar::VariableReAssignmentContext *context) = 0;

    virtual std::any visitVariableAccessToMember(Grammar::VariableAccessToMemberContext *context) = 0;

    virtual std::any visitVariableDataType(Grammar::VariableDataTypeContext *context) = 0;

    virtual std::any visitArrays(Grammar::ArraysContext *context) = 0;

    virtual std::any visitArrayDeclaration(Grammar::ArrayDeclarationContext *context) = 0;

    virtual std::any visitArrayItems(Grammar::ArrayItemsContext *context) = 0;

    virtual std::any visitArrayReAssignment(Grammar::ArrayReAssignmentContext *context) = 0;

    virtual std::any visitArrayType(Grammar::ArrayTypeContext *context) = 0;

    virtual std::any visitArrayDeclarationTypeSize(Grammar::ArrayDeclarationTypeSizeContext *context) = 0;

    virtual std::any visitArrayDataType(Grammar::ArrayDataTypeContext *context) = 0;


};

