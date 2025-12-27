
// Generated from Grammar.g4 by ANTLR 4.13.2


#include "GrammarListener.h"
#include "GrammarVisitor.h"

#include "Grammar.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct GrammarStaticData final {
  GrammarStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  GrammarStaticData(const GrammarStaticData&) = delete;
  GrammarStaticData(GrammarStaticData&&) = delete;
  GrammarStaticData& operator=(const GrammarStaticData&) = delete;
  GrammarStaticData& operator=(GrammarStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag grammarParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
std::unique_ptr<GrammarStaticData> grammarParserStaticData = nullptr;

void grammarParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (grammarParserStaticData != nullptr) {
    return;
  }
#else
  assert(grammarParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<GrammarStaticData>(
    std::vector<std::string>{
      "program", "statements", "dictionaryDeclaration", "dictionaryAssignmentBody", 
      "dictionaryDeclarationType", "dictionaryTypeElement", "dictionaryDeclarationTypeArray", 
      "dictionaryDataType", "expression", "concatenationExpression", "binaryExpression", 
      "literal", "numberLiterals", "stringLiterals", "formattedString", 
      "formattedStringContent", "stringLiteral", "integerLiteral", "floatLiteral", 
      "booleanLiteral", "noneLiteral", "identifierLiteral", "memberExpression", 
      "valuePostfix", "argumentList", "valueAtom", "variables", "variableDeclaration", 
      "variableDeclarationWithoutAssignment", "variableReAssignment", "variableDataType", 
      "arrays", "arrayDeclaration", "arrayValues", "arrayItemsWithBrackets", 
      "arrayItems", "arrayReAssignment", "arrayType", "arrayDeclarationTypeSize", 
      "arrayDataType"
    },
    std::vector<std::string>{
      "", "'regex'", "'dict'", "'bool'", "'str'", "", "", "", "", "", "", 
      "", "", "", "", "'%'", "'='", "", "", "", "", "'['", "']'", "'.'", 
      "','", "'&'", "'<'", "'>'", "':'", "", "", "", "", "", "", "", "", 
      "", "", "", "", "", "'\"'"
    },
    std::vector<std::string>{
      "", "REGEX_TYPE", "DICT_KEYWORD", "BOOLEAN_TYPES", "STRING_TYPES", 
      "INTEGER_TYPES", "UNSIGNED_INTEGER_TYPES", "FLOAT_TYPES", "NONE", 
      "BOOLEAN", "IDENTIFIER", "PLUS", "MINUS", "MUL", "DIV", "MOD", "EQ", 
      "LPAREN", "RPAREN", "LBRACE", "RBRACE", "LBRACKET", "RBRACKET", "DOT", 
      "COMMA", "AMPERSAND", "LESSTHAN", "GREATERTHAN", "COLON", "NEWLINE", 
      "NEWLINE_VISIBLE", "WS_VISIBLE", "COMMENT", "BLOCK_COMMENT", "WS", 
      "FLOAT", "INTEGER", "STRING", "FORMATTED_STRING_START", "FORMATTED_STRING_TEXT", 
      "REGEX_LITERAL", "LBRACE_IN_FSTRING", "FORMATTED_STRING_END", "RBRACE_IN_FSTRING", 
      "EXPR_WS"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,44,377,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,7,
  	28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,2,33,7,33,2,34,7,34,2,35,7,
  	35,2,36,7,36,2,37,7,37,2,38,7,38,2,39,7,39,1,0,5,0,82,8,0,10,0,12,0,85,
  	9,0,1,0,1,0,5,0,89,8,0,10,0,12,0,92,9,0,5,0,94,8,0,10,0,12,0,97,9,0,1,
  	0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,3,1,108,8,1,1,2,1,2,1,2,1,2,1,2,1,2,
  	1,2,1,2,1,2,1,2,1,2,3,2,121,8,2,5,2,123,8,2,10,2,12,2,126,9,2,3,2,128,
  	8,2,1,2,1,2,1,3,1,3,1,3,1,3,1,4,1,4,1,4,1,4,1,5,1,5,3,5,142,8,5,1,6,1,
  	6,1,6,3,6,147,8,6,1,6,1,6,1,7,1,7,1,8,1,8,1,8,1,8,1,8,1,8,3,8,159,8,8,
  	1,9,1,9,3,9,163,8,9,1,9,1,9,1,9,3,9,168,8,9,5,9,170,8,9,10,9,12,9,173,
  	9,9,4,9,175,8,9,11,9,12,9,176,1,10,1,10,1,10,1,10,1,10,1,10,1,10,3,10,
  	186,8,10,1,10,1,10,1,10,1,10,1,10,1,10,5,10,194,8,10,10,10,12,10,197,
  	9,10,1,11,1,11,1,11,1,11,3,11,203,8,11,1,12,1,12,3,12,207,8,12,1,13,1,
  	13,1,13,3,13,212,8,13,1,14,1,14,5,14,216,8,14,10,14,12,14,219,9,14,1,
  	14,1,14,1,15,1,15,1,15,1,15,1,15,1,15,3,15,229,8,15,1,16,1,16,1,17,1,
  	17,1,18,1,18,1,19,1,19,1,20,1,20,1,21,1,21,1,22,1,22,5,22,245,8,22,10,
  	22,12,22,248,9,22,1,23,1,23,1,23,1,23,3,23,254,8,23,1,23,3,23,257,8,23,
  	1,24,1,24,1,24,5,24,262,8,24,10,24,12,24,265,9,24,1,25,1,25,1,25,1,25,
  	1,25,1,25,1,25,1,25,1,25,1,25,1,25,1,25,1,25,1,25,3,25,281,8,25,1,26,
  	1,26,1,26,3,26,286,8,26,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,28,1,28,
  	1,28,1,29,1,29,1,29,1,29,1,30,1,30,1,31,1,31,3,31,306,8,31,1,32,1,32,
  	1,32,1,32,1,32,1,32,1,32,1,33,1,33,5,33,317,8,33,10,33,12,33,320,9,33,
  	1,33,3,33,323,8,33,1,34,1,34,1,34,1,34,5,34,329,8,34,10,34,12,34,332,
  	9,34,3,34,334,8,34,1,34,1,34,1,35,1,35,1,35,1,35,1,35,1,35,1,35,1,35,
  	1,35,3,35,347,8,35,1,36,1,36,1,36,1,36,1,36,1,36,5,36,355,8,36,10,36,
  	12,36,358,9,36,3,36,360,8,36,1,36,1,36,1,37,1,37,1,37,1,37,1,37,1,38,
  	1,38,3,38,371,8,38,1,38,1,38,1,39,1,39,1,39,0,1,20,40,0,2,4,6,8,10,12,
  	14,16,18,20,22,24,26,28,30,32,34,36,38,40,42,44,46,48,50,52,54,56,58,
  	60,62,64,66,68,70,72,74,76,78,0,4,1,0,3,7,1,0,13,15,1,0,11,12,2,0,1,1,
  	3,7,399,0,83,1,0,0,0,2,107,1,0,0,0,4,109,1,0,0,0,6,131,1,0,0,0,8,135,
  	1,0,0,0,10,141,1,0,0,0,12,143,1,0,0,0,14,150,1,0,0,0,16,158,1,0,0,0,18,
  	174,1,0,0,0,20,185,1,0,0,0,22,202,1,0,0,0,24,206,1,0,0,0,26,211,1,0,0,
  	0,28,213,1,0,0,0,30,228,1,0,0,0,32,230,1,0,0,0,34,232,1,0,0,0,36,234,
  	1,0,0,0,38,236,1,0,0,0,40,238,1,0,0,0,42,240,1,0,0,0,44,242,1,0,0,0,46,
  	256,1,0,0,0,48,258,1,0,0,0,50,280,1,0,0,0,52,285,1,0,0,0,54,287,1,0,0,
  	0,56,294,1,0,0,0,58,297,1,0,0,0,60,301,1,0,0,0,62,305,1,0,0,0,64,307,
  	1,0,0,0,66,322,1,0,0,0,68,324,1,0,0,0,70,346,1,0,0,0,72,348,1,0,0,0,74,
  	363,1,0,0,0,76,368,1,0,0,0,78,374,1,0,0,0,80,82,5,29,0,0,81,80,1,0,0,
  	0,82,85,1,0,0,0,83,81,1,0,0,0,83,84,1,0,0,0,84,95,1,0,0,0,85,83,1,0,0,
  	0,86,90,3,2,1,0,87,89,5,29,0,0,88,87,1,0,0,0,89,92,1,0,0,0,90,88,1,0,
  	0,0,90,91,1,0,0,0,91,94,1,0,0,0,92,90,1,0,0,0,93,86,1,0,0,0,94,97,1,0,
  	0,0,95,93,1,0,0,0,95,96,1,0,0,0,96,98,1,0,0,0,97,95,1,0,0,0,98,99,5,0,
  	0,1,99,1,1,0,0,0,100,108,3,16,8,0,101,108,3,52,26,0,102,108,3,62,31,0,
  	103,108,3,4,2,0,104,108,3,44,22,0,105,108,3,38,19,0,106,108,3,40,20,0,
  	107,100,1,0,0,0,107,101,1,0,0,0,107,102,1,0,0,0,107,103,1,0,0,0,107,104,
  	1,0,0,0,107,105,1,0,0,0,107,106,1,0,0,0,108,3,1,0,0,0,109,110,5,2,0,0,
  	110,111,5,26,0,0,111,112,3,8,4,0,112,113,5,27,0,0,113,114,5,10,0,0,114,
  	115,5,16,0,0,115,127,5,19,0,0,116,124,3,6,3,0,117,118,5,24,0,0,118,120,
  	3,6,3,0,119,121,5,24,0,0,120,119,1,0,0,0,120,121,1,0,0,0,121,123,1,0,
  	0,0,122,117,1,0,0,0,123,126,1,0,0,0,124,122,1,0,0,0,124,125,1,0,0,0,125,
  	128,1,0,0,0,126,124,1,0,0,0,127,116,1,0,0,0,127,128,1,0,0,0,128,129,1,
  	0,0,0,129,130,5,20,0,0,130,5,1,0,0,0,131,132,3,22,11,0,132,133,5,28,0,
  	0,133,134,3,16,8,0,134,7,1,0,0,0,135,136,3,10,5,0,136,137,5,24,0,0,137,
  	138,3,10,5,0,138,9,1,0,0,0,139,142,3,12,6,0,140,142,3,14,7,0,141,139,
  	1,0,0,0,141,140,1,0,0,0,142,11,1,0,0,0,143,144,3,14,7,0,144,146,5,21,
  	0,0,145,147,3,16,8,0,146,145,1,0,0,0,146,147,1,0,0,0,147,148,1,0,0,0,
  	148,149,5,22,0,0,149,13,1,0,0,0,150,151,7,0,0,0,151,15,1,0,0,0,152,159,
  	3,38,19,0,153,159,3,24,12,0,154,159,3,20,10,0,155,159,3,18,9,0,156,159,
  	3,42,21,0,157,159,3,44,22,0,158,152,1,0,0,0,158,153,1,0,0,0,158,154,1,
  	0,0,0,158,155,1,0,0,0,158,156,1,0,0,0,158,157,1,0,0,0,159,17,1,0,0,0,
  	160,163,3,26,13,0,161,163,3,42,21,0,162,160,1,0,0,0,162,161,1,0,0,0,163,
  	171,1,0,0,0,164,167,5,11,0,0,165,168,3,26,13,0,166,168,3,42,21,0,167,
  	165,1,0,0,0,167,166,1,0,0,0,168,170,1,0,0,0,169,164,1,0,0,0,170,173,1,
  	0,0,0,171,169,1,0,0,0,171,172,1,0,0,0,172,175,1,0,0,0,173,171,1,0,0,0,
  	174,162,1,0,0,0,175,176,1,0,0,0,176,174,1,0,0,0,176,177,1,0,0,0,177,19,
  	1,0,0,0,178,179,6,10,-1,0,179,186,3,24,12,0,180,186,3,42,21,0,181,182,
  	5,17,0,0,182,183,3,20,10,0,183,184,5,18,0,0,184,186,1,0,0,0,185,178,1,
  	0,0,0,185,180,1,0,0,0,185,181,1,0,0,0,186,195,1,0,0,0,187,188,10,2,0,
  	0,188,189,7,1,0,0,189,194,3,20,10,3,190,191,10,1,0,0,191,192,7,2,0,0,
  	192,194,3,20,10,2,193,187,1,0,0,0,193,190,1,0,0,0,194,197,1,0,0,0,195,
  	193,1,0,0,0,195,196,1,0,0,0,196,21,1,0,0,0,197,195,1,0,0,0,198,203,3,
  	24,12,0,199,203,3,26,13,0,200,203,3,38,19,0,201,203,3,42,21,0,202,198,
  	1,0,0,0,202,199,1,0,0,0,202,200,1,0,0,0,202,201,1,0,0,0,203,23,1,0,0,
  	0,204,207,3,34,17,0,205,207,3,36,18,0,206,204,1,0,0,0,206,205,1,0,0,0,
  	207,25,1,0,0,0,208,212,3,32,16,0,209,212,3,28,14,0,210,212,3,42,21,0,
  	211,208,1,0,0,0,211,209,1,0,0,0,211,210,1,0,0,0,212,27,1,0,0,0,213,217,
  	5,38,0,0,214,216,3,30,15,0,215,214,1,0,0,0,216,219,1,0,0,0,217,215,1,
  	0,0,0,217,218,1,0,0,0,218,220,1,0,0,0,219,217,1,0,0,0,220,221,5,42,0,
  	0,221,29,1,0,0,0,222,229,5,40,0,0,223,229,5,39,0,0,224,225,5,41,0,0,225,
  	226,3,16,8,0,226,227,5,43,0,0,227,229,1,0,0,0,228,222,1,0,0,0,228,223,
  	1,0,0,0,228,224,1,0,0,0,229,31,1,0,0,0,230,231,5,37,0,0,231,33,1,0,0,
  	0,232,233,5,36,0,0,233,35,1,0,0,0,234,235,5,35,0,0,235,37,1,0,0,0,236,
  	237,5,9,0,0,237,39,1,0,0,0,238,239,5,8,0,0,239,41,1,0,0,0,240,241,5,10,
  	0,0,241,43,1,0,0,0,242,246,3,50,25,0,243,245,3,46,23,0,244,243,1,0,0,
  	0,245,248,1,0,0,0,246,244,1,0,0,0,246,247,1,0,0,0,247,45,1,0,0,0,248,
  	246,1,0,0,0,249,250,5,23,0,0,250,257,3,42,21,0,251,253,5,17,0,0,252,254,
  	3,48,24,0,253,252,1,0,0,0,253,254,1,0,0,0,254,255,1,0,0,0,255,257,5,18,
  	0,0,256,249,1,0,0,0,256,251,1,0,0,0,257,47,1,0,0,0,258,263,3,16,8,0,259,
  	260,5,24,0,0,260,262,3,16,8,0,261,259,1,0,0,0,262,265,1,0,0,0,263,261,
  	1,0,0,0,263,264,1,0,0,0,264,49,1,0,0,0,265,263,1,0,0,0,266,281,3,42,21,
  	0,267,281,3,32,16,0,268,269,5,17,0,0,269,270,3,38,19,0,270,271,5,18,0,
  	0,271,281,1,0,0,0,272,273,5,17,0,0,273,274,3,24,12,0,274,275,5,18,0,0,
  	275,281,1,0,0,0,276,277,5,17,0,0,277,278,3,16,8,0,278,279,5,18,0,0,279,
  	281,1,0,0,0,280,266,1,0,0,0,280,267,1,0,0,0,280,268,1,0,0,0,280,272,1,
  	0,0,0,280,276,1,0,0,0,281,51,1,0,0,0,282,286,3,54,27,0,283,286,3,56,28,
  	0,284,286,3,58,29,0,285,282,1,0,0,0,285,283,1,0,0,0,285,284,1,0,0,0,286,
  	53,1,0,0,0,287,288,3,60,30,0,288,289,5,10,0,0,289,290,5,16,0,0,290,291,
  	6,27,-1,0,291,292,3,16,8,0,292,293,6,27,-1,0,293,55,1,0,0,0,294,295,3,
  	60,30,0,295,296,5,10,0,0,296,57,1,0,0,0,297,298,5,10,0,0,298,299,5,16,
  	0,0,299,300,3,16,8,0,300,59,1,0,0,0,301,302,7,3,0,0,302,61,1,0,0,0,303,
  	306,3,64,32,0,304,306,3,72,36,0,305,303,1,0,0,0,305,304,1,0,0,0,306,63,
  	1,0,0,0,307,308,6,32,-1,0,308,309,3,74,37,0,309,310,6,32,-1,0,310,311,
  	5,10,0,0,311,312,5,16,0,0,312,313,3,66,33,0,313,65,1,0,0,0,314,323,3,
  	68,34,0,315,317,3,16,8,0,316,315,1,0,0,0,317,320,1,0,0,0,318,316,1,0,
  	0,0,318,319,1,0,0,0,319,323,1,0,0,0,320,318,1,0,0,0,321,323,3,44,22,0,
  	322,314,1,0,0,0,322,318,1,0,0,0,322,321,1,0,0,0,323,67,1,0,0,0,324,333,
  	5,21,0,0,325,330,3,16,8,0,326,327,5,24,0,0,327,329,3,16,8,0,328,326,1,
  	0,0,0,329,332,1,0,0,0,330,328,1,0,0,0,330,331,1,0,0,0,331,334,1,0,0,0,
  	332,330,1,0,0,0,333,325,1,0,0,0,333,334,1,0,0,0,334,335,1,0,0,0,335,336,
  	5,22,0,0,336,69,1,0,0,0,337,347,3,32,16,0,338,347,3,28,14,0,339,347,3,
  	42,21,0,340,347,3,34,17,0,341,347,3,36,18,0,342,347,3,38,19,0,343,347,
  	3,40,20,0,344,347,3,18,9,0,345,347,3,20,10,0,346,337,1,0,0,0,346,338,
  	1,0,0,0,346,339,1,0,0,0,346,340,1,0,0,0,346,341,1,0,0,0,346,342,1,0,0,
  	0,346,343,1,0,0,0,346,344,1,0,0,0,346,345,1,0,0,0,347,71,1,0,0,0,348,
  	349,5,10,0,0,349,350,5,16,0,0,350,359,5,21,0,0,351,356,3,16,8,0,352,353,
  	5,24,0,0,353,355,3,16,8,0,354,352,1,0,0,0,355,358,1,0,0,0,356,354,1,0,
  	0,0,356,357,1,0,0,0,357,360,1,0,0,0,358,356,1,0,0,0,359,351,1,0,0,0,359,
  	360,1,0,0,0,360,361,1,0,0,0,361,362,5,22,0,0,362,73,1,0,0,0,363,364,3,
  	78,39,0,364,365,5,21,0,0,365,366,3,76,38,0,366,367,5,22,0,0,367,75,1,
  	0,0,0,368,370,6,38,-1,0,369,371,3,16,8,0,370,369,1,0,0,0,370,371,1,0,
  	0,0,371,372,1,0,0,0,372,373,6,38,-1,0,373,77,1,0,0,0,374,375,7,0,0,0,
  	375,79,1,0,0,0,37,83,90,95,107,120,124,127,141,146,158,162,167,171,176,
  	185,193,195,202,206,211,217,228,246,253,256,263,280,285,305,318,322,330,
  	333,346,356,359,370
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  grammarParserStaticData = std::move(staticData);
}

}

Grammar::Grammar(TokenStream *input) : Grammar(input, antlr4::atn::ParserATNSimulatorOptions()) {}

Grammar::Grammar(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  Grammar::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *grammarParserStaticData->atn, grammarParserStaticData->decisionToDFA, grammarParserStaticData->sharedContextCache, options);
}

Grammar::~Grammar() {
  delete _interpreter;
}

const atn::ATN& Grammar::getATN() const {
  return *grammarParserStaticData->atn;
}

std::string Grammar::getGrammarFileName() const {
  return "Grammar.g4";
}

const std::vector<std::string>& Grammar::getRuleNames() const {
  return grammarParserStaticData->ruleNames;
}

const dfa::Vocabulary& Grammar::getVocabulary() const {
  return grammarParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView Grammar::getSerializedATN() const {
  return grammarParserStaticData->serializedATN;
}


//----------------- ProgramContext ------------------------------------------------------------------

Grammar::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Grammar::ProgramContext::EOF() {
  return getToken(Grammar::EOF, 0);
}

std::vector<tree::TerminalNode *> Grammar::ProgramContext::NEWLINE() {
  return getTokens(Grammar::NEWLINE);
}

tree::TerminalNode* Grammar::ProgramContext::NEWLINE(size_t i) {
  return getToken(Grammar::NEWLINE, i);
}

std::vector<Grammar::StatementsContext *> Grammar::ProgramContext::statements() {
  return getRuleContexts<Grammar::StatementsContext>();
}

Grammar::StatementsContext* Grammar::ProgramContext::statements(size_t i) {
  return getRuleContext<Grammar::StatementsContext>(i);
}


size_t Grammar::ProgramContext::getRuleIndex() const {
  return Grammar::RuleProgram;
}

void Grammar::ProgramContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProgram(this);
}

void Grammar::ProgramContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProgram(this);
}


