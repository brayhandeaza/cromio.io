parser grammar Grammar;

options {
    tokenVocab = Tokens;
}

import Expressions;

program: NEWLINE* (statement NEWLINE*)* EOF;

statement: expression;
