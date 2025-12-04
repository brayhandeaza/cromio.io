parser grammar Variable;

options {
    tokenVocab = Tokens;
}

import ExpressionsGrammar;


variableDeclaration: variableDataType variableAssignment;

variableDeclarationWithoutAssignment
    : variableDataType IDENTIFIER
    ;

variableAssignment: IDENTIFIER EQ expression;




variableDataType: INTEGER_TYPES | UNSIGNED_INTEGER_TYPES | FLOAT_TYPES | BOOLEAN_TYPES | STRING_TYPES;

