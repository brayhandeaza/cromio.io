parser grammar Grammar;

options {
    tokenVocab = Tokens;
}

import VariableGrammar, ExpressionsGrammar;

program: NEWLINE* (statement NEWLINE*)* EOF;

statement
    : variableDeclaration
    | expression
    ;