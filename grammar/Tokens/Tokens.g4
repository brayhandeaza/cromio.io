lexer grammar Tokens;

// ==============================
// DEFAULT MODE (root)
// ==============================

NONE: 'none';
BOOLEAN: 'true' | 'false';
IDENTIFIER: [a-zA-Z_] [a-zA-Z_0-9]*;

PLUS: '+';
MINUS: '-';
MUL: '*';
DIV: '/';
EQ: '=';

LPAREN: '(';
RPAREN: ')';
LBRACE: '{';
RBRACE: '}';

NEWLINE: [\r\n]+ -> skip;
WS: [ \t]+ -> skip;


// -----------------------------------------
// NORMAL STRING
// -----------------------------------------
STRING
    : '"' (ESC_SEQ | ~["\\\r\n])* '"'
    ;

// -----------------------------------------
// F-STRING START
// -----------------------------------------
FORMATTED_STRING_START
    : 'f"' -> pushMode(FSTRING_MODE)
    ;

// =========================================
// FSTRING_MODE
// =========================================
mode FSTRING_MODE;

// any text until { or end quote
FORMATTED_STRING_TEXT
    : ( ESC_SEQ | ~["\\{}] )+
    ;

// enter expression mode
LBRACE_IN_FSTRING
    : '{' -> pushMode(EXPR_MODE)
    ;

// end of f-string
FORMATTED_STRING_END
    : '"' -> popMode
    ;


// =========================================
// EXPR_MODE — expression inside f-string
// =========================================
mode EXPR_MODE;

// finish the expression and return to f-string
RBRACE_IN_FSTRING
    : '}' -> popMode
    ;

// operators mapped to global token names
PLUS_IN_EXPR    : '+' -> type(PLUS);
MINUS_IN_EXPR   : '-' -> type(MINUS);
MUL_IN_EXPR     : '*' -> type(MUL);
DIV_IN_EXPR     : '/' -> type(DIV);

LPAREN_IN_EXPR  : '(' -> type(LPAREN);
RPAREN_IN_EXPR  : ')' -> type(RPAREN);

// numeric literals mapped to real tokens
FLOAT_IN_EXPR
    : (DIGIT+ ('.' DIGIT*)? EXPONENT? | '.' DIGIT+ EXPONENT?) -> type(FLOAT)
    ;

INTEGER_IN_EXPR
    : DIGIT+ -> type(INTEGER)
    ;

// identifiers inside expression
ID_IN_EXPR
    : [a-zA-Z_] [a-zA-Z_0-9]* -> type(IDENTIFIER)
    ;

// strings inside expression
STRING_IN_EXPR
    : '"' (ESC_SEQ | ~["\\\r\n])* '"' -> type(STRING)
    ;

// skip whitespace
EXPR_WS: [ \t\r\n]+ -> skip;


// =========================================
// Fragments
// =========================================
fragment DIGIT      : [0-9];
fragment HEX_DIGIT  : [0-9a-fA-F];
fragment EXPONENT   : [eE] [+-]? DIGIT+;

fragment ESC_SEQ
    : '\\' ['"\\/bfnrt]
    | '\\u' HEX_DIGIT HEX_DIGIT HEX_DIGIT HEX_DIGIT
    ;

// =========================================
// GLOBAL numeric token definitions
// (DEFAULT_MODE only)
// =========================================
FLOAT
    : DIGIT+ ('.' DIGIT*)? EXPONENT?
    | '.' DIGIT+ EXPONENT?
    ;

INTEGER
    : DIGIT+
    ;
