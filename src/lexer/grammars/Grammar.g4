parser grammar Grammar;

options {
    tokenVocab = Tokens;
}

import VariableGrammar, ExpressionsGrammar;

program: NEWLINE* (statements NEWLINE*)* EOF;

statements
    : variables
    | expression
    ;