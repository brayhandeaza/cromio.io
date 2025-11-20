lexer grammar StringTokens;


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


// ============================================================
// ============= FORMATTED STRING MODE ========================
// ============================================================

mode FormattedStringMode;

// ------------------------------------------------------------
// End of formatted string -> exit mode
// ------------------------------------------------------------
FORMATTED_STRING_END
    : '"' -> popMode
    ;

// ------------------------------------------------------------
// Interpolation expression "{ ... }"
// ------------------------------------------------------------
LBRACE_IN_FSTRING
    : '{' -> type(LBRACE), popMode
    ;

// ------------------------------------------------------------
// Text inside the f-string (anything except { or ")
// ------------------------------------------------------------

FORMATTED_STRING_TEXT: ( ESC_SEQ | ~["\\{] )+ ;

// ------------------------------------------------------------
// Return to formatted-string mode after expression closes
// ------------------------------------------------------------
FormattedStringModeRBrace
    : '}' -> type(RBRACE), pushMode(FormattedStringMode)
    ;