std::any Grammar::ProgramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GrammarVisitor*>(visitor))
    return parserVisitor->visitProgram(this);
  else
    return visitor->visitChildren(this);
}

Grammar::ProgramContext* Grammar::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 0, Grammar::RuleProgram);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(83);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == Grammar::NEWLINE) {
      setState(80);
      match(Grammar::NEWLINE);
      setState(85);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(95);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 515396208638) != 0)) {
      setState(86);
      statements();
      setState(90);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == Grammar::NEWLINE) {
        setState(87);
        match(Grammar::NEWLINE);
        setState(92);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(97);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(98);
    match(Grammar::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementsContext ------------------------------------------------------------------

Grammar::StatementsContext::StatementsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

Grammar::ExpressionContext* Grammar::StatementsContext::expression() {
  return getRuleContext<Grammar::ExpressionContext>(0);
}

Grammar::VariablesContext* Grammar::StatementsContext::variables() {
  return getRuleContext<Grammar::VariablesContext>(0);
}

Grammar::ArraysContext* Grammar::StatementsContext::arrays() {
  return getRuleContext<Grammar::ArraysContext>(0);
}

Grammar::DictionaryDeclarationContext* Grammar::StatementsContext::dictionaryDeclaration() {
  return getRuleContext<Grammar::DictionaryDeclarationContext>(0);
}

Grammar::MemberExpressionContext* Grammar::StatementsContext::memberExpression() {
  return getRuleContext<Grammar::MemberExpressionContext>(0);
}

Grammar::BooleanLiteralContext* Grammar::StatementsContext::booleanLiteral() {
  return getRuleContext<Grammar::BooleanLiteralContext>(0);
}

Grammar::NoneLiteralContext* Grammar::StatementsContext::noneLiteral() {
  return getRuleContext<Grammar::NoneLiteralContext>(0);
}


size_t Grammar::StatementsContext::getRuleIndex() const {
  return Grammar::RuleStatements;
}

void Grammar::StatementsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatements(this);
}

void Grammar::StatementsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatements(this);
}


