lexer grammar IntegerTokens;

// =========================================
// GLOBAL numeric literal tokens
// =========================================
FLOAT
    : DIGIT+ '.' DIGIT* EXPONENT?
    | '.' DIGIT+ EXPONENT?
    ;

INTEGER
    : DIGIT+
    ;


