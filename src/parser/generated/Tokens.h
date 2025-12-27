
// Generated from Tokens.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"




class  Tokens : public antlr4::Lexer {
public:
  enum {
    REGEX_TYPE = 1, DICT_KEYWORD = 2, BOOLEAN_TYPES = 3, STRING_TYPES = 4, 
    INTEGER_TYPES = 5, UNSIGNED_INTEGER_TYPES = 6, FLOAT_TYPES = 7, NONE = 8, 
    BOOLEAN = 9, IDENTIFIER = 10, PLUS = 11, MINUS = 12, MUL = 13, DIV = 14, 
    MOD = 15, EQ = 16, LPAREN = 17, RPAREN = 18, LBRACE = 19, RBRACE = 20, 
    LBRACKET = 21, RBRACKET = 22, DOT = 23, COMMA = 24, AMPERSAND = 25, 
    LESSTHAN = 26, GREATERTHAN = 27, COLON = 28, NEWLINE = 29, NEWLINE_VISIBLE = 30, 
    WS_VISIBLE = 31, COMMENT = 32, BLOCK_COMMENT = 33, WS = 34, FLOAT = 35, 
    INTEGER = 36, STRING = 37, REGEX_START = 38, REGEX_CONTENT = 39, REGEX_END = 40, 
    FORMATTED_STRING_START = 41, FORMATTED_STRING_TEXT = 42, LBRACE_IN_FSTRING = 43, 
    FORMATTED_STRING_END = 44, RBRACE_IN_FSTRING = 45, EXPR_WS = 46
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

