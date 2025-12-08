parser grammar DictionaryGrammar;

options {
    tokenVocab = Tokens;
}

import ExpressionsGrammar;

dictionaryDeclaration: DICT_KEYWORD LESSTHAN dictionaryDeclarationType GREATERTHAN IDENTIFIER EQ dictionaryAssignment;

dictionaryAssignment: LBRACE (dictionaryAssignmentBody (COMMA dictionaryAssignmentBody COMMA? )*)? RBRACE;

dictionaryAssignmentBody
    : literal COLON expression
    ;

dictionaryDeclarationType: dictionaryDataType COMMA dictionaryDataType;

dictionaryDataType: INTEGER_TYPES | UNSIGNED_INTEGER_TYPES | FLOAT_TYPES | BOOLEAN_TYPES | STRING_TYPES;


