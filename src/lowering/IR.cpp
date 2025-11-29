//
// Created by Brayhan De Aza on 11/25/25.
//

#include <stdexcept>
#include <string>
#include "llvm/IR/Verifier.h"
#include "IR.h"

using namespace cromio::lowering;

// ---------------------------------------------
// Constructor
// ---------------------------------------------
IR::IR(const std::string& moduleName) {
    context = std::make_unique<llvm::LLVMContext>();
    module = std::make_unique<llvm::Module>(moduleName, *context);
    builder = std::make_unique<llvm::IRBuilder<>>(*context);
}

// ---------------------------------------------
// Map DataType string from AST to LLVM Type
// ---------------------------------------------
llvm::Type* IR::mapDataType(const std::string& t) const {
    if (t == "int")
        return builder->getInt64Ty();
    if (t == "float")
        return builder->getDoubleTy();
    if (t == "bool")
        return builder->getInt1Ty();
    if (t == "none")
        return builder->getInt8Ty();
    // default: treat unknown as i64 to keep main sane
    return builder->getInt64Ty();
}

// ---------------------------------------------
// Type Promotion
// ---------------------------------------------
llvm::Value* IR::promoteToDouble(llvm::Value* v) const {
    if (v->getType()->isDoubleTy())
        return v;

    if (v->getType()->isIntegerTy())
        return builder->CreateSIToFP(v, builder->getDoubleTy(), "int_to_double");

    throw std::runtime_error("Cannot promote value to double");
}

// ---------------------------------------------
// Type Inference (WITH VARIABLEDECLARATION support)
// ---------------------------------------------
llvm::Type* IR::inferType(const json& node) const {
    const std::string kind = node.value("kind", "");

    // ─── Literals ─────────────────────────────────────────────
    if (kind == "FloatLiteral")
        return builder->getDoubleTy();
    if (kind == "IntegerLiteral")
        return builder->getInt64Ty();
    if (kind == "BooleanLiteral")
        return builder->getInt1Ty();
    if (kind == "NoneLiteral")
        return builder->getInt8Ty();
    if (kind == "StringLiteral" || kind == "StringFormatted")
        return llvm::PointerType::get(*context, 0);

    // ─── VariableDeclaration ──────────────────────────────────
    if (kind == "VariableDeclaration") {
        // Expect DataType.value to be a string like "int", "float", etc.
        if (!node.contains("DataType") || !node["DataType"].contains("value"))
            throw std::runtime_error("VariableDeclaration missing DataType");
        std::string dtype = node["DataType"].value("value", "int");
        return mapDataType(dtype);
    }

    // ─── Binary Expression ────────────────────────────────────
    if (kind == "Expression") {
        auto* LT = inferType(node["left"]);
        auto* RT = inferType(node["right"]);

        if (LT->isDoubleTy() || RT->isDoubleTy())
            return builder->getDoubleTy();

        if (LT->isIntegerTy() && RT->isIntegerTy())
            return builder->getInt64Ty();

        throw std::runtime_error("Unsupported operand types in Expression");
    }

    throw std::runtime_error("Unknown node kind in inferType: " + kind);
}

// ---------------------------------------------
// Main entry
// ---------------------------------------------
llvm::Module* IR::generate(const json& ast) {
    codegenProgram(ast);
    return module.get();
}

// ---------------------------------------------
// Literals → LLVM Constants
// ---------------------------------------------
llvm::Constant* IR::codegenLiteral(const json& node) const {
    const std::string kind = node.value("kind", "");

    if (kind == "FloatLiteral")
        return llvm::ConstantFP::get(builder->getDoubleTy(),
                                     node.value("value", 0.0));

    if (kind == "IntegerLiteral")
        return llvm::ConstantInt::get(builder->getInt64Ty(),
                                      (long long)node.value("value", 0LL),
                                      true);

    if (kind == "BooleanLiteral")
        return llvm::ConstantInt::get(builder->getInt1Ty(),
                                      node.value("value", false));

    if (kind == "NoneLiteral")
        return llvm::ConstantInt::get(builder->getInt8Ty(), 0);

    if (kind == "StringLiteral" || kind == "StringFormatted")
        return builder->CreateGlobalString(node.value("value", ""), "str");

    throw std::runtime_error("Unknown literal type: " + kind);
}

