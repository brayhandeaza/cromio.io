//
// Created by Brayhan De Aza on 11/27/25.
//

#include "bytecode.h"


#include "llvm/Bitcode/BitcodeWriter.h"
#include "llvm/Support/raw_ostream.h"
#include <fstream>

std::vector<uint8_t> Bytecode::toMemory(const llvm::Module& module) {
    llvm::SmallVector<char, 0> buffer;
    llvm::raw_svector_ostream stream(buffer);

    llvm::WriteBitcodeToFile(module, stream);

    return std::vector<uint8_t>(buffer.begin(), buffer.end());
}

void Bytecode::toFile(const llvm::Module& module, const std::string& filename) {
    llvm::SmallVector<char, 0> buffer;
    llvm::raw_svector_ostream stream(buffer);

    llvm::WriteBitcodeToFile(module, stream);

    std::ofstream out(filename, std::ios::binary);
    if (!out)
        throw std::runtime_error("Failed to open output file: " + filename);

    out.write(buffer.data(), buffer.size());
    out.close();
}