lexer grammar NumberTokens;

// =======================================================================================================================================================
// NumberTokens
// =======================================================================================================================================================

// float
FLOAT
    : [+-]? DIGIT+ '.' DIGIT*
    | [+-]? DIGIT+ '.' DIGIT* EXPONENT?
    | '.' DIGIT+ EXPONENT?
    ;

FLOAT_UNDERSCORE_EXPONENT
    : DIGIT+ (UNDERSCORE? DIGIT)* '.' DIGIT* (UNDERSCORE? DIGIT)* EXPONENT? -> type(FLOAT)
    ;


// integer
INTEGER
    : DIGIT+ // Decimal
    | [+-]? '0x' HEX_DIGIT+ // Hexadecimal
    | [+-]? '0o' OCT_DIGIT+ // Octal
    | [+-]? '0b' BINARY_DIGIT+ // Binary
    | [+-]? DIGIT+  EXPONENT?
    | DIGIT+ (UNDERSCORE? DIGIT)*
    ;