std::any Grammar::StatementsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GrammarVisitor*>(visitor))
    return parserVisitor->visitStatements(this);
  else
    return visitor->visitChildren(this);
}

Grammar::StatementsContext* Grammar::statements() {
  StatementsContext *_localctx = _tracker.createInstance<StatementsContext>(_ctx, getState());
  enterRule(_localctx, 2, Grammar::RuleStatements);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(107);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(100);
      expression();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(101);
      variables();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(102);
      arrays();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(103);
      dictionaryDeclaration();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(104);
      memberExpression();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(105);
      booleanLiteral();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(106);
      noneLiteral();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DictionaryDeclarationContext ------------------------------------------------------------------

Grammar::DictionaryDeclarationContext::DictionaryDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Grammar::DictionaryDeclarationContext::DICT_KEYWORD() {
  return getToken(Grammar::DICT_KEYWORD, 0);
}

tree::TerminalNode* Grammar::DictionaryDeclarationContext::LESSTHAN() {
  return getToken(Grammar::LESSTHAN, 0);
}

Grammar::DictionaryDeclarationTypeContext* Grammar::DictionaryDeclarationContext::dictionaryDeclarationType() {
  return getRuleContext<Grammar::DictionaryDeclarationTypeContext>(0);
}

tree::TerminalNode* Grammar::DictionaryDeclarationContext::GREATERTHAN() {
  return getToken(Grammar::GREATERTHAN, 0);
}

tree::TerminalNode* Grammar::DictionaryDeclarationContext::IDENTIFIER() {
  return getToken(Grammar::IDENTIFIER, 0);
}

tree::TerminalNode* Grammar::DictionaryDeclarationContext::EQ() {
  return getToken(Grammar::EQ, 0);
}

tree::TerminalNode* Grammar::DictionaryDeclarationContext::LBRACE() {
  return getToken(Grammar::LBRACE, 0);
}

tree::TerminalNode* Grammar::DictionaryDeclarationContext::RBRACE() {
  return getToken(Grammar::RBRACE, 0);
}

std::vector<Grammar::DictionaryAssignmentBodyContext *> Grammar::DictionaryDeclarationContext::dictionaryAssignmentBody() {
  return getRuleContexts<Grammar::DictionaryAssignmentBodyContext>();
}

Grammar::DictionaryAssignmentBodyContext* Grammar::DictionaryDeclarationContext::dictionaryAssignmentBody(size_t i) {
  return getRuleContext<Grammar::DictionaryAssignmentBodyContext>(i);
}

std::vector<tree::TerminalNode *> Grammar::DictionaryDeclarationContext::COMMA() {
  return getTokens(Grammar::COMMA);
}

tree::TerminalNode* Grammar::DictionaryDeclarationContext::COMMA(size_t i) {
  return getToken(Grammar::COMMA, i);
}


size_t Grammar::DictionaryDeclarationContext::getRuleIndex() const {
  return Grammar::RuleDictionaryDeclaration;
}

void Grammar::DictionaryDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDictionaryDeclaration(this);
}

void Grammar::DictionaryDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDictionaryDeclaration(this);
}


std::any Grammar::DictionaryDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GrammarVisitor*>(visitor))
    return parserVisitor->visitDictionaryDeclaration(this);
  else
    return visitor->visitChildren(this);
}

Grammar::DictionaryDeclarationContext* Grammar::dictionaryDeclaration() {
  DictionaryDeclarationContext *_localctx = _tracker.createInstance<DictionaryDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 4, Grammar::RuleDictionaryDeclaration);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(109);
    match(Grammar::DICT_KEYWORD);
    setState(110);
    match(Grammar::LESSTHAN);
    setState(111);
    dictionaryDeclarationType();
    setState(112);
    match(Grammar::GREATERTHAN);
    setState(113);
    match(Grammar::IDENTIFIER);
    setState(114);
    match(Grammar::EQ);
    setState(115);
    match(Grammar::LBRACE);
    setState(127);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 515396077056) != 0)) {
      setState(116);
      dictionaryAssignmentBody();
      setState(124);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == Grammar::COMMA) {
        setState(117);
        match(Grammar::COMMA);
        setState(118);
        dictionaryAssignmentBody();
        setState(120);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
        case 1: {
          setState(119);
          match(Grammar::COMMA);
          break;
        }

        default:
          break;
        }
        setState(126);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(129);
    match(Grammar::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DictionaryAssignmentBodyContext ------------------------------------------------------------------

Grammar::DictionaryAssignmentBodyContext::DictionaryAssignmentBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

Grammar::LiteralContext* Grammar::DictionaryAssignmentBodyContext::literal() {
  return getRuleContext<Grammar::LiteralContext>(0);
}

tree::TerminalNode* Grammar::DictionaryAssignmentBodyContext::COLON() {
  return getToken(Grammar::COLON, 0);
}

Grammar::ExpressionContext* Grammar::DictionaryAssignmentBodyContext::expression() {
  return getRuleContext<Grammar::ExpressionContext>(0);
}


size_t Grammar::DictionaryAssignmentBodyContext::getRuleIndex() const {
  return Grammar::RuleDictionaryAssignmentBody;
}

void Grammar::DictionaryAssignmentBodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDictionaryAssignmentBody(this);
}

void Grammar::DictionaryAssignmentBodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDictionaryAssignmentBody(this);
}


std::any Grammar::DictionaryAssignmentBodyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GrammarVisitor*>(visitor))
    return parserVisitor->visitDictionaryAssignmentBody(this);
  else
    return visitor->visitChildren(this);
}

Grammar::DictionaryAssignmentBodyContext* Grammar::dictionaryAssignmentBody() {
  DictionaryAssignmentBodyContext *_localctx = _tracker.createInstance<DictionaryAssignmentBodyContext>(_ctx, getState());
  enterRule(_localctx, 6, Grammar::RuleDictionaryAssignmentBody);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(131);
    literal();
    setState(132);
    match(Grammar::COLON);
    setState(133);
    expression();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DictionaryDeclarationTypeContext ------------------------------------------------------------------

Grammar::DictionaryDeclarationTypeContext::DictionaryDeclarationTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<Grammar::DictionaryTypeElementContext *> Grammar::DictionaryDeclarationTypeContext::dictionaryTypeElement() {
  return getRuleContexts<Grammar::DictionaryTypeElementContext>();
}

Grammar::DictionaryTypeElementContext* Grammar::DictionaryDeclarationTypeContext::dictionaryTypeElement(size_t i) {
  return getRuleContext<Grammar::DictionaryTypeElementContext>(i);
}

tree::TerminalNode* Grammar::DictionaryDeclarationTypeContext::COMMA() {
  return getToken(Grammar::COMMA, 0);
}


size_t Grammar::DictionaryDeclarationTypeContext::getRuleIndex() const {
  return Grammar::RuleDictionaryDeclarationType;
}

void Grammar::DictionaryDeclarationTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDictionaryDeclarationType(this);
}

void Grammar::DictionaryDeclarationTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDictionaryDeclarationType(this);
}


std::any Grammar::DictionaryDeclarationTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GrammarVisitor*>(visitor))
    return parserVisitor->visitDictionaryDeclarationType(this);
  else
    return visitor->visitChildren(this);
}

Grammar::DictionaryDeclarationTypeContext* Grammar::dictionaryDeclarationType() {
  DictionaryDeclarationTypeContext *_localctx = _tracker.createInstance<DictionaryDeclarationTypeContext>(_ctx, getState());
  enterRule(_localctx, 8, Grammar::RuleDictionaryDeclarationType);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(135);
    dictionaryTypeElement();
    setState(136);
    match(Grammar::COMMA);
    setState(137);
    dictionaryTypeElement();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DictionaryTypeElementContext ------------------------------------------------------------------

Grammar::DictionaryTypeElementContext::DictionaryTypeElementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

Grammar::DictionaryDeclarationTypeArrayContext* Grammar::DictionaryTypeElementContext::dictionaryDeclarationTypeArray() {
  return getRuleContext<Grammar::DictionaryDeclarationTypeArrayContext>(0);
}

Grammar::DictionaryDataTypeContext* Grammar::DictionaryTypeElementContext::dictionaryDataType() {
  return getRuleContext<Grammar::DictionaryDataTypeContext>(0);
}


size_t Grammar::DictionaryTypeElementContext::getRuleIndex() const {
  return Grammar::RuleDictionaryTypeElement;
}

void Grammar::DictionaryTypeElementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDictionaryTypeElement(this);
}

void Grammar::DictionaryTypeElementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDictionaryTypeElement(this);
}


std::any Grammar::DictionaryTypeElementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GrammarVisitor*>(visitor))
    return parserVisitor->visitDictionaryTypeElement(this);
  else
    return visitor->visitChildren(this);
}

Grammar::DictionaryTypeElementContext* Grammar::dictionaryTypeElement() {
  DictionaryTypeElementContext *_localctx = _tracker.createInstance<DictionaryTypeElementContext>(_ctx, getState());
  enterRule(_localctx, 10, Grammar::RuleDictionaryTypeElement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(141);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(139);
      dictionaryDeclarationTypeArray();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(140);
      dictionaryDataType();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DictionaryDeclarationTypeArrayContext ------------------------------------------------------------------

Grammar::DictionaryDeclarationTypeArrayContext::DictionaryDeclarationTypeArrayContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

Grammar::DictionaryDataTypeContext* Grammar::DictionaryDeclarationTypeArrayContext::dictionaryDataType() {
  return getRuleContext<Grammar::DictionaryDataTypeContext>(0);
}

tree::TerminalNode* Grammar::DictionaryDeclarationTypeArrayContext::LBRACKET() {
  return getToken(Grammar::LBRACKET, 0);
}

tree::TerminalNode* Grammar::DictionaryDeclarationTypeArrayContext::RBRACKET() {
  return getToken(Grammar::RBRACKET, 0);
}

Grammar::ExpressionContext* Grammar::DictionaryDeclarationTypeArrayContext::expression() {
  return getRuleContext<Grammar::ExpressionContext>(0);
}


size_t Grammar::DictionaryDeclarationTypeArrayContext::getRuleIndex() const {
  return Grammar::RuleDictionaryDeclarationTypeArray;
}

void Grammar::DictionaryDeclarationTypeArrayContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDictionaryDeclarationTypeArray(this);
}

void Grammar::DictionaryDeclarationTypeArrayContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDictionaryDeclarationTypeArray(this);
}


std::any Grammar::DictionaryDeclarationTypeArrayContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GrammarVisitor*>(visitor))
    return parserVisitor->visitDictionaryDeclarationTypeArray(this);
  else
    return visitor->visitChildren(this);
}

Grammar::DictionaryDeclarationTypeArrayContext* Grammar::dictionaryDeclarationTypeArray() {
  DictionaryDeclarationTypeArrayContext *_localctx = _tracker.createInstance<DictionaryDeclarationTypeArrayContext>(_ctx, getState());
  enterRule(_localctx, 12, Grammar::RuleDictionaryDeclarationTypeArray);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(143);
    dictionaryDataType();
    setState(144);
    match(Grammar::LBRACKET);
    setState(146);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 515396208128) != 0)) {
      setState(145);
      expression();
    }
    setState(148);
    match(Grammar::RBRACKET);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DictionaryDataTypeContext ------------------------------------------------------------------

