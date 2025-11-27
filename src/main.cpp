//
// Created by Brayhan De Aza on 11/27/25.
//

#include "cromio.h"


int main(int argc, const char* argv[]) {
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

    Grammar grammar(&tokens);
    auto* tree = grammar.program();

    cromio::parser::Parser visitor;
    auto ast = std::any_cast<json>(visitor.visit(tree));

    // std::cout << "ast: " << ast.dump(4) << std::endl;

    // Generate IR
    cromio::lowering::IR ir("main_module");
    llvm::Module* module = ir.generate(ast);

    // Bytecode
    // BytecodeEmitter::toFile(*module, "output.bc");
    std::vector<uint8_t> bc = cromio::backend::BytecodeEmitter::toMemory(*module);
    std::cout << "bc size: " << bc.size() << std::endl;

    return 0;
}