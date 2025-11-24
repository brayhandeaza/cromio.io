parser grammar Expressions;

options {
    tokenVocab = Tokens;
}

expression: literal
          | LPAREN expression RPAREN
          | expression MUL expression
          | expression DIV expression
          | expression PLUS expression
          | expression MINUS expression
          ;

literal: integerLiteral
       | floatLiteral
       | formattedString
       | stringLiteral
       | booleanLiteral
       | noneLiteral
       ;

formattedString
    : FORMATTED_STRING_START formattedStringContent* FORMATTED_STRING_END
    ;

formattedStringContent
    : FORMATTED_STRING_TEXT
    | LBRACE_IN_FSTRING expression RBRACE_IN_FSTRING
    ;

//formattedStringExpression: expression
//      | LPAREN expression RPAREN
//      | expression MUL expression
//      | expression DIV expression
//      | expression PLUS expression
//      | expression MINUS expression
//      ;

integerLiteral: INTEGER;
floatLiteral: FLOAT;
stringLiteral: STRING;
booleanLiteral: BOOLEAN;
noneLiteral: NONE;