Grammar::DictionaryDataTypeContext::DictionaryDataTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Grammar::DictionaryDataTypeContext::INTEGER_TYPES() {
  return getToken(Grammar::INTEGER_TYPES, 0);
}

tree::TerminalNode* Grammar::DictionaryDataTypeContext::UNSIGNED_INTEGER_TYPES() {
  return getToken(Grammar::UNSIGNED_INTEGER_TYPES, 0);
}

tree::TerminalNode* Grammar::DictionaryDataTypeContext::FLOAT_TYPES() {
  return getToken(Grammar::FLOAT_TYPES, 0);
}

tree::TerminalNode* Grammar::DictionaryDataTypeContext::BOOLEAN_TYPES() {
  return getToken(Grammar::BOOLEAN_TYPES, 0);
}

tree::TerminalNode* Grammar::DictionaryDataTypeContext::STRING_TYPES() {
  return getToken(Grammar::STRING_TYPES, 0);
}


size_t Grammar::DictionaryDataTypeContext::getRuleIndex() const {
  return Grammar::RuleDictionaryDataType;
}

void Grammar::DictionaryDataTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDictionaryDataType(this);
}

void Grammar::DictionaryDataTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDictionaryDataType(this);
}


std::any Grammar::DictionaryDataTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GrammarVisitor*>(visitor))
    return parserVisitor->visitDictionaryDataType(this);
  else
    return visitor->visitChildren(this);
}

Grammar::DictionaryDataTypeContext* Grammar::dictionaryDataType() {
  DictionaryDataTypeContext *_localctx = _tracker.createInstance<DictionaryDataTypeContext>(_ctx, getState());
  enterRule(_localctx, 14, Grammar::RuleDictionaryDataType);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(150);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 248) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionContext ------------------------------------------------------------------

Grammar::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

Grammar::BooleanLiteralContext* Grammar::ExpressionContext::booleanLiteral() {
  return getRuleContext<Grammar::BooleanLiteralContext>(0);
}

Grammar::NumberLiteralsContext* Grammar::ExpressionContext::numberLiterals() {
  return getRuleContext<Grammar::NumberLiteralsContext>(0);
}

Grammar::BinaryExpressionContext* Grammar::ExpressionContext::binaryExpression() {
  return getRuleContext<Grammar::BinaryExpressionContext>(0);
}

Grammar::ConcatenationExpressionContext* Grammar::ExpressionContext::concatenationExpression() {
  return getRuleContext<Grammar::ConcatenationExpressionContext>(0);
}

Grammar::IdentifierLiteralContext* Grammar::ExpressionContext::identifierLiteral() {
  return getRuleContext<Grammar::IdentifierLiteralContext>(0);
}

Grammar::MemberExpressionContext* Grammar::ExpressionContext::memberExpression() {
  return getRuleContext<Grammar::MemberExpressionContext>(0);
}


size_t Grammar::ExpressionContext::getRuleIndex() const {
  return Grammar::RuleExpression;
}

void Grammar::ExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpression(this);
}

void Grammar::ExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpression(this);
}


std::any Grammar::ExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GrammarVisitor*>(visitor))
    return parserVisitor->visitExpression(this);
  else
    return visitor->visitChildren(this);
}

Grammar::ExpressionContext* Grammar::expression() {
  ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, getState());
  enterRule(_localctx, 16, Grammar::RuleExpression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(158);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(152);
      booleanLiteral();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(153);
      numberLiterals();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(154);
      binaryExpression(0);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(155);
      concatenationExpression();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(156);
      identifierLiteral();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(157);
      memberExpression();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConcatenationExpressionContext ------------------------------------------------------------------

Grammar::ConcatenationExpressionContext::ConcatenationExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<Grammar::StringLiteralsContext *> Grammar::ConcatenationExpressionContext::stringLiterals() {
  return getRuleContexts<Grammar::StringLiteralsContext>();
}

Grammar::StringLiteralsContext* Grammar::ConcatenationExpressionContext::stringLiterals(size_t i) {
  return getRuleContext<Grammar::StringLiteralsContext>(i);
}

std::vector<Grammar::IdentifierLiteralContext *> Grammar::ConcatenationExpressionContext::identifierLiteral() {
  return getRuleContexts<Grammar::IdentifierLiteralContext>();
}

Grammar::IdentifierLiteralContext* Grammar::ConcatenationExpressionContext::identifierLiteral(size_t i) {
  return getRuleContext<Grammar::IdentifierLiteralContext>(i);
}

std::vector<tree::TerminalNode *> Grammar::ConcatenationExpressionContext::PLUS() {
  return getTokens(Grammar::PLUS);
}

tree::TerminalNode* Grammar::ConcatenationExpressionContext::PLUS(size_t i) {
  return getToken(Grammar::PLUS, i);
}


size_t Grammar::ConcatenationExpressionContext::getRuleIndex() const {
  return Grammar::RuleConcatenationExpression;
}

void Grammar::ConcatenationExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConcatenationExpression(this);
}

void Grammar::ConcatenationExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConcatenationExpression(this);
}


std::any Grammar::ConcatenationExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GrammarVisitor*>(visitor))
    return parserVisitor->visitConcatenationExpression(this);
  else
    return visitor->visitChildren(this);
}

Grammar::ConcatenationExpressionContext* Grammar::concatenationExpression() {
  ConcatenationExpressionContext *_localctx = _tracker.createInstance<ConcatenationExpressionContext>(_ctx, getState());
  enterRule(_localctx, 18, Grammar::RuleConcatenationExpression);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(174); 
    _errHandler->sync(this);
    alt = 1;
    do {
      switch (alt) {
        case 1: {
              setState(162);
              _errHandler->sync(this);
              switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx)) {
              case 1: {
                setState(160);
                stringLiterals();
                break;
              }

              case 2: {
                setState(161);
                identifierLiteral();
                break;
              }

              default:
                break;
              }
              setState(171);
              _errHandler->sync(this);
              _la = _input->LA(1);
              while (_la == Grammar::PLUS) {
                setState(164);
                match(Grammar::PLUS);
                setState(167);
                _errHandler->sync(this);
                switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx)) {
                case 1: {
                  setState(165);
                  stringLiterals();
                  break;
                }

                case 2: {
                  setState(166);
                  identifierLiteral();
                  break;
                }

                default:
                  break;
                }
                setState(173);
                _errHandler->sync(this);
                _la = _input->LA(1);
              }
              break;
            }

      default:
        throw NoViableAltException(this);
      }
      setState(176); 
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx);
    } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BinaryExpressionContext ------------------------------------------------------------------

Grammar::BinaryExpressionContext::BinaryExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

Grammar::NumberLiteralsContext* Grammar::BinaryExpressionContext::numberLiterals() {
  return getRuleContext<Grammar::NumberLiteralsContext>(0);
}

Grammar::IdentifierLiteralContext* Grammar::BinaryExpressionContext::identifierLiteral() {
  return getRuleContext<Grammar::IdentifierLiteralContext>(0);
}

tree::TerminalNode* Grammar::BinaryExpressionContext::LPAREN() {
  return getToken(Grammar::LPAREN, 0);
}

std::vector<Grammar::BinaryExpressionContext *> Grammar::BinaryExpressionContext::binaryExpression() {
  return getRuleContexts<Grammar::BinaryExpressionContext>();
}

Grammar::BinaryExpressionContext* Grammar::BinaryExpressionContext::binaryExpression(size_t i) {
  return getRuleContext<Grammar::BinaryExpressionContext>(i);
}

tree::TerminalNode* Grammar::BinaryExpressionContext::RPAREN() {
  return getToken(Grammar::RPAREN, 0);
}

tree::TerminalNode* Grammar::BinaryExpressionContext::MUL() {
  return getToken(Grammar::MUL, 0);
}

tree::TerminalNode* Grammar::BinaryExpressionContext::DIV() {
  return getToken(Grammar::DIV, 0);
}

tree::TerminalNode* Grammar::BinaryExpressionContext::MOD() {
  return getToken(Grammar::MOD, 0);
}

tree::TerminalNode* Grammar::BinaryExpressionContext::PLUS() {
  return getToken(Grammar::PLUS, 0);
}

tree::TerminalNode* Grammar::BinaryExpressionContext::MINUS() {
  return getToken(Grammar::MINUS, 0);
}


size_t Grammar::BinaryExpressionContext::getRuleIndex() const {
  return Grammar::RuleBinaryExpression;
}

void Grammar::BinaryExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBinaryExpression(this);
}

void Grammar::BinaryExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBinaryExpression(this);
}


std::any Grammar::BinaryExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GrammarVisitor*>(visitor))
    return parserVisitor->visitBinaryExpression(this);
  else
    return visitor->visitChildren(this);
}


Grammar::BinaryExpressionContext* Grammar::binaryExpression() {
   return binaryExpression(0);
}

Grammar::BinaryExpressionContext* Grammar::binaryExpression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  Grammar::BinaryExpressionContext *_localctx = _tracker.createInstance<BinaryExpressionContext>(_ctx, parentState);
  Grammar::BinaryExpressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 20;
  enterRecursionRule(_localctx, 20, Grammar::RuleBinaryExpression, precedence);

    size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(185);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case Grammar::FLOAT:
      case Grammar::INTEGER: {
        setState(179);
        numberLiterals();
        break;
      }

      case Grammar::IDENTIFIER: {
        setState(180);
        identifierLiteral();
        break;
      }

      case Grammar::LPAREN: {
        setState(181);
        match(Grammar::LPAREN);
        setState(182);
        binaryExpression(0);
        setState(183);
        match(Grammar::RPAREN);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(195);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(193);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<BinaryExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleBinaryExpression);
          setState(187);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(188);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & 57344) != 0))) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(189);
          binaryExpression(3);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<BinaryExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleBinaryExpression);
          setState(190);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(191);
          _la = _input->LA(1);
          if (!(_la == Grammar::PLUS

          || _la == Grammar::MINUS)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(192);
          binaryExpression(2);
          break;
        }

        default:
          break;
        } 
      }
      setState(197);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- LiteralContext ------------------------------------------------------------------

Grammar::LiteralContext::LiteralContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

Grammar::NumberLiteralsContext* Grammar::LiteralContext::numberLiterals() {
  return getRuleContext<Grammar::NumberLiteralsContext>(0);
}

Grammar::StringLiteralsContext* Grammar::LiteralContext::stringLiterals() {
  return getRuleContext<Grammar::StringLiteralsContext>(0);
}

Grammar::BooleanLiteralContext* Grammar::LiteralContext::booleanLiteral() {
  return getRuleContext<Grammar::BooleanLiteralContext>(0);
}

Grammar::IdentifierLiteralContext* Grammar::LiteralContext::identifierLiteral() {
  return getRuleContext<Grammar::IdentifierLiteralContext>(0);
}


size_t Grammar::LiteralContext::getRuleIndex() const {
  return Grammar::RuleLiteral;
}

void Grammar::LiteralContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLiteral(this);
}

void Grammar::LiteralContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLiteral(this);
}


std::any Grammar::LiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GrammarVisitor*>(visitor))
    return parserVisitor->visitLiteral(this);
  else
    return visitor->visitChildren(this);
}

