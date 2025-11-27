//
// Created by Brayhan De Aza on 11/27/25.
//

#ifndef CROMIO_BYTECODE_EMITTER_H
#define CROMIO_BYTECODE_EMITTER_H

#include <string>
#include <vector>
#include <llvm/IR/Module.h>

class BytecodeEmitter {
public:
    // Generate LLVM bitcode into a vector of bytes (in memory)
    static std::vector<uint8_t> toMemory(const llvm::Module& module);

    // Write LLVM bitcode to a .bc file
    static void toFile(const llvm::Module& module, const std::string& filename);
};


#endif //CROMIO_BYTECODE_EMITTER_H