
// Generated from Grammar.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"




class  Grammar : public antlr4::Parser {
public:
  enum {
    DICT_KEYWORD = 1, BOOLEAN_TYPES = 2, STRING_TYPES = 3, INTEGER_TYPES = 4, 
    UNSIGNED_INTEGER_TYPES = 5, FLOAT_TYPES = 6, NONE = 7, BOOLEAN = 8, 
    IDENTIFIER = 9, PLUS = 10, MINUS = 11, MUL = 12, DIV = 13, MOD = 14, 
    EQ = 15, LPAREN = 16, RPAREN = 17, LBRACE = 18, RBRACE = 19, LBRACKET = 20, 
    RBRACKET = 21, DOT = 22, COMMA = 23, AMPERSAND = 24, LESSTHAN = 25, 
    GREATERTHAN = 26, COLON = 27, NEWLINE = 28, NEWLINE_VISIBLE = 29, WS_VISIBLE = 30, 
    COMMENT = 31, BLOCK_COMMENT = 32, WS = 33, FLOAT = 34, INTEGER = 35, 
    STRING = 36, FORMATTED_STRING_START = 37, FORMATTED_STRING_TEXT = 38, 
    LBRACE_IN_FSTRING = 39, FORMATTED_STRING_END = 40, RBRACE_IN_FSTRING = 41, 
    EXPR_WS = 42
  };

  enum {
    RuleProgram = 0, RuleStatements = 1, RuleDictionaryDeclaration = 2, 
    RuleDictionaryAssignmentBody = 3, RuleDictionaryDeclarationType = 4, 
    RuleDictionaryTypeElement = 5, RuleDictionaryDeclarationTypeArray = 6, 
    RuleDictionaryDataType = 7, RuleExpression = 8, RuleConcatenationExpression = 9, 
    RuleBinaryExpression = 10, RuleLiteral = 11, RuleNumberLiterals = 12, 
    RuleStringLiterals = 13, RuleFormattedString = 14, RuleFormattedStringContent = 15, 
    RuleStringLiteral = 16, RuleIntegerLiteral = 17, RuleFloatLiteral = 18, 
    RuleBooleanLiteral = 19, RuleNoneLiteral = 20, RuleIdentifierLiteral = 21, 
    RuleVariables = 22, RuleVariableDeclaration = 23, RuleVariableDeclarationWithoutAssignment = 24, 
    RuleVariableReAssignment = 25, RuleVariableAccessToMember = 26, RuleVariableDataType = 27, 
    RuleArrays = 28, RuleArrayDeclaration = 29, RuleArrayItems = 30, RuleArrayReAssignment = 31, 
    RuleArrayType = 32, RuleArrayDeclarationTypeSize = 33, RuleArrayDataType = 34
  };

  explicit Grammar(antlr4::TokenStream *input);

  Grammar(antlr4::TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options);

  ~Grammar() override;

  std::string getGrammarFileName() const override;

  const antlr4::atn::ATN& getATN() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;


      public:
          bool inVarMode = false;
          bool inSkipMode = false;


  class ProgramContext;
  class StatementsContext;
  class DictionaryDeclarationContext;
  class DictionaryAssignmentBodyContext;
  class DictionaryDeclarationTypeContext;
  class DictionaryTypeElementContext;
  class DictionaryDeclarationTypeArrayContext;
  class DictionaryDataTypeContext;
  class ExpressionContext;
  class ConcatenationExpressionContext;
  class BinaryExpressionContext;
  class LiteralContext;
  class NumberLiteralsContext;
  class StringLiteralsContext;
  class FormattedStringContext;
  class FormattedStringContentContext;
  class StringLiteralContext;
  class IntegerLiteralContext;
  class FloatLiteralContext;
  class BooleanLiteralContext;
  class NoneLiteralContext;
  class IdentifierLiteralContext;
  class VariablesContext;
  class VariableDeclarationContext;
  class VariableDeclarationWithoutAssignmentContext;
  class VariableReAssignmentContext;
  class VariableAccessToMemberContext;
  class VariableDataTypeContext;
  class ArraysContext;
  class ArrayDeclarationContext;
  class ArrayItemsContext;
  class ArrayReAssignmentContext;
  class ArrayTypeContext;
  class ArrayDeclarationTypeSizeContext;
  class ArrayDataTypeContext; 