Grammar::LiteralContext* Grammar::literal() {
  LiteralContext *_localctx = _tracker.createInstance<LiteralContext>(_ctx, getState());
  enterRule(_localctx, 22, Grammar::RuleLiteral);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(202);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(198);
      numberLiterals();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(199);
      stringLiterals();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(200);
      booleanLiteral();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(201);
      identifierLiteral();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NumberLiteralsContext ------------------------------------------------------------------

Grammar::NumberLiteralsContext::NumberLiteralsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

Grammar::IntegerLiteralContext* Grammar::NumberLiteralsContext::integerLiteral() {
  return getRuleContext<Grammar::IntegerLiteralContext>(0);
}

Grammar::FloatLiteralContext* Grammar::NumberLiteralsContext::floatLiteral() {
  return getRuleContext<Grammar::FloatLiteralContext>(0);
}


size_t Grammar::NumberLiteralsContext::getRuleIndex() const {
  return Grammar::RuleNumberLiterals;
}

void Grammar::NumberLiteralsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNumberLiterals(this);
}

void Grammar::NumberLiteralsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNumberLiterals(this);
}


std::any Grammar::NumberLiteralsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GrammarVisitor*>(visitor))
    return parserVisitor->visitNumberLiterals(this);
  else
    return visitor->visitChildren(this);
}

Grammar::NumberLiteralsContext* Grammar::numberLiterals() {
  NumberLiteralsContext *_localctx = _tracker.createInstance<NumberLiteralsContext>(_ctx, getState());
  enterRule(_localctx, 24, Grammar::RuleNumberLiterals);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(206);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case Grammar::INTEGER: {
        enterOuterAlt(_localctx, 1);
        setState(204);
        integerLiteral();
        break;
      }

      case Grammar::FLOAT: {
        enterOuterAlt(_localctx, 2);
        setState(205);
        floatLiteral();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StringLiteralsContext ------------------------------------------------------------------

Grammar::StringLiteralsContext::StringLiteralsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

Grammar::StringLiteralContext* Grammar::StringLiteralsContext::stringLiteral() {
  return getRuleContext<Grammar::StringLiteralContext>(0);
}

Grammar::FormattedStringContext* Grammar::StringLiteralsContext::formattedString() {
  return getRuleContext<Grammar::FormattedStringContext>(0);
}

Grammar::IdentifierLiteralContext* Grammar::StringLiteralsContext::identifierLiteral() {
  return getRuleContext<Grammar::IdentifierLiteralContext>(0);
}


size_t Grammar::StringLiteralsContext::getRuleIndex() const {
  return Grammar::RuleStringLiterals;
}

void Grammar::StringLiteralsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStringLiterals(this);
}

void Grammar::StringLiteralsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStringLiterals(this);
}


std::any Grammar::StringLiteralsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GrammarVisitor*>(visitor))
    return parserVisitor->visitStringLiterals(this);
  else
    return visitor->visitChildren(this);
}

Grammar::StringLiteralsContext* Grammar::stringLiterals() {
  StringLiteralsContext *_localctx = _tracker.createInstance<StringLiteralsContext>(_ctx, getState());
  enterRule(_localctx, 26, Grammar::RuleStringLiterals);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(211);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case Grammar::STRING: {
        enterOuterAlt(_localctx, 1);
        setState(208);
        stringLiteral();
        break;
      }

      case Grammar::FORMATTED_STRING_START: {
        enterOuterAlt(_localctx, 2);
        setState(209);
        formattedString();
        break;
      }

      case Grammar::IDENTIFIER: {
        enterOuterAlt(_localctx, 3);
        setState(210);
        identifierLiteral();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FormattedStringContext ------------------------------------------------------------------

Grammar::FormattedStringContext::FormattedStringContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Grammar::FormattedStringContext::FORMATTED_STRING_START() {
  return getToken(Grammar::FORMATTED_STRING_START, 0);
}

tree::TerminalNode* Grammar::FormattedStringContext::FORMATTED_STRING_END() {
  return getToken(Grammar::FORMATTED_STRING_END, 0);
}

std::vector<Grammar::FormattedStringContentContext *> Grammar::FormattedStringContext::formattedStringContent() {
  return getRuleContexts<Grammar::FormattedStringContentContext>();
}

Grammar::FormattedStringContentContext* Grammar::FormattedStringContext::formattedStringContent(size_t i) {
  return getRuleContext<Grammar::FormattedStringContentContext>(i);
}


size_t Grammar::FormattedStringContext::getRuleIndex() const {
  return Grammar::RuleFormattedString;
}

void Grammar::FormattedStringContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFormattedString(this);
}

void Grammar::FormattedStringContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFormattedString(this);
}


std::any Grammar::FormattedStringContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GrammarVisitor*>(visitor))
    return parserVisitor->visitFormattedString(this);
  else
    return visitor->visitChildren(this);
}

Grammar::FormattedStringContext* Grammar::formattedString() {
  FormattedStringContext *_localctx = _tracker.createInstance<FormattedStringContext>(_ctx, getState());
  enterRule(_localctx, 28, Grammar::RuleFormattedString);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(213);
    match(Grammar::FORMATTED_STRING_START);
    setState(217);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 3848290697216) != 0)) {
      setState(214);
      formattedStringContent();
      setState(219);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(220);
    match(Grammar::FORMATTED_STRING_END);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FormattedStringContentContext ------------------------------------------------------------------

Grammar::FormattedStringContentContext::FormattedStringContentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Grammar::FormattedStringContentContext::REGEX_LITERAL() {
  return getToken(Grammar::REGEX_LITERAL, 0);
}

tree::TerminalNode* Grammar::FormattedStringContentContext::FORMATTED_STRING_TEXT() {
  return getToken(Grammar::FORMATTED_STRING_TEXT, 0);
}

tree::TerminalNode* Grammar::FormattedStringContentContext::LBRACE_IN_FSTRING() {
  return getToken(Grammar::LBRACE_IN_FSTRING, 0);
}

Grammar::ExpressionContext* Grammar::FormattedStringContentContext::expression() {
  return getRuleContext<Grammar::ExpressionContext>(0);
}

tree::TerminalNode* Grammar::FormattedStringContentContext::RBRACE_IN_FSTRING() {
  return getToken(Grammar::RBRACE_IN_FSTRING, 0);
}


size_t Grammar::FormattedStringContentContext::getRuleIndex() const {
  return Grammar::RuleFormattedStringContent;
}

void Grammar::FormattedStringContentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFormattedStringContent(this);
}

void Grammar::FormattedStringContentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFormattedStringContent(this);
}


std::any Grammar::FormattedStringContentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GrammarVisitor*>(visitor))
    return parserVisitor->visitFormattedStringContent(this);
  else
    return visitor->visitChildren(this);
}

Grammar::FormattedStringContentContext* Grammar::formattedStringContent() {
  FormattedStringContentContext *_localctx = _tracker.createInstance<FormattedStringContentContext>(_ctx, getState());
  enterRule(_localctx, 30, Grammar::RuleFormattedStringContent);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(228);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case Grammar::REGEX_LITERAL: {
        enterOuterAlt(_localctx, 1);
        setState(222);
        match(Grammar::REGEX_LITERAL);
        break;
      }

      case Grammar::FORMATTED_STRING_TEXT: {
        enterOuterAlt(_localctx, 2);
        setState(223);
        match(Grammar::FORMATTED_STRING_TEXT);
        break;
      }

      case Grammar::LBRACE_IN_FSTRING: {
        enterOuterAlt(_localctx, 3);
        setState(224);
        match(Grammar::LBRACE_IN_FSTRING);
        setState(225);
        expression();
        setState(226);
        match(Grammar::RBRACE_IN_FSTRING);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StringLiteralContext ------------------------------------------------------------------

Grammar::StringLiteralContext::StringLiteralContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Grammar::StringLiteralContext::STRING() {
  return getToken(Grammar::STRING, 0);
}


size_t Grammar::StringLiteralContext::getRuleIndex() const {
  return Grammar::RuleStringLiteral;
}

void Grammar::StringLiteralContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStringLiteral(this);
}

void Grammar::StringLiteralContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStringLiteral(this);
}


std::any Grammar::StringLiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GrammarVisitor*>(visitor))
    return parserVisitor->visitStringLiteral(this);
  else
    return visitor->visitChildren(this);
}

Grammar::StringLiteralContext* Grammar::stringLiteral() {
  StringLiteralContext *_localctx = _tracker.createInstance<StringLiteralContext>(_ctx, getState());
  enterRule(_localctx, 32, Grammar::RuleStringLiteral);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(230);
    match(Grammar::STRING);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IntegerLiteralContext ------------------------------------------------------------------

Grammar::IntegerLiteralContext::IntegerLiteralContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Grammar::IntegerLiteralContext::INTEGER() {
  return getToken(Grammar::INTEGER, 0);
}


size_t Grammar::IntegerLiteralContext::getRuleIndex() const {
  return Grammar::RuleIntegerLiteral;
}

void Grammar::IntegerLiteralContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIntegerLiteral(this);
}

void Grammar::IntegerLiteralContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIntegerLiteral(this);
}


std::any Grammar::IntegerLiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GrammarVisitor*>(visitor))
    return parserVisitor->visitIntegerLiteral(this);
  else
    return visitor->visitChildren(this);
}

Grammar::IntegerLiteralContext* Grammar::integerLiteral() {
  IntegerLiteralContext *_localctx = _tracker.createInstance<IntegerLiteralContext>(_ctx, getState());
  enterRule(_localctx, 34, Grammar::RuleIntegerLiteral);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(232);
    match(Grammar::INTEGER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FloatLiteralContext ------------------------------------------------------------------

Grammar::FloatLiteralContext::FloatLiteralContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Grammar::FloatLiteralContext::FLOAT() {
  return getToken(Grammar::FLOAT, 0);
}


size_t Grammar::FloatLiteralContext::getRuleIndex() const {
  return Grammar::RuleFloatLiteral;
}

void Grammar::FloatLiteralContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFloatLiteral(this);
}

void Grammar::FloatLiteralContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFloatLiteral(this);
}


std::any Grammar::FloatLiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GrammarVisitor*>(visitor))
    return parserVisitor->visitFloatLiteral(this);
  else
    return visitor->visitChildren(this);
}

Grammar::FloatLiteralContext* Grammar::floatLiteral() {
  FloatLiteralContext *_localctx = _tracker.createInstance<FloatLiteralContext>(_ctx, getState());
  enterRule(_localctx, 36, Grammar::RuleFloatLiteral);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(234);
    match(Grammar::FLOAT);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BooleanLiteralContext ------------------------------------------------------------------

Grammar::BooleanLiteralContext::BooleanLiteralContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Grammar::BooleanLiteralContext::BOOLEAN() {
  return getToken(Grammar::BOOLEAN, 0);
}


size_t Grammar::BooleanLiteralContext::getRuleIndex() const {
  return Grammar::RuleBooleanLiteral;
}

void Grammar::BooleanLiteralContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBooleanLiteral(this);
}

void Grammar::BooleanLiteralContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBooleanLiteral(this);
}


std::any Grammar::BooleanLiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GrammarVisitor*>(visitor))
    return parserVisitor->visitBooleanLiteral(this);
  else
    return visitor->visitChildren(this);
}

Grammar::BooleanLiteralContext* Grammar::booleanLiteral() {
  BooleanLiteralContext *_localctx = _tracker.createInstance<BooleanLiteralContext>(_ctx, getState());
  enterRule(_localctx, 38, Grammar::RuleBooleanLiteral);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(236);
    match(Grammar::BOOLEAN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NoneLiteralContext ------------------------------------------------------------------

Grammar::NoneLiteralContext::NoneLiteralContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Grammar::NoneLiteralContext::NONE() {
  return getToken(Grammar::NONE, 0);
}


size_t Grammar::NoneLiteralContext::getRuleIndex() const {
  return Grammar::RuleNoneLiteral;
}

void Grammar::NoneLiteralContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNoneLiteral(this);
}

void Grammar::NoneLiteralContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNoneLiteral(this);
}


