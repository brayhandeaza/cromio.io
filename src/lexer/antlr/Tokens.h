
// Generated from Tokens.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"




class  Tokens : public antlr4::Lexer {
public:
  enum {
    NONE = 1, BOOLEAN = 2, IDENTIFIER = 3, PLUS = 4, MINUS = 5, MUL = 6, 
    DIV = 7, EQ = 8, LPAREN = 9, RPAREN = 10, LBRACE = 11, RBRACE = 12, 
    NEWLINE = 13, WS = 14, FLOAT = 15, INTEGER = 16, STRING = 17, FORMATTED_STRING_START = 18, 
    FORMATTED_STRING_TEXT = 19, LBRACE_IN_FSTRING = 20, FORMATTED_STRING_END = 21, 
    RBRACE_IN_FSTRING = 22, EXPR_WS = 23
  };

  enum {
    FSTRING_MODE = 1, EXPR_MODE = 2
  };

  explicit Tokens(antlr4::CharStream *input);

  ~Tokens() override;


  std::string getGrammarFileName() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const std::vector<std::string>& getChannelNames() const override;

  const std::vector<std::string>& getModeNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;

  const antlr4::atn::ATN& getATN() const override;

  // By default the static state used to implement the lexer is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:

  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

};

