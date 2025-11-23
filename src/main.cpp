#include <iostream>
#include <fstream>
#include <sstream>

#include "antlr4-runtime.h"
#include "Tokens.h"
#include "Grammar.h"
#include "../includes/Parser/Parser.h"

int main(int argc, const char *argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <input-file>" << std::endl;
        return 1;
    }

    // Read file content
    std::ifstream file(argv[1]);
    if (!file) {
        std::cerr << "Error: Could not open file " << argv[1] << std::endl;
        return 1;
    }

    std::stringstream buffer;
    buffer << file.rdbuf();
    std::string content = buffer.str();

    // // Feed into ANTLR
    antlr4::ANTLRInputStream input(content);

    Tokens lexer(&input);
    antlr4::CommonTokenStream tokens(&lexer);
    Grammar parser(&tokens);

    auto *tree = parser.program();

    Parser visitor;
    auto ast = std::any_cast<json>(visitor.visit(tree));

    // std::cout << "ast: " << ast.dump(1)<< std::endl;

    return 0;
}
