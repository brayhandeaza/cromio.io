//
// Created by Brayhan De Aza on 11/27/25.
//


#include "backend/BytecodeEmitter.h"

#include <llvm/Support/raw_ostream.h>
#include <fstream>
#include <llvm/IR/Module.h>
#include <llvm/Bitcode/BitcodeWriter.h>


std::vector<uint8_t> cromio::backend::BytecodeEmitter::toMemory(const llvm::Module& module) {
    llvm::SmallVector<char, 0> buffer;
    llvm::raw_svector_ostream stream(buffer);

    llvm::WriteBitcodeToFile(module, stream);

    return {buffer.begin(), buffer.end()};
}

void cromio::backend::BytecodeEmitter::toFile(const llvm::Module& module, const std::string& filename) {
    llvm::SmallVector<char, 0> buffer;
    llvm::raw_svector_ostream stream(buffer);

    llvm::WriteBitcodeToFile(module, stream);

    std::ofstream out(filename, std::ios::binary);
    if (!out)
        throw std::runtime_error("Failed to open output file: " + filename);

    out.write(buffer.data(), static_cast<std::streamsize>(buffer.size()));
    out.close();
}