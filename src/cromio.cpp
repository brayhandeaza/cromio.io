//
// Created by Brayhan De Aza on 11/27/25.
//

#include "cromio.h"

#include <visitor/ProgramVisitor.h>
#include <visitor/visitor.h>

int main(int argc, const char* argv[]) {
    // ---------------------------------------------
    // Load input file
    // ---------------------------------------------
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

    std::string filenamePath = argv[1];
    std::string fileName = filenamePath.substr(filenamePath.find_last_of('/') + 1);

    std::stringstream buffer;
    buffer << file.rdbuf();
    std::string content = buffer.str();

    // ---------------------------------------------
    // Feed file content into  ANTLR
    // ---------------------------------------------
    antlr4::ANTLRInputStream input(content);

    Tokens lexer(&input);
    antlr4::CommonTokenStream tokens(&lexer);
    Grammar grammar(&tokens);

    lexer.removeErrorListeners();
    grammar.removeErrorListeners();

    cromio::utils::AntlrErrorListener errorListener(content);
    lexer.addErrorListener(&errorListener);
    grammar.addErrorListener(&errorListener);

    auto* tree = grammar.program();

    cromio::visitor::Visitor visitor(content);
    auto ast = std::any_cast<json>(visitor.visit(tree));
    std::cout << ast.dump(1) << std::endl;

    // ---------------------------------------------
    // Emit LLVM IR from AST
    // ---------------------------------------------
    cromio::lowering::IR ir(fileName);
    llvm::Module* module = ir.generate(ast);

    // ---------------------------------------------
    // Emit LLVM Bytecode to memory or to file
    // ---------------------------------------------
    std::vector<uint8_t> bc = cromio::backend::BytecodeEmitter::toMemory(*module);
    module->print(llvm::outs(), nullptr);
    return 0;
}