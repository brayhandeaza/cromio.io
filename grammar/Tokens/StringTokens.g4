lexer grammar StringTokens;

import Tokens, IntegerTokens;

// ------------------------------
// Start f-string
// ------------------------------
FORMATTED_STRING_START
    : 'f"' -> pushMode(FSTRING_MODE)
    ;

// ------------------------------
// F-STRING MODE
// ------------------------------
mode FSTRING_MODE;

// NOTE: CLOSING BRACE — first rule!
RBRACE_IN_FSTRING
    : '}' -> pushMode(FSTRING_MODE)
    ;

// OPEN BRACE — EXIT FSTRING MODE
LBRACE_IN_FSTRING
    : '{' -> popMode
    ;

// RAW TEXT
FORMATTED_STRING_TEXT
    : ( ESC_SEQ | ~["\\{}] )+
    ;

// END QUOTE OF F-STRING
FORMATTED_STRING_END
    : '"' -> popMode
    ;

// escape sequences
fragment ESC_SEQ
    : '\\' .
    ;

// ------------------------------
// Normal strings (outside f-string)
// ------------------------------
STRING
    : '"'  (ESC_SEQ | ~["\\\r\n])* '"'
    | '\'' (ESC_SEQ | ~['\\\r\n])* '\''
    | '"""' ( ~["] | '"' ~["] | '""' ~["])* '"""'
    ;
