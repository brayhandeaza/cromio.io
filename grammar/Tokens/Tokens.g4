lexer grammar Tokens;

import StringTokens;

// ------------------------------------------------------------
// BASIC TOKENS
// ------------------------------------------------------------
NONE: 'none';
BOOLEAN: 'true' | 'false';
NEWLINE: [\r\n]+;
PLUS: '+';
MINUS: '-';
MUL: '*';
DIV: '/';
EQ: '=';
LPAREN: '(';
RPAREN: ')';
LBRACE: '{';
RBRACE: '}';
WS: [ \t]+ -> skip;

// ------------------------------------------------------------
// NORMAL STRINGS
// ------------------------------------------------------------
STRING:
      '"'  (ESC_SEQ | ~["\\\r\n])* '"'
    | '\'' (ESC_SEQ | ~['\\\r\n])* '\''
    | '"""' ( ~["] | '"' ~["] | '""' ~["])* '"""'
;

// ------------------------------------------------------------
// FORMATTED STRING START (ENTER MODE)
// ------------------------------------------------------------
FORMATTED_STRING_START
    : 'f"' -> pushMode(FormattedStringMode)
    ;

// ------------------------------------------------------------
// NUMBERS AND IDENTIFIERS
// ------------------------------------------------------------
fragment DIGIT: [0-9];
fragment HEX_DIGIT: [0-9a-fA-F];
fragment EXPONENT: [eE] [+-]? DIGIT+;
fragment ESC_SEQ: '\\' ['"\\/bfnrt] | '\\u' HEX_DIGIT HEX_DIGIT HEX_DIGIT HEX_DIGIT;

FLOAT: ('+' | '-')? (
    DIGIT+ ('_'? DIGIT+)* '.' DIGIT* ('_'? DIGIT+)* EXPONENT?
  | DIGIT* ('_'? DIGIT+)* '.' DIGIT+ ('_'? DIGIT+)* EXPONENT?
  | DIGIT+ ('_'? DIGIT+)* EXPONENT
);

INTEGER: ('+' | '-')? DIGIT+ ('_'? DIGIT+)*;

IDENTIFIER: [a-zA-Z_] [a-zA-Z_0-9]*;
