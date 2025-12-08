parser grammar Grammar;

options {
    tokenVocab = Tokens;
}

// bandera que controlará qué hace el lexer
@parser::members {
    public:
        bool inVarMode = false;
        bool inSkipMode = false;
}

import DictionaryGrammar, VariableGrammar, ArraysGrammar,  LiteralsGrammar, ExpressionsGrammar;

program: NEWLINE* (statements NEWLINE*)* EOF;

statements
    :   variables
    |   arrayDeclaration
    |   dictionaryDeclaration
    |   expression
    ;