std::any Grammar::NoneLiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GrammarVisitor*>(visitor))
    return parserVisitor->visitNoneLiteral(this);
  else
    return visitor->visitChildren(this);
}

Grammar::NoneLiteralContext* Grammar::noneLiteral() {
  NoneLiteralContext *_localctx = _tracker.createInstance<NoneLiteralContext>(_ctx, getState());
  enterRule(_localctx, 40, Grammar::RuleNoneLiteral);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(238);
    match(Grammar::NONE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IdentifierLiteralContext ------------------------------------------------------------------

Grammar::IdentifierLiteralContext::IdentifierLiteralContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Grammar::IdentifierLiteralContext::IDENTIFIER() {
  return getToken(Grammar::IDENTIFIER, 0);
}


size_t Grammar::IdentifierLiteralContext::getRuleIndex() const {
  return Grammar::RuleIdentifierLiteral;
}

void Grammar::IdentifierLiteralContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIdentifierLiteral(this);
}

void Grammar::IdentifierLiteralContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIdentifierLiteral(this);
}


std::any Grammar::IdentifierLiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GrammarVisitor*>(visitor))
    return parserVisitor->visitIdentifierLiteral(this);
  else
    return visitor->visitChildren(this);
}

Grammar::IdentifierLiteralContext* Grammar::identifierLiteral() {
  IdentifierLiteralContext *_localctx = _tracker.createInstance<IdentifierLiteralContext>(_ctx, getState());
  enterRule(_localctx, 42, Grammar::RuleIdentifierLiteral);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(240);
    match(Grammar::IDENTIFIER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MemberExpressionContext ------------------------------------------------------------------

Grammar::MemberExpressionContext::MemberExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

Grammar::ValueAtomContext* Grammar::MemberExpressionContext::valueAtom() {
  return getRuleContext<Grammar::ValueAtomContext>(0);
}

std::vector<Grammar::ValuePostfixContext *> Grammar::MemberExpressionContext::valuePostfix() {
  return getRuleContexts<Grammar::ValuePostfixContext>();
}

Grammar::ValuePostfixContext* Grammar::MemberExpressionContext::valuePostfix(size_t i) {
  return getRuleContext<Grammar::ValuePostfixContext>(i);
}


size_t Grammar::MemberExpressionContext::getRuleIndex() const {
  return Grammar::RuleMemberExpression;
}

void Grammar::MemberExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMemberExpression(this);
}

void Grammar::MemberExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMemberExpression(this);
}


std::any Grammar::MemberExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GrammarVisitor*>(visitor))
    return parserVisitor->visitMemberExpression(this);
  else
    return visitor->visitChildren(this);
}

Grammar::MemberExpressionContext* Grammar::memberExpression() {
  MemberExpressionContext *_localctx = _tracker.createInstance<MemberExpressionContext>(_ctx, getState());
  enterRule(_localctx, 44, Grammar::RuleMemberExpression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(242);
    valueAtom();
    setState(246);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(243);
        valuePostfix(); 
      }
      setState(248);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ValuePostfixContext ------------------------------------------------------------------

Grammar::ValuePostfixContext::ValuePostfixContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Grammar::ValuePostfixContext::DOT() {
  return getToken(Grammar::DOT, 0);
}

Grammar::IdentifierLiteralContext* Grammar::ValuePostfixContext::identifierLiteral() {
  return getRuleContext<Grammar::IdentifierLiteralContext>(0);
}

tree::TerminalNode* Grammar::ValuePostfixContext::LPAREN() {
  return getToken(Grammar::LPAREN, 0);
}

tree::TerminalNode* Grammar::ValuePostfixContext::RPAREN() {
  return getToken(Grammar::RPAREN, 0);
}

Grammar::ArgumentListContext* Grammar::ValuePostfixContext::argumentList() {
  return getRuleContext<Grammar::ArgumentListContext>(0);
}


size_t Grammar::ValuePostfixContext::getRuleIndex() const {
  return Grammar::RuleValuePostfix;
}

void Grammar::ValuePostfixContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterValuePostfix(this);
}

void Grammar::ValuePostfixContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitValuePostfix(this);
}


std::any Grammar::ValuePostfixContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GrammarVisitor*>(visitor))
    return parserVisitor->visitValuePostfix(this);
  else
    return visitor->visitChildren(this);
}

Grammar::ValuePostfixContext* Grammar::valuePostfix() {
  ValuePostfixContext *_localctx = _tracker.createInstance<ValuePostfixContext>(_ctx, getState());
  enterRule(_localctx, 46, Grammar::RuleValuePostfix);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(256);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case Grammar::DOT: {
        enterOuterAlt(_localctx, 1);
        setState(249);
        match(Grammar::DOT);
        setState(250);
        identifierLiteral();
        break;
      }

      case Grammar::LPAREN: {
        enterOuterAlt(_localctx, 2);
        setState(251);
        match(Grammar::LPAREN);
        setState(253);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & 515396208128) != 0)) {
          setState(252);
          argumentList();
        }
        setState(255);
        match(Grammar::RPAREN);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArgumentListContext ------------------------------------------------------------------

Grammar::ArgumentListContext::ArgumentListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<Grammar::ExpressionContext *> Grammar::ArgumentListContext::expression() {
  return getRuleContexts<Grammar::ExpressionContext>();
}

Grammar::ExpressionContext* Grammar::ArgumentListContext::expression(size_t i) {
  return getRuleContext<Grammar::ExpressionContext>(i);
}

std::vector<tree::TerminalNode *> Grammar::ArgumentListContext::COMMA() {
  return getTokens(Grammar::COMMA);
}

tree::TerminalNode* Grammar::ArgumentListContext::COMMA(size_t i) {
  return getToken(Grammar::COMMA, i);
}


size_t Grammar::ArgumentListContext::getRuleIndex() const {
  return Grammar::RuleArgumentList;
}

void Grammar::ArgumentListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArgumentList(this);
}

void Grammar::ArgumentListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArgumentList(this);
}


std::any Grammar::ArgumentListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GrammarVisitor*>(visitor))
    return parserVisitor->visitArgumentList(this);
  else
    return visitor->visitChildren(this);
}

Grammar::ArgumentListContext* Grammar::argumentList() {
  ArgumentListContext *_localctx = _tracker.createInstance<ArgumentListContext>(_ctx, getState());
  enterRule(_localctx, 48, Grammar::RuleArgumentList);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(258);
    expression();
    setState(263);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == Grammar::COMMA) {
      setState(259);
      match(Grammar::COMMA);
      setState(260);
      expression();
      setState(265);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ValueAtomContext ------------------------------------------------------------------

Grammar::ValueAtomContext::ValueAtomContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

Grammar::IdentifierLiteralContext* Grammar::ValueAtomContext::identifierLiteral() {
  return getRuleContext<Grammar::IdentifierLiteralContext>(0);
}

Grammar::StringLiteralContext* Grammar::ValueAtomContext::stringLiteral() {
  return getRuleContext<Grammar::StringLiteralContext>(0);
}

tree::TerminalNode* Grammar::ValueAtomContext::LPAREN() {
  return getToken(Grammar::LPAREN, 0);
}

Grammar::BooleanLiteralContext* Grammar::ValueAtomContext::booleanLiteral() {
  return getRuleContext<Grammar::BooleanLiteralContext>(0);
}

tree::TerminalNode* Grammar::ValueAtomContext::RPAREN() {
  return getToken(Grammar::RPAREN, 0);
}

Grammar::NumberLiteralsContext* Grammar::ValueAtomContext::numberLiterals() {
  return getRuleContext<Grammar::NumberLiteralsContext>(0);
}

Grammar::ExpressionContext* Grammar::ValueAtomContext::expression() {
  return getRuleContext<Grammar::ExpressionContext>(0);
}


size_t Grammar::ValueAtomContext::getRuleIndex() const {
  return Grammar::RuleValueAtom;
}

void Grammar::ValueAtomContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterValueAtom(this);
}

void Grammar::ValueAtomContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitValueAtom(this);
}


std::any Grammar::ValueAtomContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GrammarVisitor*>(visitor))
    return parserVisitor->visitValueAtom(this);
  else
    return visitor->visitChildren(this);
}

Grammar::ValueAtomContext* Grammar::valueAtom() {
  ValueAtomContext *_localctx = _tracker.createInstance<ValueAtomContext>(_ctx, getState());
  enterRule(_localctx, 50, Grammar::RuleValueAtom);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(280);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 26, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(266);
      identifierLiteral();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(267);
      stringLiteral();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(268);
      match(Grammar::LPAREN);
      setState(269);
      booleanLiteral();
      setState(270);
      match(Grammar::RPAREN);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(272);
      match(Grammar::LPAREN);
      setState(273);
      numberLiterals();
      setState(274);
      match(Grammar::RPAREN);
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(276);
      match(Grammar::LPAREN);
      setState(277);
      expression();
      setState(278);
      match(Grammar::RPAREN);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VariablesContext ------------------------------------------------------------------

Grammar::VariablesContext::VariablesContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

Grammar::VariableDeclarationContext* Grammar::VariablesContext::variableDeclaration() {
  return getRuleContext<Grammar::VariableDeclarationContext>(0);
}

Grammar::VariableDeclarationWithoutAssignmentContext* Grammar::VariablesContext::variableDeclarationWithoutAssignment() {
  return getRuleContext<Grammar::VariableDeclarationWithoutAssignmentContext>(0);
}

Grammar::VariableReAssignmentContext* Grammar::VariablesContext::variableReAssignment() {
  return getRuleContext<Grammar::VariableReAssignmentContext>(0);
}


size_t Grammar::VariablesContext::getRuleIndex() const {
  return Grammar::RuleVariables;
}

void Grammar::VariablesContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVariables(this);
}

void Grammar::VariablesContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVariables(this);
}


std::any Grammar::VariablesContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GrammarVisitor*>(visitor))
    return parserVisitor->visitVariables(this);
  else
    return visitor->visitChildren(this);
}

Grammar::VariablesContext* Grammar::variables() {
  VariablesContext *_localctx = _tracker.createInstance<VariablesContext>(_ctx, getState());
  enterRule(_localctx, 52, Grammar::RuleVariables);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(285);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 27, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(282);
      variableDeclaration();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(283);
      variableDeclarationWithoutAssignment();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(284);
      variableReAssignment();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VariableDeclarationContext ------------------------------------------------------------------

Grammar::VariableDeclarationContext::VariableDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

Grammar::VariableDataTypeContext* Grammar::VariableDeclarationContext::variableDataType() {
  return getRuleContext<Grammar::VariableDataTypeContext>(0);
}

tree::TerminalNode* Grammar::VariableDeclarationContext::IDENTIFIER() {
  return getToken(Grammar::IDENTIFIER, 0);
}

tree::TerminalNode* Grammar::VariableDeclarationContext::EQ() {
  return getToken(Grammar::EQ, 0);
}

Grammar::ExpressionContext* Grammar::VariableDeclarationContext::expression() {
  return getRuleContext<Grammar::ExpressionContext>(0);
}


size_t Grammar::VariableDeclarationContext::getRuleIndex() const {
  return Grammar::RuleVariableDeclaration;
}

void Grammar::VariableDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVariableDeclaration(this);
}

void Grammar::VariableDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVariableDeclaration(this);
}