  class  ProgramContext : public antlr4::ParserRuleContext {
  public:
    ProgramContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EOF();
    std::vector<antlr4::tree::TerminalNode *> NEWLINE();
    antlr4::tree::TerminalNode* NEWLINE(size_t i);
    std::vector<StatementsContext *> statements();
    StatementsContext* statements(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ProgramContext* program();

  class  StatementsContext : public antlr4::ParserRuleContext {
  public:
    StatementsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    VariablesContext *variables();
    ArraysContext *arrays();
    DictionaryDeclarationContext *dictionaryDeclaration();
    ExpressionContext *expression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StatementsContext* statements();

  class  DictionaryDeclarationContext : public antlr4::ParserRuleContext {
  public:
    DictionaryDeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DICT_KEYWORD();
    antlr4::tree::TerminalNode *LESSTHAN();
    DictionaryDeclarationTypeContext *dictionaryDeclarationType();
    antlr4::tree::TerminalNode *GREATERTHAN();
    antlr4::tree::TerminalNode *IDENTIFIER();
    antlr4::tree::TerminalNode *EQ();
    antlr4::tree::TerminalNode *LBRACE();
    antlr4::tree::TerminalNode *RBRACE();
    std::vector<DictionaryAssignmentBodyContext *> dictionaryAssignmentBody();
    DictionaryAssignmentBodyContext* dictionaryAssignmentBody(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DictionaryDeclarationContext* dictionaryDeclaration();

  class  DictionaryAssignmentBodyContext : public antlr4::ParserRuleContext {
  public:
    DictionaryAssignmentBodyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    LiteralContext *literal();
    antlr4::tree::TerminalNode *COLON();
    ExpressionContext *expression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DictionaryAssignmentBodyContext* dictionaryAssignmentBody();

  class  DictionaryDeclarationTypeContext : public antlr4::ParserRuleContext {
  public:
    DictionaryDeclarationTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<DictionaryTypeElementContext *> dictionaryTypeElement();
    DictionaryTypeElementContext* dictionaryTypeElement(size_t i);
    antlr4::tree::TerminalNode *COMMA();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DictionaryDeclarationTypeContext* dictionaryDeclarationType();

  class  DictionaryTypeElementContext : public antlr4::ParserRuleContext {
  public:
    DictionaryTypeElementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    DictionaryDeclarationTypeArrayContext *dictionaryDeclarationTypeArray();
    DictionaryDataTypeContext *dictionaryDataType();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DictionaryTypeElementContext* dictionaryTypeElement();

  class  DictionaryDeclarationTypeArrayContext : public antlr4::ParserRuleContext {
  public:
    DictionaryDeclarationTypeArrayContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    DictionaryDataTypeContext *dictionaryDataType();
    antlr4::tree::TerminalNode *LBRACKET();
    antlr4::tree::TerminalNode *RBRACKET();
    ExpressionContext *expression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DictionaryDeclarationTypeArrayContext* dictionaryDeclarationTypeArray();

  class  DictionaryDataTypeContext : public antlr4::ParserRuleContext {
  public:
    DictionaryDataTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *INTEGER_TYPES();
    antlr4::tree::TerminalNode *UNSIGNED_INTEGER_TYPES();
    antlr4::tree::TerminalNode *FLOAT_TYPES();
    antlr4::tree::TerminalNode *BOOLEAN_TYPES();
    antlr4::tree::TerminalNode *STRING_TYPES();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DictionaryDataTypeContext* dictionaryDataType();

  class  ExpressionContext : public antlr4::ParserRuleContext {
  public:
    ExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ConcatenationExpressionContext *concatenationExpression();
    BinaryExpressionContext *binaryExpression();
    StringLiteralsContext *stringLiterals();
    NumberLiteralsContext *numberLiterals();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ExpressionContext* expression();

  class  ConcatenationExpressionContext : public antlr4::ParserRuleContext {
  public:
    ConcatenationExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<StringLiteralsContext *> stringLiterals();
    StringLiteralsContext* stringLiterals(size_t i);
    std::vector<antlr4::tree::TerminalNode *> PLUS();
    antlr4::tree::TerminalNode* PLUS(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ConcatenationExpressionContext* concatenationExpression();

  class  BinaryExpressionContext : public antlr4::ParserRuleContext {
  public:
    BinaryExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    NumberLiteralsContext *numberLiterals();
    antlr4::tree::TerminalNode *LPAREN();
    std::vector<BinaryExpressionContext *> binaryExpression();
    BinaryExpressionContext* binaryExpression(size_t i);
    antlr4::tree::TerminalNode *RPAREN();
    antlr4::tree::TerminalNode *MUL();
    antlr4::tree::TerminalNode *DIV();
    antlr4::tree::TerminalNode *MOD();
    antlr4::tree::TerminalNode *PLUS();
    antlr4::tree::TerminalNode *MINUS();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BinaryExpressionContext* binaryExpression();
  BinaryExpressionContext* binaryExpression(int precedence);
  class  LiteralContext : public antlr4::ParserRuleContext {
  public:
    LiteralContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    NumberLiteralsContext *numberLiterals();
    StringLiteralsContext *stringLiterals();
    BooleanLiteralContext *booleanLiteral();
    IdentifierLiteralContext *identifierLiteral();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LiteralContext* literal();

  class  NumberLiteralsContext : public antlr4::ParserRuleContext {
  public:
    NumberLiteralsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IntegerLiteralContext *integerLiteral();
    FloatLiteralContext *floatLiteral();
    IdentifierLiteralContext *identifierLiteral();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  NumberLiteralsContext* numberLiterals();

  class  StringLiteralsContext : public antlr4::ParserRuleContext {
  public:
    StringLiteralsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    StringLiteralContext *stringLiteral();
    FormattedStringContext *formattedString();
    IdentifierLiteralContext *identifierLiteral();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StringLiteralsContext* stringLiterals();

  class  FormattedStringContext : public antlr4::ParserRuleContext {
  public:
    FormattedStringContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *FORMATTED_STRING_START();
    antlr4::tree::TerminalNode *FORMATTED_STRING_END();
    std::vector<FormattedStringContentContext *> formattedStringContent();
    FormattedStringContentContext* formattedStringContent(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FormattedStringContext* formattedString();

  class  FormattedStringContentContext : public antlr4::ParserRuleContext {
  public:
    FormattedStringContentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *FORMATTED_STRING_TEXT();
    antlr4::tree::TerminalNode *LBRACE_IN_FSTRING();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *RBRACE_IN_FSTRING();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FormattedStringContentContext* formattedStringContent();

  class  StringLiteralContext : public antlr4::ParserRuleContext {
  public:
    StringLiteralContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *STRING();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StringLiteralContext* stringLiteral();

  class  IntegerLiteralContext : public antlr4::ParserRuleContext {
  public:
    IntegerLiteralContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *INTEGER();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IntegerLiteralContext* integerLiteral();

  class  FloatLiteralContext : public antlr4::ParserRuleContext {
  public:
    FloatLiteralContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *FLOAT();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FloatLiteralContext* floatLiteral();

  class  BooleanLiteralContext : public antlr4::ParserRuleContext {
  public:
    BooleanLiteralContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *BOOLEAN();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BooleanLiteralContext* booleanLiteral();

  class  NoneLiteralContext : public antlr4::ParserRuleContext {
  public:
    NoneLiteralContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NONE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  NoneLiteralContext* noneLiteral();

  class  IdentifierLiteralContext : public antlr4::ParserRuleContext {
  public:
    IdentifierLiteralContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENTIFIER();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IdentifierLiteralContext* identifierLiteral();

  class  VariablesContext : public antlr4::ParserRuleContext {
  public:
    VariablesContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    VariableDeclarationContext *variableDeclaration();
    VariableDeclarationWithoutAssignmentContext *variableDeclarationWithoutAssignment();
    VariableReAssignmentContext *variableReAssignment();
    VariableAccessToMemberContext *variableAccessToMember();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  VariablesContext* variables();

  class  VariableDeclarationContext : public antlr4::ParserRuleContext {
  public:
    VariableDeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    VariableDataTypeContext *variableDataType();
    antlr4::tree::TerminalNode *IDENTIFIER();
    antlr4::tree::TerminalNode *EQ();
    ExpressionContext *expression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  VariableDeclarationContext* variableDeclaration();

  class  VariableDeclarationWithoutAssignmentContext : public antlr4::ParserRuleContext {
  public:
    VariableDeclarationWithoutAssignmentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    VariableDataTypeContext *variableDataType();
    antlr4::tree::TerminalNode *IDENTIFIER();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  VariableDeclarationWithoutAssignmentContext* variableDeclarationWithoutAssignment();

  class  VariableReAssignmentContext : public antlr4::ParserRuleContext {
  public:
    VariableReAssignmentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENTIFIER();
    antlr4::tree::TerminalNode *EQ();
    ExpressionContext *expression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  VariableReAssignmentContext* variableReAssignment();

  class  VariableAccessToMemberContext : public antlr4::ParserRuleContext {
  public:
    VariableAccessToMemberContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> IDENTIFIER();
    antlr4::tree::TerminalNode* IDENTIFIER(size_t i);
    antlr4::tree::TerminalNode *DOT();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  VariableAccessToMemberContext* variableAccessToMember();

  class  VariableDataTypeContext : public antlr4::ParserRuleContext {
  public:
    VariableDataTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *INTEGER_TYPES();
    antlr4::tree::TerminalNode *UNSIGNED_INTEGER_TYPES();
    antlr4::tree::TerminalNode *FLOAT_TYPES();
    antlr4::tree::TerminalNode *BOOLEAN_TYPES();
    antlr4::tree::TerminalNode *STRING_TYPES();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  VariableDataTypeContext* variableDataType();

  class  ArraysContext : public antlr4::ParserRuleContext {
  public:
    ArraysContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ArrayDeclarationContext *arrayDeclaration();
    ArrayReAssignmentContext *arrayReAssignment();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ArraysContext* arrays();

  class  ArrayDeclarationContext : public antlr4::ParserRuleContext {
  public:
    ArrayDeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ArrayTypeContext *arrayType();
    antlr4::tree::TerminalNode *IDENTIFIER();
    antlr4::tree::TerminalNode *EQ();
    antlr4::tree::TerminalNode *LBRACKET();
    antlr4::tree::TerminalNode *RBRACKET();
    std::vector<ArrayItemsContext *> arrayItems();
    ArrayItemsContext* arrayItems(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ArrayDeclarationContext* arrayDeclaration();

  class  ArrayItemsContext : public antlr4::ParserRuleContext {
  public:
    ArrayItemsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    StringLiteralContext *stringLiteral();
    FormattedStringContext *formattedString();
    IdentifierLiteralContext *identifierLiteral();
    IntegerLiteralContext *integerLiteral();
    FloatLiteralContext *floatLiteral();
    BooleanLiteralContext *booleanLiteral();
    NoneLiteralContext *noneLiteral();
    ConcatenationExpressionContext *concatenationExpression();
    BinaryExpressionContext *binaryExpression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ArrayItemsContext* arrayItems();

  class  ArrayReAssignmentContext : public antlr4::ParserRuleContext {
  public:
    ArrayReAssignmentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENTIFIER();
    antlr4::tree::TerminalNode *EQ();
    antlr4::tree::TerminalNode *LBRACKET();
    antlr4::tree::TerminalNode *RBRACKET();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ArrayReAssignmentContext* arrayReAssignment();

  class  ArrayTypeContext : public antlr4::ParserRuleContext {
  public:
    ArrayTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ArrayDataTypeContext *arrayDataType();
    antlr4::tree::TerminalNode *LBRACKET();
    ArrayDeclarationTypeSizeContext *arrayDeclarationTypeSize();
    antlr4::tree::TerminalNode *RBRACKET();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ArrayTypeContext* arrayType();

  class  ArrayDeclarationTypeSizeContext : public antlr4::ParserRuleContext {
  public:
    ArrayDeclarationTypeSizeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpressionContext *expression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ArrayDeclarationTypeSizeContext* arrayDeclarationTypeSize();

  class  ArrayDataTypeContext : public antlr4::ParserRuleContext {
  public:
    ArrayDataTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *INTEGER_TYPES();
    antlr4::tree::TerminalNode *UNSIGNED_INTEGER_TYPES();
    antlr4::tree::TerminalNode *FLOAT_TYPES();
    antlr4::tree::TerminalNode *BOOLEAN_TYPES();
    antlr4::tree::TerminalNode *STRING_TYPES();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ArrayDataTypeContext* arrayDataType();


  bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;

  bool binaryExpressionSempred(BinaryExpressionContext *_localctx, size_t predicateIndex);

  // By default the static state used to implement the parser is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:
};

