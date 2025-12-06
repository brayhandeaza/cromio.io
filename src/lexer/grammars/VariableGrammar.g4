parser grammar Variable;

options {
    tokenVocab = Tokens;
}

import ExpressionsGrammar;

// bandera que controlará qué hace el lexer
@parser::members {
    bool inVarMode = false;
}

variables
    :   variableDeclaration
    |   variableDeclarationWithoutAssignment
    |   variableAssignment
    |   variableAccessToMember
    ;

variableDeclaration: variableDataType variableAssignment;

variableDeclarationWithoutAssignment: variableDataType IDENTIFIER;

variableAssignment: IDENTIFIER EQ expression;

variableAccessToMember
    : {inVarMode = true;} IDENTIFIER DOT IDENTIFIER {inVarMode = false;};

variableDataType: INTEGER_TYPES | UNSIGNED_INTEGER_TYPES | FLOAT_TYPES | BOOLEAN_TYPES | STRING_TYPES;

