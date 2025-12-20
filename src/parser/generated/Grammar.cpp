
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
      "arrays", "arrayDeclaration", "arrayItems", "arrayReAssignment", "arrayType", 
      "arrayDeclarationTypeSize", "arrayDataType"
    },
    std::vector<std::string>{
      "", "'dict'", "'bool'", "'str'", "", "", "", "", "", "", "", "", "", 
      "", "'%'", "'='", "", "", "", "", "'['", "']'", "'.'", "','", "'&'", 
      "'<'", "'>'", "':'", "", "", "", "", "", "", "", "", "", "'f\"'", 
      "", "", "'\"'"
    },
    std::vector<std::string>{
      "", "DICT_KEYWORD", "BOOLEAN_TYPES", "STRING_TYPES", "INTEGER_TYPES", 
      "UNSIGNED_INTEGER_TYPES", "FLOAT_TYPES", "NONE", "BOOLEAN", "IDENTIFIER", 
      "PLUS", "MINUS", "MUL", "DIV", "MOD", "EQ", "LPAREN", "RPAREN", "LBRACE", 
      "RBRACE", "LBRACKET", "RBRACKET", "DOT", "COMMA", "AMPERSAND", "LESSTHAN", 
      "GREATERTHAN", "COLON", "NEWLINE", "NEWLINE_VISIBLE", "WS_VISIBLE", 
      "COMMENT", "BLOCK_COMMENT", "WS", "FLOAT", "INTEGER", "STRING", "FORMATTED_STRING_START", 
      "FORMATTED_STRING_TEXT", "LBRACE_IN_FSTRING", "FORMATTED_STRING_END", 
      "RBRACE_IN_FSTRING", "EXPR_WS"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,42,354,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,7,
  	28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,2,33,7,33,2,34,7,34,2,35,7,
  	35,2,36,7,36,2,37,7,37,1,0,5,0,78,8,0,10,0,12,0,81,9,0,1,0,1,0,5,0,85,
  	8,0,10,0,12,0,88,9,0,5,0,90,8,0,10,0,12,0,93,9,0,1,0,1,0,1,1,1,1,1,1,
  	1,1,1,1,1,1,1,1,3,1,104,8,1,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,
  	2,3,2,117,8,2,5,2,119,8,2,10,2,12,2,122,9,2,3,2,124,8,2,1,2,1,2,1,3,1,
  	3,1,3,1,3,1,4,1,4,1,4,1,4,1,5,1,5,3,5,138,8,5,1,6,1,6,1,6,3,6,143,8,6,
  	1,6,1,6,1,7,1,7,1,8,1,8,1,8,1,8,1,8,3,8,154,8,8,1,9,1,9,1,9,5,9,159,8,
  	9,10,9,12,9,162,9,9,4,9,164,8,9,11,9,12,9,165,1,10,1,10,1,10,1,10,1,10,
  	1,10,3,10,174,8,10,1,10,1,10,1,10,1,10,1,10,1,10,5,10,182,8,10,10,10,
  	12,10,185,9,10,1,11,1,11,1,11,1,11,3,11,191,8,11,1,12,1,12,1,12,3,12,
  	196,8,12,1,13,1,13,1,13,3,13,201,8,13,1,14,1,14,5,14,205,8,14,10,14,12,
  	14,208,9,14,1,14,1,14,1,15,1,15,1,15,1,15,1,15,3,15,217,8,15,1,16,1,16,
  	1,17,1,17,1,18,1,18,1,19,1,19,1,20,1,20,1,21,1,21,1,22,1,22,5,22,233,
  	8,22,10,22,12,22,236,9,22,1,23,1,23,1,23,1,23,3,23,242,8,23,1,23,3,23,
  	245,8,23,1,24,1,24,1,24,5,24,250,8,24,10,24,12,24,253,9,24,1,25,1,25,
  	1,25,1,25,1,25,1,25,1,25,1,25,1,25,1,25,1,25,1,25,1,25,1,25,3,25,269,
  	8,25,1,26,1,26,1,26,3,26,274,8,26,1,27,1,27,1,27,1,27,1,27,1,27,1,27,
  	1,28,1,28,1,28,1,29,1,29,1,29,1,29,1,30,1,30,1,31,1,31,3,31,294,8,31,
  	1,32,1,32,1,32,1,32,1,32,1,32,1,32,1,32,1,32,5,32,305,8,32,10,32,12,32,
  	308,9,32,3,32,310,8,32,1,32,1,32,1,33,1,33,1,33,1,33,1,33,1,33,1,33,1,
  	33,1,33,1,33,3,33,324,8,33,1,34,1,34,1,34,1,34,1,34,1,34,5,34,332,8,34,
  	10,34,12,34,335,9,34,3,34,337,8,34,1,34,1,34,1,35,1,35,1,35,1,35,1,35,
  	1,36,1,36,3,36,348,8,36,1,36,1,36,1,37,1,37,1,37,0,1,20,38,0,2,4,6,8,
  	10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,42,44,46,48,50,52,54,
  	56,58,60,62,64,66,68,70,72,74,0,3,1,0,2,6,1,0,12,14,1,0,10,11,372,0,79,
  	1,0,0,0,2,103,1,0,0,0,4,105,1,0,0,0,6,127,1,0,0,0,8,131,1,0,0,0,10,137,
  	1,0,0,0,12,139,1,0,0,0,14,146,1,0,0,0,16,153,1,0,0,0,18,163,1,0,0,0,20,
  	173,1,0,0,0,22,190,1,0,0,0,24,195,1,0,0,0,26,200,1,0,0,0,28,202,1,0,0,
  	0,30,216,1,0,0,0,32,218,1,0,0,0,34,220,1,0,0,0,36,222,1,0,0,0,38,224,
  	1,0,0,0,40,226,1,0,0,0,42,228,1,0,0,0,44,230,1,0,0,0,46,244,1,0,0,0,48,
  	246,1,0,0,0,50,268,1,0,0,0,52,273,1,0,0,0,54,275,1,0,0,0,56,282,1,0,0,
  	0,58,285,1,0,0,0,60,289,1,0,0,0,62,293,1,0,0,0,64,295,1,0,0,0,66,323,
  	1,0,0,0,68,325,1,0,0,0,70,340,1,0,0,0,72,345,1,0,0,0,74,351,1,0,0,0,76,
  	78,5,28,0,0,77,76,1,0,0,0,78,81,1,0,0,0,79,77,1,0,0,0,79,80,1,0,0,0,80,
  	91,1,0,0,0,81,79,1,0,0,0,82,86,3,2,1,0,83,85,5,28,0,0,84,83,1,0,0,0,85,
  	88,1,0,0,0,86,84,1,0,0,0,86,87,1,0,0,0,87,90,1,0,0,0,88,86,1,0,0,0,89,
  	82,1,0,0,0,90,93,1,0,0,0,91,89,1,0,0,0,91,92,1,0,0,0,92,94,1,0,0,0,93,
  	91,1,0,0,0,94,95,5,0,0,1,95,1,1,0,0,0,96,104,3,16,8,0,97,104,3,52,26,
  	0,98,104,3,62,31,0,99,104,3,4,2,0,100,104,3,44,22,0,101,104,3,38,19,0,
  	102,104,3,40,20,0,103,96,1,0,0,0,103,97,1,0,0,0,103,98,1,0,0,0,103,99,
  	1,0,0,0,103,100,1,0,0,0,103,101,1,0,0,0,103,102,1,0,0,0,104,3,1,0,0,0,
  	105,106,5,1,0,0,106,107,5,25,0,0,107,108,3,8,4,0,108,109,5,26,0,0,109,
  	110,5,9,0,0,110,111,5,15,0,0,111,123,5,18,0,0,112,120,3,6,3,0,113,114,
  	5,23,0,0,114,116,3,6,3,0,115,117,5,23,0,0,116,115,1,0,0,0,116,117,1,0,
  	0,0,117,119,1,0,0,0,118,113,1,0,0,0,119,122,1,0,0,0,120,118,1,0,0,0,120,
  	121,1,0,0,0,121,124,1,0,0,0,122,120,1,0,0,0,123,112,1,0,0,0,123,124,1,
  	0,0,0,124,125,1,0,0,0,125,126,5,19,0,0,126,5,1,0,0,0,127,128,3,22,11,
  	0,128,129,5,27,0,0,129,130,3,16,8,0,130,7,1,0,0,0,131,132,3,10,5,0,132,
  	133,5,23,0,0,133,134,3,10,5,0,134,9,1,0,0,0,135,138,3,12,6,0,136,138,
  	3,14,7,0,137,135,1,0,0,0,137,136,1,0,0,0,138,11,1,0,0,0,139,140,3,14,
  	7,0,140,142,5,20,0,0,141,143,3,16,8,0,142,141,1,0,0,0,142,143,1,0,0,0,
  	143,144,1,0,0,0,144,145,5,21,0,0,145,13,1,0,0,0,146,147,7,0,0,0,147,15,
  	1,0,0,0,148,154,3,18,9,0,149,154,3,20,10,0,150,154,3,24,12,0,151,154,
  	3,44,22,0,152,154,3,38,19,0,153,148,1,0,0,0,153,149,1,0,0,0,153,150,1,
  	0,0,0,153,151,1,0,0,0,153,152,1,0,0,0,154,17,1,0,0,0,155,160,3,26,13,
  	0,156,157,5,10,0,0,157,159,3,26,13,0,158,156,1,0,0,0,159,162,1,0,0,0,
  	160,158,1,0,0,0,160,161,1,0,0,0,161,164,1,0,0,0,162,160,1,0,0,0,163,155,
  	1,0,0,0,164,165,1,0,0,0,165,163,1,0,0,0,165,166,1,0,0,0,166,19,1,0,0,
  	0,167,168,6,10,-1,0,168,174,3,24,12,0,169,170,5,16,0,0,170,171,3,20,10,
  	0,171,172,5,17,0,0,172,174,1,0,0,0,173,167,1,0,0,0,173,169,1,0,0,0,174,
  	183,1,0,0,0,175,176,10,2,0,0,176,177,7,1,0,0,177,182,3,20,10,3,178,179,
  	10,1,0,0,179,180,7,2,0,0,180,182,3,20,10,2,181,175,1,0,0,0,181,178,1,
  	0,0,0,182,185,1,0,0,0,183,181,1,0,0,0,183,184,1,0,0,0,184,21,1,0,0,0,
  	185,183,1,0,0,0,186,191,3,24,12,0,187,191,3,26,13,0,188,191,3,38,19,0,
  	189,191,3,42,21,0,190,186,1,0,0,0,190,187,1,0,0,0,190,188,1,0,0,0,190,
  	189,1,0,0,0,191,23,1,0,0,0,192,196,3,34,17,0,193,196,3,36,18,0,194,196,
  	3,42,21,0,195,192,1,0,0,0,195,193,1,0,0,0,195,194,1,0,0,0,196,25,1,0,
  	0,0,197,201,3,32,16,0,198,201,3,28,14,0,199,201,3,42,21,0,200,197,1,0,
  	0,0,200,198,1,0,0,0,200,199,1,0,0,0,201,27,1,0,0,0,202,206,5,37,0,0,203,
  	205,3,30,15,0,204,203,1,0,0,0,205,208,1,0,0,0,206,204,1,0,0,0,206,207,
  	1,0,0,0,207,209,1,0,0,0,208,206,1,0,0,0,209,210,5,40,0,0,210,29,1,0,0,
  	0,211,217,5,38,0,0,212,213,5,39,0,0,213,214,3,16,8,0,214,215,5,41,0,0,
  	215,217,1,0,0,0,216,211,1,0,0,0,216,212,1,0,0,0,217,31,1,0,0,0,218,219,
  	5,36,0,0,219,33,1,0,0,0,220,221,5,35,0,0,221,35,1,0,0,0,222,223,5,34,
  	0,0,223,37,1,0,0,0,224,225,5,8,0,0,225,39,1,0,0,0,226,227,5,7,0,0,227,
  	41,1,0,0,0,228,229,5,9,0,0,229,43,1,0,0,0,230,234,3,50,25,0,231,233,3,
  	46,23,0,232,231,1,0,0,0,233,236,1,0,0,0,234,232,1,0,0,0,234,235,1,0,0,
  	0,235,45,1,0,0,0,236,234,1,0,0,0,237,238,5,22,0,0,238,245,3,42,21,0,239,
  	241,5,16,0,0,240,242,3,48,24,0,241,240,1,0,0,0,241,242,1,0,0,0,242,243,
  	1,0,0,0,243,245,5,17,0,0,244,237,1,0,0,0,244,239,1,0,0,0,245,47,1,0,0,
  	0,246,251,3,16,8,0,247,248,5,23,0,0,248,250,3,16,8,0,249,247,1,0,0,0,
  	250,253,1,0,0,0,251,249,1,0,0,0,251,252,1,0,0,0,252,49,1,0,0,0,253,251,
  	1,0,0,0,254,269,3,42,21,0,255,269,3,32,16,0,256,257,5,16,0,0,257,258,
  	3,38,19,0,258,259,5,17,0,0,259,269,1,0,0,0,260,261,5,16,0,0,261,262,3,
  	24,12,0,262,263,5,17,0,0,263,269,1,0,0,0,264,265,5,16,0,0,265,266,3,16,
  	8,0,266,267,5,17,0,0,267,269,1,0,0,0,268,254,1,0,0,0,268,255,1,0,0,0,
  	268,256,1,0,0,0,268,260,1,0,0,0,268,264,1,0,0,0,269,51,1,0,0,0,270,274,
  	3,54,27,0,271,274,3,56,28,0,272,274,3,58,29,0,273,270,1,0,0,0,273,271,
  	1,0,0,0,273,272,1,0,0,0,274,53,1,0,0,0,275,276,3,60,30,0,276,277,5,9,
  	0,0,277,278,5,15,0,0,278,279,6,27,-1,0,279,280,3,16,8,0,280,281,6,27,
  	-1,0,281,55,1,0,0,0,282,283,3,60,30,0,283,284,5,9,0,0,284,57,1,0,0,0,
  	285,286,5,9,0,0,286,287,5,15,0,0,287,288,3,16,8,0,288,59,1,0,0,0,289,
  	290,7,0,0,0,290,61,1,0,0,0,291,294,3,64,32,0,292,294,3,68,34,0,293,291,
  	1,0,0,0,293,292,1,0,0,0,294,63,1,0,0,0,295,296,6,32,-1,0,296,297,3,70,
  	35,0,297,298,6,32,-1,0,298,299,5,9,0,0,299,300,5,15,0,0,300,309,5,20,
  	0,0,301,306,3,66,33,0,302,303,5,23,0,0,303,305,3,66,33,0,304,302,1,0,
  	0,0,305,308,1,0,0,0,306,304,1,0,0,0,306,307,1,0,0,0,307,310,1,0,0,0,308,
  	306,1,0,0,0,309,301,1,0,0,0,309,310,1,0,0,0,310,311,1,0,0,0,311,312,5,
  	21,0,0,312,65,1,0,0,0,313,324,3,32,16,0,314,324,3,28,14,0,315,324,3,28,
  	14,0,316,324,3,42,21,0,317,324,3,34,17,0,318,324,3,36,18,0,319,324,3,
  	38,19,0,320,324,3,40,20,0,321,324,3,18,9,0,322,324,3,20,10,0,323,313,
  	1,0,0,0,323,314,1,0,0,0,323,315,1,0,0,0,323,316,1,0,0,0,323,317,1,0,0,
  	0,323,318,1,0,0,0,323,319,1,0,0,0,323,320,1,0,0,0,323,321,1,0,0,0,323,
  	322,1,0,0,0,324,67,1,0,0,0,325,326,5,9,0,0,326,327,5,15,0,0,327,336,5,
  	20,0,0,328,333,3,16,8,0,329,330,5,23,0,0,330,332,3,16,8,0,331,329,1,0,
  	0,0,332,335,1,0,0,0,333,331,1,0,0,0,333,334,1,0,0,0,334,337,1,0,0,0,335,
  	333,1,0,0,0,336,328,1,0,0,0,336,337,1,0,0,0,337,338,1,0,0,0,338,339,5,
  	21,0,0,339,69,1,0,0,0,340,341,3,74,37,0,341,342,5,20,0,0,342,343,3,72,
  	36,0,343,344,5,21,0,0,344,71,1,0,0,0,345,347,6,36,-1,0,346,348,3,16,8,
  	0,347,346,1,0,0,0,347,348,1,0,0,0,348,349,1,0,0,0,349,350,6,36,-1,0,350,
  	73,1,0,0,0,351,352,7,0,0,0,352,75,1,0,0,0,33,79,86,91,103,116,120,123,
  	137,142,153,160,165,173,181,183,190,195,200,206,216,234,241,244,251,268,
  	273,293,306,309,323,333,336,347
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
    setState(79);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == Grammar::NEWLINE) {
      setState(76);
      match(Grammar::NEWLINE);
      setState(81);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(91);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 257698104318) != 0)) {
      setState(82);
      statements();
      setState(86);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == Grammar::NEWLINE) {
        setState(83);
        match(Grammar::NEWLINE);
        setState(88);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(93);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(94);
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
    setState(103);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(96);
      expression();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(97);
      variables();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(98);
      arrays();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(99);
      dictionaryDeclaration();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(100);
      memberExpression();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(101);
      booleanLiteral();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(102);
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
    setState(105);
    match(Grammar::DICT_KEYWORD);
    setState(106);
    match(Grammar::LESSTHAN);
    setState(107);
    dictionaryDeclarationType();
    setState(108);
    match(Grammar::GREATERTHAN);
    setState(109);
    match(Grammar::IDENTIFIER);
    setState(110);
    match(Grammar::EQ);
    setState(111);
    match(Grammar::LBRACE);
    setState(123);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 257698038528) != 0)) {
      setState(112);
      dictionaryAssignmentBody();
      setState(120);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == Grammar::COMMA) {
        setState(113);
        match(Grammar::COMMA);
        setState(114);
        dictionaryAssignmentBody();
        setState(116);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
        case 1: {
          setState(115);
          match(Grammar::COMMA);
          break;
        }

        default:
          break;
        }
        setState(122);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(125);
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
    setState(127);
    literal();
    setState(128);
    match(Grammar::COLON);
    setState(129);
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
    setState(131);
    dictionaryTypeElement();
    setState(132);
    match(Grammar::COMMA);
    setState(133);
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
    setState(137);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(135);
      dictionaryDeclarationTypeArray();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(136);
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
    setState(139);
    dictionaryDataType();
    setState(140);
    match(Grammar::LBRACKET);
    setState(142);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 257698104064) != 0)) {
      setState(141);
      expression();
    }
    setState(144);
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
    setState(146);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 124) != 0))) {
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

Grammar::ConcatenationExpressionContext* Grammar::ExpressionContext::concatenationExpression() {
  return getRuleContext<Grammar::ConcatenationExpressionContext>(0);
}

Grammar::BinaryExpressionContext* Grammar::ExpressionContext::binaryExpression() {
  return getRuleContext<Grammar::BinaryExpressionContext>(0);
}

Grammar::NumberLiteralsContext* Grammar::ExpressionContext::numberLiterals() {
  return getRuleContext<Grammar::NumberLiteralsContext>(0);
}

Grammar::MemberExpressionContext* Grammar::ExpressionContext::memberExpression() {
  return getRuleContext<Grammar::MemberExpressionContext>(0);
}

Grammar::BooleanLiteralContext* Grammar::ExpressionContext::booleanLiteral() {
  return getRuleContext<Grammar::BooleanLiteralContext>(0);
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
    setState(153);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(148);
      concatenationExpression();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(149);
      binaryExpression(0);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(150);
      numberLiterals();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(151);
      memberExpression();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(152);
      booleanLiteral();
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
    setState(163); 
    _errHandler->sync(this);
    alt = 1;
    do {
      switch (alt) {
        case 1: {
              setState(155);
              stringLiterals();
              setState(160);
              _errHandler->sync(this);
              _la = _input->LA(1);
              while (_la == Grammar::PLUS) {
                setState(156);
                match(Grammar::PLUS);
                setState(157);
                stringLiterals();
                setState(162);
                _errHandler->sync(this);
                _la = _input->LA(1);
              }
              break;
            }

      default:
        throw NoViableAltException(this);
      }
      setState(165); 
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx);
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
    setState(173);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case Grammar::IDENTIFIER:
      case Grammar::FLOAT:
      case Grammar::INTEGER: {
        setState(168);
        numberLiterals();
        break;
      }

      case Grammar::LPAREN: {
        setState(169);
        match(Grammar::LPAREN);
        setState(170);
        binaryExpression(0);
        setState(171);
        match(Grammar::RPAREN);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(183);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(181);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<BinaryExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleBinaryExpression);
          setState(175);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(176);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & 28672) != 0))) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(177);
          binaryExpression(3);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<BinaryExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleBinaryExpression);
          setState(178);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(179);
          _la = _input->LA(1);
          if (!(_la == Grammar::PLUS

          || _la == Grammar::MINUS)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(180);
          binaryExpression(2);
          break;
        }

        default:
          break;
        } 
      }
      setState(185);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx);
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
    setState(190);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(186);
      numberLiterals();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(187);
      stringLiterals();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(188);
      booleanLiteral();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(189);
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

