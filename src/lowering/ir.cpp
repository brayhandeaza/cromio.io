//
// Created by Brayhan De Aza on 11/25/25.
//

#include <stdexcept>
#include "llvm/IR/Verifier.h"
#include "ir.h"

IR::IR(const std::string& moduleName) {
    context = std::make_unique<llvm::LLVMContext>();
    module = std::make_unique<llvm::Module>(moduleName, *context);
    builder = std::make_unique<llvm::IRBuilder<>>(*context);
}

llvm::Value* IR::promoteToDouble(llvm::Value* v) const {
    if (v->getType()->isDoubleTy())
        return v;

    if (v->getType()->isIntegerTy())
        return builder->CreateSIToFP(v, builder->getDoubleTy(), "int_to_double");

    throw std::runtime_error("Cannot promote value to double");
}

llvm::Type* IR::inferType(const json& node) const {
    const std::string kind = node.value("kind", "");

    // Literals
    if (kind == "FloatLiteral")
        return builder->getDoubleTy();
    if (kind == "IntegerLiteral")
        return builder->getInt64Ty();
    if (kind == "BooleanLiteral")
        return builder->getInt1Ty();

    // Expression (binary)
    if (kind == "Expression") {
        // Infer left and right
        const llvm::Type* L = inferType(node["left"]);
        const llvm::Type* R = inferType(node["right"]);

        // If either is double -> result is double (promote ints to double)
        if (L->isDoubleTy() || R->isDoubleTy())
            return builder->getDoubleTy();

        // Otherwise, integer ops yield integer
        if (L->isIntegerTy() && R->isIntegerTy())
            return builder->getInt64Ty();

        throw std::runtime_error("Unsupported operand types in expression for inferType");
    }

    // A Statement wrapper: extract inner Expression's type
    if (kind == "Statement") {
        if (!node.contains("Expression"))
            throw std::runtime_error("Statement missing Expression in inferType");
        return inferType(node["Expression"]);
    }

    throw std::runtime_error("Unknown node kind in inferType: " + kind);
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
        double v = node.value("value", 0.0);
        return llvm::ConstantFP::get(builder->getDoubleTy(), v);
    }

    if (kind == "IntegerLiteral") {
        long long v = node.value("value", 0LL);
        return llvm::ConstantInt::get(builder->getInt64Ty(), v, true);
    }

    if (kind == "BooleanLiteral") {
        bool b = node.value("value", false);
        return llvm::ConstantInt::get(builder->getInt1Ty(), b);
    }

    throw std::runtime_error("Unknown literal: " + kind);
}


// ---------------------------------------------
// Expression
// ---------------------------------------------
llvm::Value* IR::codegenExpression(const json& node) {
    const std::string kind = node.value("kind", "");

    // Literals
    if (kind == "FloatLiteral" || kind == "IntegerLiteral" || kind == "BooleanLiteral")
        return codegenLiteral(node);

    // Binary expression
    if (kind == "Expression") {
        llvm::Value* L = codegenExpression(node["left"]);
        llvm::Value* R = codegenExpression(node["right"]);
        const std::string op = node.value("operator", "");

        bool isFloat =
            L->getType()->isDoubleTy() ||
            R->getType()->isDoubleTy();

        // Promote if needed
        if (isFloat) {
            L = promoteToDouble(L);
            R = promoteToDouble(R);

            if (op == "+")
                return builder->CreateFAdd(L, R, "fadd");
            if (op == "-")
                return builder->CreateFSub(L, R, "fsub");
            if (op == "*")
                return builder->CreateFMul(L, R, "fmul");
            if (op == "/")
                return builder->CreateFDiv(L, R, "fdiv");
        } else {
            // Integer ops
            if (op == "+")
                return builder->CreateAdd(L, R, "add");
            if (op == "-")
                return builder->CreateSub(L, R, "sub");
            if (op == "*")
                return builder->CreateMul(L, R, "mul");
            if (op == "/")
                return builder->CreateSDiv(L, R, "sdiv");
        }

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
// Creates:   double @main()
// ---------------------------------------------
llvm::Value* IR::codegenProgram(const json& node) {
    if (node.value("kind", "") != "Program")
        throw std::runtime_error("Top-level node must be Program");

    auto& body = node["Body"];
    if (!body.is_array() || body.empty())
        throw std::runtime_error("Program Body missing or empty");

    // Infer return type from AST WITHOUT emitting IR
    llvm::Type* retType = inferType(body[0]);

    // Create main function with inferred return type
    auto* fnType = llvm::FunctionType::get(retType, false);
    auto* fn = llvm::Function::Create(fnType, llvm::Function::ExternalLinkage, "main", module.get());

    // Create entry block and set insertion point for IR emission
    auto* entry = llvm::BasicBlock::Create(*context, "entry", fn);
    builder->SetInsertPoint(entry);

    // Now actually generate the statement (this emits IR)
    llvm::Value* retVal = codegenStatement(body[0]);

    // If the emitted value type differs from declared return type, attempt safe conversions
    if (retVal->getType() != retType) {
        if (retVal->getType()->isIntegerTy() && retType->isDoubleTy()) {
            retVal = builder->CreateSIToFP(retVal, builder->getDoubleTy(), "ret_int_to_fp");
        } else if (retVal->getType()->isDoubleTy() && retType->isIntegerTy()) {
            // narrowing double -> int is lossy; better to error, but here's a truncation
            retVal = builder->CreateFPToSI(retVal, retType, "ret_fp_to_int");
        } else {
            throw std::runtime_error("Cannot convert return value to function return type");
        }
    }

    builder->CreateRet(retVal);

    // Verify function and emit diagnostics if broken
    if (llvm::verifyFunction(*fn, &llvm::errs()))
        throw std::runtime_error("IR verification failed");

    return fn;
}