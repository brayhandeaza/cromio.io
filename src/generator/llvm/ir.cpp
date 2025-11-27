//
// Created by Brayhan De Aza on 11/25/25.
//

#include <stdexcept>
#include "llvm/IR/Verifier.h"
#include "generator/llvm/ir.h"

IR::IR(const std::string& moduleName) {
    context = std::make_unique<llvm::LLVMContext>();
    module  = std::make_unique<llvm::Module>(moduleName, *context);
    builder = std::make_unique<llvm::IRBuilder<>>(*context);
}

// ---------------------------------------------
// Public: main entry point
// ---------------------------------------------
llvm::Module* IR::generate(const json& ast) {
    codegenProgram(ast);
    return module.get();
}

// ---------------------------------------------
// Literals → LLVM double constants
// ---------------------------------------------
llvm::Constant* IR::codegenLiteral(const json& node) const {
    const std::string kind = node.value("kind", "");

    if (kind == "FloatLiteral") {
        return llvm::ConstantFP::get(builder->getDoubleTy(), node.value("value", 0.0));
    }
    if (kind == "IntegerLiteral") {
        return llvm::ConstantFP::get(builder->getDoubleTy(), (double)node.value("value", 0));
    }
    if (kind == "BooleanLiteral") {
        bool b = node.value("value", false);
        return llvm::ConstantFP::get(builder->getDoubleTy(), b ? 1.0 : 0.0);
    }

    throw std::runtime_error("Unknown literal: " + kind);
}

// ---------------------------------------------
// Expression
// ---------------------------------------------
llvm::Value* IR::codegenExpression(const json& node) {
    const std::string kind = node.value("kind", "");

    // Literal
    if (kind == "FloatLiteral" || kind == "IntegerLiteral" || kind == "BooleanLiteral")
        return codegenLiteral(node);

    // Binary Expression
    if (kind == "Expression") {
        llvm::Value* L = codegenExpression(node["left"]);
        llvm::Value* R = codegenExpression(node["right"]);
        const std::string op = node.value("operator", "");

        // Ensure both are double
        if (!L->getType()->isDoubleTy())
            L = builder->CreateFPCast(L, builder->getDoubleTy());
        if (!R->getType()->isDoubleTy())
            R = builder->CreateFPCast(R, builder->getDoubleTy());

        if (op == "+") return builder->CreateFAdd(L, R, "addtmp");
        if (op == "-") return builder->CreateFSub(L, R, "subtmp");
        if (op == "*") return builder->CreateFMul(L, R, "multmp");
        if (op == "/") return builder->CreateFDiv(L, R, "divtmp");

        throw std::runtime_error("Unknown operator: " + op);
    }

    throw std::runtime_error("Invalid expression node: " + kind);
}

// ---------------------------------------------
// Statement → Expression
// ---------------------------------------------
llvm::Value* IR::codegenStatement(const json& node) {
    if (!node.contains("Expression"))
        throw std::runtime_error("Statement missing Expression");

    return codegenExpression(node["Expression"]);
}

// ---------------------------------------------
// Program (entry point)
// Creates:   double @main_expr()
// ---------------------------------------------
llvm::Value* IR::codegenProgram(const json& node) {
    if (node.value("kind", "") != "Program")
        throw std::runtime_error("Top-level node must be Program");

    auto& body = node["Body"];
    if (!body.is_array() || body.empty())
        throw std::runtime_error("Program Body missing or empty");

    // Create function
    auto* fnType = llvm::FunctionType::get(builder->getDoubleTy(), false);
    auto* fn = llvm::Function::Create(
        fnType,
        llvm::Function::ExternalLinkage,
        "main_expr",
        module.get()
    );

    auto* entry = llvm::BasicBlock::Create(*context, "entry", fn);
    builder->SetInsertPoint(entry);

    llvm::Value* retVal = codegenStatement(body[0]);
    if (!retVal->getType()->isDoubleTy()) {
        retVal = builder->CreateFPCast(retVal, builder->getDoubleTy());
    }

    builder->CreateRet(retVal);

    // Verify function
    if (llvm::verifyFunction(*fn)) {
        throw std::runtime_error("IR verification failed");
    }

    return fn;
}