std::any Grammar::VariableDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GrammarVisitor*>(visitor))
    return parserVisitor->visitVariableDeclaration(this);
  else
    return visitor->visitChildren(this);
}

Grammar::VariableDeclarationContext* Grammar::variableDeclaration() {
  VariableDeclarationContext *_localctx = _tracker.createInstance<VariableDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 54, Grammar::RuleVariableDeclaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(287);
    variableDataType();
    setState(288);
    match(Grammar::IDENTIFIER);
    setState(289);
    match(Grammar::EQ);
    inVarMode= true;
    setState(291);
    expression();
    inVarMode = false;
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VariableDeclarationWithoutAssignmentContext ------------------------------------------------------------------

Grammar::VariableDeclarationWithoutAssignmentContext::VariableDeclarationWithoutAssignmentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

Grammar::VariableDataTypeContext* Grammar::VariableDeclarationWithoutAssignmentContext::variableDataType() {
  return getRuleContext<Grammar::VariableDataTypeContext>(0);
}

tree::TerminalNode* Grammar::VariableDeclarationWithoutAssignmentContext::IDENTIFIER() {
  return getToken(Grammar::IDENTIFIER, 0);
}


size_t Grammar::VariableDeclarationWithoutAssignmentContext::getRuleIndex() const {
  return Grammar::RuleVariableDeclarationWithoutAssignment;
}

void Grammar::VariableDeclarationWithoutAssignmentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVariableDeclarationWithoutAssignment(this);
}

void Grammar::VariableDeclarationWithoutAssignmentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVariableDeclarationWithoutAssignment(this);
}


std::any Grammar::VariableDeclarationWithoutAssignmentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GrammarVisitor*>(visitor))
    return parserVisitor->visitVariableDeclarationWithoutAssignment(this);
  else
    return visitor->visitChildren(this);
}

Grammar::VariableDeclarationWithoutAssignmentContext* Grammar::variableDeclarationWithoutAssignment() {
  VariableDeclarationWithoutAssignmentContext *_localctx = _tracker.createInstance<VariableDeclarationWithoutAssignmentContext>(_ctx, getState());
  enterRule(_localctx, 56, Grammar::RuleVariableDeclarationWithoutAssignment);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(294);
    variableDataType();
    setState(295);
    match(Grammar::IDENTIFIER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VariableReAssignmentContext ------------------------------------------------------------------

Grammar::VariableReAssignmentContext::VariableReAssignmentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Grammar::VariableReAssignmentContext::IDENTIFIER() {
  return getToken(Grammar::IDENTIFIER, 0);
}

tree::TerminalNode* Grammar::VariableReAssignmentContext::EQ() {
  return getToken(Grammar::EQ, 0);
}

Grammar::ExpressionContext* Grammar::VariableReAssignmentContext::expression() {
  return getRuleContext<Grammar::ExpressionContext>(0);
}


size_t Grammar::VariableReAssignmentContext::getRuleIndex() const {
  return Grammar::RuleVariableReAssignment;
}

void Grammar::VariableReAssignmentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVariableReAssignment(this);
}

void Grammar::VariableReAssignmentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVariableReAssignment(this);
}


std::any Grammar::VariableReAssignmentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GrammarVisitor*>(visitor))
    return parserVisitor->visitVariableReAssignment(this);
  else
    return visitor->visitChildren(this);
}

Grammar::VariableReAssignmentContext* Grammar::variableReAssignment() {
  VariableReAssignmentContext *_localctx = _tracker.createInstance<VariableReAssignmentContext>(_ctx, getState());
  enterRule(_localctx, 58, Grammar::RuleVariableReAssignment);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(297);
    match(Grammar::IDENTIFIER);
    setState(298);
    match(Grammar::EQ);
    setState(299);
    expression();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VariableDataTypeContext ------------------------------------------------------------------

Grammar::VariableDataTypeContext::VariableDataTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Grammar::VariableDataTypeContext::INTEGER_TYPES() {
  return getToken(Grammar::INTEGER_TYPES, 0);
}

tree::TerminalNode* Grammar::VariableDataTypeContext::UNSIGNED_INTEGER_TYPES() {
  return getToken(Grammar::UNSIGNED_INTEGER_TYPES, 0);
}

tree::TerminalNode* Grammar::VariableDataTypeContext::FLOAT_TYPES() {
  return getToken(Grammar::FLOAT_TYPES, 0);
}

tree::TerminalNode* Grammar::VariableDataTypeContext::BOOLEAN_TYPES() {
  return getToken(Grammar::BOOLEAN_TYPES, 0);
}

tree::TerminalNode* Grammar::VariableDataTypeContext::STRING_TYPES() {
  return getToken(Grammar::STRING_TYPES, 0);
}

tree::TerminalNode* Grammar::VariableDataTypeContext::REGEX_TYPE() {
  return getToken(Grammar::REGEX_TYPE, 0);
}


size_t Grammar::VariableDataTypeContext::getRuleIndex() const {
  return Grammar::RuleVariableDataType;
}

void Grammar::VariableDataTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVariableDataType(this);
}

void Grammar::VariableDataTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVariableDataType(this);
}


std::any Grammar::VariableDataTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GrammarVisitor*>(visitor))
    return parserVisitor->visitVariableDataType(this);
  else
    return visitor->visitChildren(this);
}

Grammar::VariableDataTypeContext* Grammar::variableDataType() {
  VariableDataTypeContext *_localctx = _tracker.createInstance<VariableDataTypeContext>(_ctx, getState());
  enterRule(_localctx, 60, Grammar::RuleVariableDataType);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(301);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 250) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArraysContext ------------------------------------------------------------------

Grammar::ArraysContext::ArraysContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

Grammar::ArrayDeclarationContext* Grammar::ArraysContext::arrayDeclaration() {
  return getRuleContext<Grammar::ArrayDeclarationContext>(0);
}

Grammar::ArrayReAssignmentContext* Grammar::ArraysContext::arrayReAssignment() {
  return getRuleContext<Grammar::ArrayReAssignmentContext>(0);
}


size_t Grammar::ArraysContext::getRuleIndex() const {
  return Grammar::RuleArrays;
}

void Grammar::ArraysContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArrays(this);
}

void Grammar::ArraysContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArrays(this);
}


std::any Grammar::ArraysContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GrammarVisitor*>(visitor))
    return parserVisitor->visitArrays(this);
  else
    return visitor->visitChildren(this);
}

Grammar::ArraysContext* Grammar::arrays() {
  ArraysContext *_localctx = _tracker.createInstance<ArraysContext>(_ctx, getState());
  enterRule(_localctx, 62, Grammar::RuleArrays);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(305);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case Grammar::BOOLEAN_TYPES:
      case Grammar::STRING_TYPES:
      case Grammar::INTEGER_TYPES:
      case Grammar::UNSIGNED_INTEGER_TYPES:
      case Grammar::FLOAT_TYPES: {
        enterOuterAlt(_localctx, 1);
        setState(303);
        arrayDeclaration();
        break;
      }

      case Grammar::IDENTIFIER: {
        enterOuterAlt(_localctx, 2);
        setState(304);
        arrayReAssignment();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArrayDeclarationContext ------------------------------------------------------------------

Grammar::ArrayDeclarationContext::ArrayDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

Grammar::ArrayTypeContext* Grammar::ArrayDeclarationContext::arrayType() {
  return getRuleContext<Grammar::ArrayTypeContext>(0);
}

tree::TerminalNode* Grammar::ArrayDeclarationContext::IDENTIFIER() {
  return getToken(Grammar::IDENTIFIER, 0);
}

tree::TerminalNode* Grammar::ArrayDeclarationContext::EQ() {
  return getToken(Grammar::EQ, 0);
}

Grammar::ArrayValuesContext* Grammar::ArrayDeclarationContext::arrayValues() {
  return getRuleContext<Grammar::ArrayValuesContext>(0);
}


size_t Grammar::ArrayDeclarationContext::getRuleIndex() const {
  return Grammar::RuleArrayDeclaration;
}

void Grammar::ArrayDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArrayDeclaration(this);
}

void Grammar::ArrayDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArrayDeclaration(this);
}


std::any Grammar::ArrayDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GrammarVisitor*>(visitor))
    return parserVisitor->visitArrayDeclaration(this);
  else
    return visitor->visitChildren(this);
}

Grammar::ArrayDeclarationContext* Grammar::arrayDeclaration() {
  ArrayDeclarationContext *_localctx = _tracker.createInstance<ArrayDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 64, Grammar::RuleArrayDeclaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    inSkipMode = true;
    setState(308);
    arrayType();
    inSkipMode = false;
    setState(310);
    match(Grammar::IDENTIFIER);
    setState(311);
    match(Grammar::EQ);
    setState(312);
    arrayValues();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArrayValuesContext ------------------------------------------------------------------

Grammar::ArrayValuesContext::ArrayValuesContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

Grammar::ArrayItemsWithBracketsContext* Grammar::ArrayValuesContext::arrayItemsWithBrackets() {
  return getRuleContext<Grammar::ArrayItemsWithBracketsContext>(0);
}

std::vector<Grammar::ExpressionContext *> Grammar::ArrayValuesContext::expression() {
  return getRuleContexts<Grammar::ExpressionContext>();
}

Grammar::ExpressionContext* Grammar::ArrayValuesContext::expression(size_t i) {
  return getRuleContext<Grammar::ExpressionContext>(i);
}

Grammar::MemberExpressionContext* Grammar::ArrayValuesContext::memberExpression() {
  return getRuleContext<Grammar::MemberExpressionContext>(0);
}


size_t Grammar::ArrayValuesContext::getRuleIndex() const {
  return Grammar::RuleArrayValues;
}

void Grammar::ArrayValuesContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArrayValues(this);
}

void Grammar::ArrayValuesContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArrayValues(this);
}


std::any Grammar::ArrayValuesContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GrammarVisitor*>(visitor))
    return parserVisitor->visitArrayValues(this);
  else
    return visitor->visitChildren(this);
}

Grammar::ArrayValuesContext* Grammar::arrayValues() {
  ArrayValuesContext *_localctx = _tracker.createInstance<ArrayValuesContext>(_ctx, getState());
  enterRule(_localctx, 66, Grammar::RuleArrayValues);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    setState(322);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 30, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(314);
      arrayItemsWithBrackets();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(318);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 29, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(315);
          expression(); 
        }
        setState(320);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 29, _ctx);
      }
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(321);
      memberExpression();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArrayItemsWithBracketsContext ------------------------------------------------------------------

Grammar::ArrayItemsWithBracketsContext::ArrayItemsWithBracketsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Grammar::ArrayItemsWithBracketsContext::LBRACKET() {
  return getToken(Grammar::LBRACKET, 0);
}

tree::TerminalNode* Grammar::ArrayItemsWithBracketsContext::RBRACKET() {
  return getToken(Grammar::RBRACKET, 0);
}

std::vector<Grammar::ExpressionContext *> Grammar::ArrayItemsWithBracketsContext::expression() {
  return getRuleContexts<Grammar::ExpressionContext>();
}

Grammar::ExpressionContext* Grammar::ArrayItemsWithBracketsContext::expression(size_t i) {
  return getRuleContext<Grammar::ExpressionContext>(i);
}

std::vector<tree::TerminalNode *> Grammar::ArrayItemsWithBracketsContext::COMMA() {
  return getTokens(Grammar::COMMA);
}

tree::TerminalNode* Grammar::ArrayItemsWithBracketsContext::COMMA(size_t i) {
  return getToken(Grammar::COMMA, i);
}


