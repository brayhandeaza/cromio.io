lexer grammar MainTokens;

// --------------------------------------------------------------------
// FLAG compartida entre parser y lexer
// --------------------------------------------------------------------
@members {
    bool* inVarMode = nullptr;
    void setParserFlag(bool* flag) { inVarMode = flag; }
}


// =======================================================================================================================================================
// MainTokens
// =======================================================================================================================================================

// Boolean types
BOOLEAN_TYPES
    : 'bool'
    ;

STRING_TYPES
    : 'str'
    ;

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
    | 'float32'    // 34-bit
    | 'float64'    // 64-bit
    ;

NONE: 'none';
BOOLEAN: 'true' | 'false';

IDENTIFIER: [a-zA-Z_] [a-zA-Z_0-9]*;

PLUS: '+';
MINUS: '-';
MUL: '*';
DIV: '/';
MOD: '%';
EQ: '=';

LPAREN: '(';
RPAREN: ')';
LBRACE: '{';
RBRACE: '}';
DOT: '.';

// --------------------------------------------------------------------
// NEWLINE normal → skip
// --------------------------------------------------------------------
NEWLINE
    : [\r\n]+   { if (inVarMode && *inVarMode) emit(); else skip(); }
    ;


// NEWLINE visible
NEWLINE_VISIBLE
    : [\r\n]+
    ;

WS_VISIBLE: [ \t]+ { if (inVarMode && *inVarMode) emit(); else skip(); };


WS: [ \t]+ -> skip;

