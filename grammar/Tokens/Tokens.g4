lexer grammar Tokens;

import StringTokens;

NONE: 'none';
BOOLEAN: 'true' | 'false';
IDENTIFIER: [a-zA-Z_] [a-zA-Z_0-9]*;
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

WS: [ \t]+ -> skip;