size_t Grammar::ArrayItemsWithBracketsContext::getRuleIndex() const {
  return Grammar::RuleArrayItemsWithBrackets;
}

void Grammar::ArrayItemsWithBracketsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArrayItemsWithBrackets(this);
}

void Grammar::ArrayItemsWithBracketsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArrayItemsWithBrackets(this);
}


std::any Grammar::ArrayItemsWithBracketsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GrammarVisitor*>(visitor))
    return parserVisitor->visitArrayItemsWithBrackets(this);
  else
    return visitor->visitChildren(this);
}

Grammar::ArrayItemsWithBracketsContext* Grammar::arrayItemsWithBrackets() {
  ArrayItemsWithBracketsContext *_localctx = _tracker.createInstance<ArrayItemsWithBracketsContext>(_ctx, getState());
  enterRule(_localctx, 68, Grammar::RuleArrayItemsWithBrackets);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(324);
    match(Grammar::LBRACKET);
    setState(333);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 515396208128) != 0)) {
      setState(325);
      expression();
      setState(330);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == Grammar::COMMA) {
        setState(326);
        match(Grammar::COMMA);
        setState(327);
        expression();
        setState(332);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(335);
    match(Grammar::RBRACKET);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArrayItemsContext ------------------------------------------------------------------

Grammar::ArrayItemsContext::ArrayItemsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

Grammar::StringLiteralContext* Grammar::ArrayItemsContext::stringLiteral() {
  return getRuleContext<Grammar::StringLiteralContext>(0);
}

Grammar::FormattedStringContext* Grammar::ArrayItemsContext::formattedString() {
  return getRuleContext<Grammar::FormattedStringContext>(0);
}

Grammar::IdentifierLiteralContext* Grammar::ArrayItemsContext::identifierLiteral() {
  return getRuleContext<Grammar::IdentifierLiteralContext>(0);
}

Grammar::IntegerLiteralContext* Grammar::ArrayItemsContext::integerLiteral() {
  return getRuleContext<Grammar::IntegerLiteralContext>(0);
}

Grammar::FloatLiteralContext* Grammar::ArrayItemsContext::floatLiteral() {
  return getRuleContext<Grammar::FloatLiteralContext>(0);
}

Grammar::BooleanLiteralContext* Grammar::ArrayItemsContext::booleanLiteral() {
  return getRuleContext<Grammar::BooleanLiteralContext>(0);
}

Grammar::NoneLiteralContext* Grammar::ArrayItemsContext::noneLiteral() {
  return getRuleContext<Grammar::NoneLiteralContext>(0);
}

Grammar::ConcatenationExpressionContext* Grammar::ArrayItemsContext::concatenationExpression() {
  return getRuleContext<Grammar::ConcatenationExpressionContext>(0);
}

Grammar::BinaryExpressionContext* Grammar::ArrayItemsContext::binaryExpression() {
  return getRuleContext<Grammar::BinaryExpressionContext>(0);
}


size_t Grammar::ArrayItemsContext::getRuleIndex() const {
  return Grammar::RuleArrayItems;
}

void Grammar::ArrayItemsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArrayItems(this);
}

void Grammar::ArrayItemsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArrayItems(this);
}


std::any Grammar::ArrayItemsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GrammarVisitor*>(visitor))
    return parserVisitor->visitArrayItems(this);
  else
    return visitor->visitChildren(this);
}

Grammar::ArrayItemsContext* Grammar::arrayItems() {
  ArrayItemsContext *_localctx = _tracker.createInstance<ArrayItemsContext>(_ctx, getState());
  enterRule(_localctx, 70, Grammar::RuleArrayItems);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(346);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 33, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(337);
      stringLiteral();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(338);
      formattedString();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(339);
      identifierLiteral();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(340);
      integerLiteral();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(341);
      floatLiteral();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(342);
      booleanLiteral();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(343);
      noneLiteral();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(344);
      concatenationExpression();
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(345);
      binaryExpression(0);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArrayReAssignmentContext ------------------------------------------------------------------

Grammar::ArrayReAssignmentContext::ArrayReAssignmentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Grammar::ArrayReAssignmentContext::IDENTIFIER() {
  return getToken(Grammar::IDENTIFIER, 0);
}

tree::TerminalNode* Grammar::ArrayReAssignmentContext::EQ() {
  return getToken(Grammar::EQ, 0);
}

tree::TerminalNode* Grammar::ArrayReAssignmentContext::LBRACKET() {
  return getToken(Grammar::LBRACKET, 0);
}

tree::TerminalNode* Grammar::ArrayReAssignmentContext::RBRACKET() {
  return getToken(Grammar::RBRACKET, 0);
}

std::vector<Grammar::ExpressionContext *> Grammar::ArrayReAssignmentContext::expression() {
  return getRuleContexts<Grammar::ExpressionContext>();
}

Grammar::ExpressionContext* Grammar::ArrayReAssignmentContext::expression(size_t i) {
  return getRuleContext<Grammar::ExpressionContext>(i);
}

std::vector<tree::TerminalNode *> Grammar::ArrayReAssignmentContext::COMMA() {
  return getTokens(Grammar::COMMA);
}

tree::TerminalNode* Grammar::ArrayReAssignmentContext::COMMA(size_t i) {
  return getToken(Grammar::COMMA, i);
}


size_t Grammar::ArrayReAssignmentContext::getRuleIndex() const {
  return Grammar::RuleArrayReAssignment;
}

void Grammar::ArrayReAssignmentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArrayReAssignment(this);
}

void Grammar::ArrayReAssignmentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArrayReAssignment(this);
}


std::any Grammar::ArrayReAssignmentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GrammarVisitor*>(visitor))
    return parserVisitor->visitArrayReAssignment(this);
  else
    return visitor->visitChildren(this);
}

Grammar::ArrayReAssignmentContext* Grammar::arrayReAssignment() {
  ArrayReAssignmentContext *_localctx = _tracker.createInstance<ArrayReAssignmentContext>(_ctx, getState());
  enterRule(_localctx, 72, Grammar::RuleArrayReAssignment);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(348);
    match(Grammar::IDENTIFIER);
    setState(349);
    match(Grammar::EQ);
    setState(350);
    match(Grammar::LBRACKET);
    setState(359);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 515396208128) != 0)) {
      setState(351);
      expression();
      setState(356);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == Grammar::COMMA) {
        setState(352);
        match(Grammar::COMMA);
        setState(353);
        expression();
        setState(358);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(361);
    match(Grammar::RBRACKET);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArrayTypeContext ------------------------------------------------------------------

Grammar::ArrayTypeContext::ArrayTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

Grammar::ArrayDataTypeContext* Grammar::ArrayTypeContext::arrayDataType() {
  return getRuleContext<Grammar::ArrayDataTypeContext>(0);
}

tree::TerminalNode* Grammar::ArrayTypeContext::LBRACKET() {
  return getToken(Grammar::LBRACKET, 0);
}

Grammar::ArrayDeclarationTypeSizeContext* Grammar::ArrayTypeContext::arrayDeclarationTypeSize() {
  return getRuleContext<Grammar::ArrayDeclarationTypeSizeContext>(0);
}

tree::TerminalNode* Grammar::ArrayTypeContext::RBRACKET() {
  return getToken(Grammar::RBRACKET, 0);
}


size_t Grammar::ArrayTypeContext::getRuleIndex() const {
  return Grammar::RuleArrayType;
}

void Grammar::ArrayTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArrayType(this);
}

void Grammar::ArrayTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArrayType(this);
}


std::any Grammar::ArrayTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GrammarVisitor*>(visitor))
    return parserVisitor->visitArrayType(this);
  else
    return visitor->visitChildren(this);
}

Grammar::ArrayTypeContext* Grammar::arrayType() {
  ArrayTypeContext *_localctx = _tracker.createInstance<ArrayTypeContext>(_ctx, getState());
  enterRule(_localctx, 74, Grammar::RuleArrayType);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(363);
    arrayDataType();
    setState(364);
    match(Grammar::LBRACKET);
    setState(365);
    arrayDeclarationTypeSize();
    setState(366);
    match(Grammar::RBRACKET);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArrayDeclarationTypeSizeContext ------------------------------------------------------------------

Grammar::ArrayDeclarationTypeSizeContext::ArrayDeclarationTypeSizeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

Grammar::ExpressionContext* Grammar::ArrayDeclarationTypeSizeContext::expression() {
  return getRuleContext<Grammar::ExpressionContext>(0);
}


size_t Grammar::ArrayDeclarationTypeSizeContext::getRuleIndex() const {
  return Grammar::RuleArrayDeclarationTypeSize;
}

void Grammar::ArrayDeclarationTypeSizeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArrayDeclarationTypeSize(this);
}

void Grammar::ArrayDeclarationTypeSizeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArrayDeclarationTypeSize(this);
}


std::any Grammar::ArrayDeclarationTypeSizeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GrammarVisitor*>(visitor))
    return parserVisitor->visitArrayDeclarationTypeSize(this);
  else
    return visitor->visitChildren(this);
}

Grammar::ArrayDeclarationTypeSizeContext* Grammar::arrayDeclarationTypeSize() {
  ArrayDeclarationTypeSizeContext *_localctx = _tracker.createInstance<ArrayDeclarationTypeSizeContext>(_ctx, getState());
  enterRule(_localctx, 76, Grammar::RuleArrayDeclarationTypeSize);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    inSkipMode = false;
    setState(370);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 515396208128) != 0)) {
      setState(369);
      expression();
    }
    inSkipMode = true;
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArrayDataTypeContext ------------------------------------------------------------------

Grammar::ArrayDataTypeContext::ArrayDataTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Grammar::ArrayDataTypeContext::INTEGER_TYPES() {
  return getToken(Grammar::INTEGER_TYPES, 0);
}

tree::TerminalNode* Grammar::ArrayDataTypeContext::UNSIGNED_INTEGER_TYPES() {
  return getToken(Grammar::UNSIGNED_INTEGER_TYPES, 0);
}

tree::TerminalNode* Grammar::ArrayDataTypeContext::FLOAT_TYPES() {
  return getToken(Grammar::FLOAT_TYPES, 0);
}

tree::TerminalNode* Grammar::ArrayDataTypeContext::BOOLEAN_TYPES() {
  return getToken(Grammar::BOOLEAN_TYPES, 0);
}

tree::TerminalNode* Grammar::ArrayDataTypeContext::STRING_TYPES() {
  return getToken(Grammar::STRING_TYPES, 0);
}


size_t Grammar::ArrayDataTypeContext::getRuleIndex() const {
  return Grammar::RuleArrayDataType;
}

void Grammar::ArrayDataTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArrayDataType(this);
}

void Grammar::ArrayDataTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArrayDataType(this);
}


std::any Grammar::ArrayDataTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GrammarVisitor*>(visitor))
    return parserVisitor->visitArrayDataType(this);
  else
    return visitor->visitChildren(this);
}

Grammar::ArrayDataTypeContext* Grammar::arrayDataType() {
  ArrayDataTypeContext *_localctx = _tracker.createInstance<ArrayDataTypeContext>(_ctx, getState());
  enterRule(_localctx, 78, Grammar::RuleArrayDataType);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(374);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 248) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool Grammar::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 10: return binaryExpressionSempred(antlrcpp::downCast<BinaryExpressionContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool Grammar::binaryExpressionSempred(BinaryExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 2);
    case 1: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

void Grammar::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  grammarParserInitialize();
#else
  ::antlr4::internal::call_once(grammarParserOnceFlag, grammarParserInitialize);
#endif
}
