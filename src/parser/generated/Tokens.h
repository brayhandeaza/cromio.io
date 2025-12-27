
// Generated from Tokens.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"




class  Tokens : public antlr4::Lexer {
public:
  enum {
    DICT_KEYWORD = 1, BOOLEAN_TYPES = 2, STRING_TYPES = 3, INTEGER_TYPES = 4, 
    UNSIGNED_INTEGER_TYPES = 5, FLOAT_TYPES = 6, NONE = 7, BOOLEAN = 8, 
    IDENTIFIER = 9, PLUS = 10, MINUS = 11, MUL = 12, DIV = 13, MOD = 14, 
    EQ = 15, LPAREN = 16, RPAREN = 17, LBRACE = 18, RBRACE = 19, LBRACKET = 20, 
    RBRACKET = 21, DOT = 22, COMMA = 23, AMPERSAND = 24, LESSTHAN = 25, 
    GREATERTHAN = 26, COLON = 27, NEWLINE = 28, NEWLINE_VISIBLE = 29, WS_VISIBLE = 30, 
    COMMENT = 31, BLOCK_COMMENT = 32, WS = 33, FLOAT = 34, INTEGER = 35, 
    STRING = 36, REGEX_START = 37, REGEX_CONTENT = 38, REGEX_END = 39, FORMATTED_STRING_START = 40, 
    FORMATTED_STRING_TEXT = 41, LBRACE_IN_FSTRING = 42, FORMATTED_STRING_END = 43, 
    RBRACE_IN_FSTRING = 44, EXPR_WS = 45
  };

  enum {
    REGEX_MODE = 1, FSTRING_MODE = 2, EXPR_MODE = 3
  };

  explicit Tokens(antlr4::CharStream *input);

  ~Tokens() override;


      bool* inSkipMode = nullptr;
      void setParserFlag(bool* flag) { inSkipMode = flag; }


  std::string getGrammarFileName() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const std::vector<std::string>& getChannelNames() const override;

  const std::vector<std::string>& getModeNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;

  const antlr4::atn::ATN& getATN() const override;

  void action(antlr4::RuleContext *context, size_t ruleIndex, size_t actionIndex) override;

  // By default the static state used to implement the lexer is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:

  // Individual action functions triggered by action() above.
  void NEWLINEAction(antlr4::RuleContext *context, size_t actionIndex);
  void WS_VISIBLEAction(antlr4::RuleContext *context, size_t actionIndex);

  // Individual semantic predicate functions triggered by sempred() above.

};