// ---------------------------------------------
// Expression
// ---------------------------------------------
llvm::Value* IR::codegenExpression(const json& node) {
    const std::string kind = node.value("kind", "");

    // ─── Literals ────────────────────────────────
    if (kind == "FloatLiteral" || kind == "IntegerLiteral"
        || kind == "BooleanLiteral" || kind == "NoneLiteral"
        || kind == "StringLiteral" || kind == "StringFormatted")
        return codegenLiteral(node);

    // If it's a VariableIdentifier (loading a variable) — not required by your current request,
    // but handle gracefully by trying to create an error since we have no symbol table.
    if (kind == "VariableIdentifier") {
        // Without a symbol table we cannot load previously-allocated variables.
        // To keep behaviour explicit: error out.
        throw std::runtime_error("VariableIdentifier encountered but no symbol table exists to resolve it");
    }

    // ─── Binary Expression ───────────────────────
    if (kind == "Expression") {
        llvm::Value* L = codegenExpression(node["left"]);
        llvm::Value* R = codegenExpression(node["right"]);
        const std::string op = node.value("operator", "");

        // Float promotion
        if (L->getType()->isDoubleTy() || R->getType()->isDoubleTy()) {
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
        }

        // Integer ops
        if (op == "+")
            return builder->CreateAdd(L, R, "add");
        if (op == "-")
            return builder->CreateSub(L, R, "sub");
        if (op == "*")
            return builder->CreateMul(L, R, "mul");
        if (op == "/")
            return builder->CreateSDiv(L, R, "sdiv");

        throw std::runtime_error("Unknown operator: " + op);
    }

    // If we encounter a VariableDeclaration here, it should be handled at program level,
    // but in case it appears inside an expression, return nullptr/error.
    if (kind == "VariableDeclaration")
        throw std::runtime_error("VariableDeclaration cannot appear inside an expression");

    throw std::runtime_error("Invalid expression node: " + kind);
}

// ---------------------------------------------
// Generate an alloca in the entry block and store initializer
// (NO symbol table is created; we simply allocate+store so the module is valid)
// ---------------------------------------------
llvm::Value* IR::codegenVariableDeclaration(const json& node) {
    // node must contain DataType, Identifier, value
    if (!node.contains("DataType") || !node.contains("Identifier") || !node.contains("value"))
        throw std::runtime_error("Malformed VariableDeclaration node");

    std::string varName = node["Identifier"].value("value", "");
    std::string dtype = node["DataType"].value("value", "int");

    llvm::Type* varType = mapDataType(dtype);

    // Ensure we are inside a function
    llvm::Function* currentFn = builder->GetInsertBlock()->getParent();
    if (!currentFn)
        throw std::runtime_error("No current function to allocate variable in");

    // Create an IRBuilder positioned at the entry block to emit alloca
    llvm::IRBuilder<> tmpBuilder(&currentFn->getEntryBlock(),
                                 currentFn->getEntryBlock().begin());

    llvm::AllocaInst* allocaInst = tmpBuilder.CreateAlloca(varType, nullptr, varName);

    // Evaluate initializer
    llvm::Value* initVal = codegenExpression(node["value"]);
    if (!initVal)
        throw std::runtime_error("Variable initializer produced null");

    // If initializer type doesn't match declared type, try safe conversion
    if (initVal->getType() != varType) {
        if (initVal->getType()->isIntegerTy() && varType->isDoubleTy()) {
            initVal = builder->CreateSIToFP(initVal, varType, "init_int_to_fp");
        } else if (initVal->getType()->isDoubleTy() && varType->isIntegerTy()) {
            initVal = builder->CreateFPToSI(initVal, varType, "init_fp_to_int");
        } else {
            // If other mismatches exist, attempt bitcast if pointer-like OR error
            if (initVal->getType()->isPointerTy() && varType->isPointerTy()) {
                initVal = builder->CreateBitCast(initVal, varType, "init_bitcast");
            } else {
                throw std::runtime_error("Cannot convert initializer to variable type for: " + varName);
            }
        }
    }

    // Store into allocated slot
    builder->CreateStore(initVal, allocaInst);

    // Return the alloca (so caller can inspect if needed). We do NOT store it in any symbol table.
    return allocaInst;
}

// ---------------------------------------------
// Program (NO STATEMENT WRAPPER)
// Emits i64 @main() and returns 0 by default.
// ---------------------------------------------
llvm::Value* IR::codegenProgram(const json& node) {
    if (node.value("kind", "") != "Program")
        throw std::runtime_error("Top-level node must be Program");

    auto& body = node["Body"];
    if (!body.is_array() || body.empty())
        throw std::runtime_error("Program Body missing or empty");

    // For now always emit main as i64 -> return 0.
    llvm::Type* retType = builder->getInt64Ty();

    // Create main()
    auto* fnType = llvm::FunctionType::get(retType, false);
    auto* fn = llvm::Function::Create(fnType,
                                      llvm::Function::ExternalLinkage,
                                      "main",
                                      module.get());

    auto* entry = llvm::BasicBlock::Create(*context, "entry", fn);
    builder->SetInsertPoint(entry);

    // Execute each body item. For VariableDeclaration we allocate+store.
    for (const auto& stmt : body) {
        const std::string kind = stmt.value("kind", "");
        if (kind == "VariableDeclaration") {
            codegenVariableDeclaration(stmt);
        } else {
            // Evaluate expression for side-effects (if any)
            // If expression returns a value, we ignore it here.
            codegenExpression(stmt);
        }
    }

    // Default return 0 (i64)
    builder->CreateRet(llvm::ConstantInt::get(builder->getInt64Ty(), 0));

    if (llvm::verifyFunction(*fn, &llvm::errs()))
        throw std::runtime_error("IR verification failed");

    return fn;
}