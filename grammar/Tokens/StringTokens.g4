lexer grammar StringTokens;

import Tokens, IntegerTokens;


STRING:
      '"'  (ESC_SEQ | ~["\\\r\n])* '"'
    | '\'' (ESC_SEQ | ~['\\\r\n])* '\''
    | '"""' ( ~["] | '"' ~["] | '""' ~["])* '"""'
;

FORMATTED_STRING_START
    : 'f"' -> pushMode(FormattedStringMode)
    ;

mode FormattedStringMode;

FORMATTED_STRING_END
    : '"' -> popMode
    ;

LBRACE_IN_FSTRING
    : '{' -> type(LBRACE), popMode
    ;

FORMATTED_STRING_TEXT: ( ESC_SEQ | ~["\\{] )+ ;

FormattedStringModeRBrace
    : '}' -> type(RBRACE), pushMode(FormattedStringMode)
    ;