Grammar::IdentifierLiteralContext* Grammar::NumberLiteralsContext::identifierLiteral() {
  return getRuleContext<Grammar::IdentifierLiteralContext>(0);
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
    setState(195);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case Grammar::INTEGER: {
        enterOuterAlt(_localctx, 1);
        setState(192);
        integerLiteral();
        break;
      }

      case Grammar::FLOAT: {
        enterOuterAlt(_localctx, 2);
        setState(193);
        floatLiteral();
        break;
      }

      case Grammar::IDENTIFIER: {
        enterOuterAlt(_localctx, 3);
        setState(194);
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
    setState(200);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case Grammar::STRING: {
        enterOuterAlt(_localctx, 1);
        setState(197);
        stringLiteral();
        break;
      }

      case Grammar::FORMATTED_STRING_START: {
        enterOuterAlt(_localctx, 2);
        setState(198);
        formattedString();
        break;
      }

      case Grammar::IDENTIFIER: {
        enterOuterAlt(_localctx, 3);
        setState(199);
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
    setState(202);
    match(Grammar::FORMATTED_STRING_START);
    setState(206);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == Grammar::FORMATTED_STRING_TEXT

    || _la == Grammar::LBRACE_IN_FSTRING) {
      setState(203);
      formattedStringContent();
      setState(208);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(209);
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
    setState(216);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case Grammar::FORMATTED_STRING_TEXT: {
        enterOuterAlt(_localctx, 1);
        setState(211);
        match(Grammar::FORMATTED_STRING_TEXT);
        break;
      }

      case Grammar::LBRACE_IN_FSTRING: {
        enterOuterAlt(_localctx, 2);
        setState(212);
        match(Grammar::LBRACE_IN_FSTRING);
        setState(213);
        expression();
        setState(214);
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
    setState(218);
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
    setState(220);
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
    setState(222);
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
    setState(224);
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
    setState(226);
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
    setState(228);
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
    setState(230);
    valueAtom();
    setState(234);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(231);
        valuePostfix(); 
      }
      setState(236);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx);
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
    setState(244);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case Grammar::DOT: {
        enterOuterAlt(_localctx, 1);
        setState(237);
        match(Grammar::DOT);
        setState(238);
        identifierLiteral();
        break;
      }

      case Grammar::LPAREN: {
        enterOuterAlt(_localctx, 2);
        setState(239);
        match(Grammar::LPAREN);
        setState(241);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & 257698104064) != 0)) {
          setState(240);
          argumentList();
        }
        setState(243);
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
    setState(246);
    expression();
    setState(251);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == Grammar::COMMA) {
      setState(247);
      match(Grammar::COMMA);
      setState(248);
      expression();
      setState(253);
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
    setState(268);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(254);
      identifierLiteral();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(255);
      stringLiteral();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(256);
      match(Grammar::LPAREN);
      setState(257);
      booleanLiteral();
      setState(258);
      match(Grammar::RPAREN);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(260);
      match(Grammar::LPAREN);
      setState(261);
      numberLiterals();
      setState(262);
      match(Grammar::RPAREN);
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(264);
      match(Grammar::LPAREN);
      setState(265);
      expression();
      setState(266);
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
    setState(273);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(270);
      variableDeclaration();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(271);
      variableDeclarationWithoutAssignment();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(272);
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
    setState(275);
    variableDataType();
    setState(276);
    match(Grammar::IDENTIFIER);
    setState(277);
    match(Grammar::EQ);
    inVarMode= true;
    setState(279);
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
    setState(282);
    variableDataType();
    setState(283);
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
    setState(285);
    match(Grammar::IDENTIFIER);
    setState(286);
    match(Grammar::EQ);
    setState(287);
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
    setState(289);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 124) != 0))) {
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
    setState(293);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case Grammar::BOOLEAN_TYPES:
      case Grammar::STRING_TYPES:
      case Grammar::INTEGER_TYPES:
      case Grammar::UNSIGNED_INTEGER_TYPES:
      case Grammar::FLOAT_TYPES: {
        enterOuterAlt(_localctx, 1);
        setState(291);
        arrayDeclaration();
        break;
      }

      case Grammar::IDENTIFIER: {
        enterOuterAlt(_localctx, 2);
        setState(292);
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

tree::TerminalNode* Grammar::ArrayDeclarationContext::LBRACKET() {
  return getToken(Grammar::LBRACKET, 0);
}

tree::TerminalNode* Grammar::ArrayDeclarationContext::RBRACKET() {
  return getToken(Grammar::RBRACKET, 0);
}

std::vector<Grammar::ArrayItemsContext *> Grammar::ArrayDeclarationContext::arrayItems() {
  return getRuleContexts<Grammar::ArrayItemsContext>();
}

Grammar::ArrayItemsContext* Grammar::ArrayDeclarationContext::arrayItems(size_t i) {
  return getRuleContext<Grammar::ArrayItemsContext>(i);
}

std::vector<tree::TerminalNode *> Grammar::ArrayDeclarationContext::COMMA() {
  return getTokens(Grammar::COMMA);
}

tree::TerminalNode* Grammar::ArrayDeclarationContext::COMMA(size_t i) {
  return getToken(Grammar::COMMA, i);
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
    inSkipMode = true;
    setState(296);
    arrayType();
    inSkipMode = false;
    setState(298);
    match(Grammar::IDENTIFIER);
    setState(299);
    match(Grammar::EQ);
    setState(300);
    match(Grammar::LBRACKET);
    setState(309);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 257698104192) != 0)) {
      setState(301);
      arrayItems();
      setState(306);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == Grammar::COMMA) {
        setState(302);
        match(Grammar::COMMA);
        setState(303);
        arrayItems();
        setState(308);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(311);
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
  enterRule(_localctx, 66, Grammar::RuleArrayItems);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(323);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 29, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(313);
      stringLiteral();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(314);
      formattedString();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(315);
      formattedString();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(316);
      identifierLiteral();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(317);
      integerLiteral();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(318);
      floatLiteral();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(319);
      booleanLiteral();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(320);
      noneLiteral();
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(321);
      concatenationExpression();
      break;
    }

    case 10: {
      enterOuterAlt(_localctx, 10);
      setState(322);
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
  enterRule(_localctx, 68, Grammar::RuleArrayReAssignment);
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
    setState(325);
    match(Grammar::IDENTIFIER);
    setState(326);
    match(Grammar::EQ);
    setState(327);
    match(Grammar::LBRACKET);
    setState(336);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 257698104064) != 0)) {
      setState(328);
      expression();
      setState(333);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == Grammar::COMMA) {
        setState(329);
        match(Grammar::COMMA);
        setState(330);
        expression();
        setState(335);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(338);
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
  enterRule(_localctx, 70, Grammar::RuleArrayType);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(340);
    arrayDataType();
    setState(341);
    match(Grammar::LBRACKET);
    setState(342);
    arrayDeclarationTypeSize();
    setState(343);
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
  enterRule(_localctx, 72, Grammar::RuleArrayDeclarationTypeSize);
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
    setState(347);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 257698104064) != 0)) {
      setState(346);
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
  enterRule(_localctx, 74, Grammar::RuleArrayDataType);
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
    setState(351);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 124) != 0))) {
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
