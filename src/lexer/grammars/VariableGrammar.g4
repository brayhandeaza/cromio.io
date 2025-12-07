parser grammar VariableGrammar;

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
    |   variableReAssignment
    |   variableAccessToMember
    |   arrayDeclaration
    ;

// --------------------------------------------------------------------
// ArrayDeclaration
// --------------------------------------------------------------------
arrayDeclaration: {inVarMode = true;} variableDataType LBRACKET arrayDeclarationTypeSize RBRACKET  {inVarMode = false;} IDENTIFIER EQ arrayAssignment ;

arrayAssignment: LBRACKET (expression (COMMA expression)*)? RBRACKET;

arrayDeclarationTypeSize: {inVarMode = false;} expression? {inVarMode = true;};

// --------------------------------------------------------------------
// VariableDeclaration
// --------------------------------------------------------------------
variableDeclaration: variableDataType IDENTIFIER EQ expression;

variableDeclarationWithoutAssignment: variableDataType IDENTIFIER;

variableReAssignment: IDENTIFIER EQ expression;

variableAccessToMember
    : {inVarMode = true;} IDENTIFIER DOT IDENTIFIER {inVarMode = false;};

variableDataType: INTEGER_TYPES | UNSIGNED_INTEGER_TYPES | FLOAT_TYPES | BOOLEAN_TYPES | STRING_TYPES;



