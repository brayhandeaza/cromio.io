lexer grammar MainTokens;

// =======================================================================================================================================================
// MainTokens
// =======================================================================================================================================================


// Integer types
INTEGER_TYPES
    : 'int'
    | 'int8'
    | 'int16'
    | 'int32'
    | 'int64'
    ;

// Unsigned integer types
UNSIGNED_INTEGER_TYPES
    : 'uint'
    | 'uint8'
    | 'uint16'
    | 'uint32'
    | 'uint64'
    ;

FLOAT_TYPES
    : 'float'      // 32-bit
    | 'double'     // 64-bit
    ;


BOOLEAN_TYPES: 'bool';


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

