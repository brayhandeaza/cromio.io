parser grammar ArraysGrammar;

options {
    tokenVocab = Tokens;
}

import VariableGrammar, ExpressionsGrammar;

arrayDeclaration: {inSkipMode = true;} variableDataType LBRACKET arrayDeclarationTypeSize RBRACKET  {inSkipMode = false;} IDENTIFIER EQ LBRACKET (expression (COMMA expression)*)? RBRACKET;

arrayDeclarationTypeSize: {inSkipMode = false;} expression? {inSkipMode = true;};



