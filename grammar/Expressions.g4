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

formattedString: FORMATTED_STRING_START formattedStringContent* FORMATTED_STRING_END;
formattedStringContent: FORMATTED_STRING_TEXT | formattedStringExpression;
formattedStringExpression: LBRACE expression RBRACE;

integerLiteral: INTEGER;
floatLiteral: FLOAT;
stringLiteral: STRING;
booleanLiteral: BOOLEAN;
noneLiteral: NONE;