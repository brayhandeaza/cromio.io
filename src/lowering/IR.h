//
// Created by Brayhan De Aza on 11/24/25.
//

#ifndef CROMIO_IR_H
#define CROMIO_IR_H

#include <string>
#include <utils/Helpers.h>

#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"

namespace cromio::lowering {
    class IR
    {
    public:
        explicit IR(const std::string& moduleName = "module");

        llvm::Module* generate(const json& ast);
        [[nodiscard]] llvm::Module* getModule() const { return module.get(); }

    private:
        std::unique_ptr<llvm::LLVMContext> context;
        std::unique_ptr<llvm::Module> module;
        std::unique_ptr<llvm::IRBuilder<>> builder;


        llvm::Value* codegenProgram(const json& node);
        llvm::Value* codegenStatement(const json& node);
        llvm::Value* codegenExpression(const json& node);
        llvm::Constant* codegenLiteral(const json& node) const;

        llvm::Value* promoteToDouble(llvm::Value* v) const;
        llvm::Type* inferType(const json& node) const;
    };

}



#endif //CROMIO_IR_H
