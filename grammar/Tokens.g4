lexer grammar Tokens;


// ---- SINGLE ----
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
IDENTIFIER: [a-zA-Z_] [a-zA-Z_0-9]*;
WS: [ \t]+ -> skip;

// ---- FRAGMENTS ----
fragment DIGIT: [0-9];
fragment HEX_DIGIT: [0-9a-fA-F];
fragment EXPONENT: [eE] [+-]? DIGIT+;
fragment ESC_SEQ: '\\' ['"\\/bfnrt] | '\\u' HEX_DIGIT HEX_DIGIT HEX_DIGIT HEX_DIGIT;

// ---- COMPLEX ----
FLOAT: ('+' | '-')? (
    DIGIT+ ('_'? DIGIT+)* '.' DIGIT* ('_'? DIGIT+)* EXPONENT?
    | DIGIT* ('_'? DIGIT+)* '.' DIGIT+ ('_'? DIGIT+)* EXPONENT?
    | DIGIT+ ('_'? DIGIT+)* EXPONENT
    | '0' [xX] HEX_DIGIT+ ('_'? HEX_DIGIT+)* '.' HEX_DIGIT* ('_'? HEX_DIGIT+)* [pP] [+-]? DIGIT+
    | '0' [xX] HEX_DIGIT* ('_'? HEX_DIGIT+)* '.' HEX_DIGIT+ ('_'? HEX_DIGIT+)* [pP] [+-]? DIGIT+
);

INTEGER: ('+' | '-')? (
    '0' [xX] HEX_DIGIT+ ('_'? HEX_DIGIT+)*
    | '0' [bB] [01]+ ('_'? [01]+)*
    | '0' [oO] [0-7]+ ('_'? [0-7]+)*
    | DIGIT+ ('_'? DIGIT+)*
);

STRING: '"' (ESC_SEQ | ~["\\\r\n])* '"'
       | '\'' (ESC_SEQ | ~['\\\r\n])* '\''
       | '"""' ( ~["] | '"' ~["] | '""' ~["])* '"""';

mode FormattedStringMode;
FORMATTED_STRING_START: 'f"' -> pushMode(FormattedStringMode);
FORMATTED_STRING_END: '"' -> popMode;
FORMATTED_STRING_TEXT: (~["{])+;
