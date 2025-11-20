lexer grammar IntegerTokens;


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
