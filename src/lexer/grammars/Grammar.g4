parser grammar Grammar;

options {
    tokenVocab = Tokens;
}

import VariableGrammar, LiteralsGrammar, ExpressionsGrammar;

program: NEWLINE* (statements NEWLINE*)* EOF;

statements
    : variables
    | expression
    ;