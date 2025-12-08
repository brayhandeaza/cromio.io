//
// Created by Brayhan De Aza on 11/27/25.
//

#include "ProgramVisitor.h"
#include <utils/utils.h>

void processScope(cromio::semantic::Scope& scope, const json& body, const std::string& source) {
    for (const auto& node : body) {
        if (node["kind"] == "VariableDeclaration") {
            std::string name = node["Identifier"]["value"];
            scope.declareVariable(name, node);
        }

        if (node["kind"] == "VariableAssignment") {
            const std::string name = node["Identifier"]["value"];

            if (auto lookup = scope.lookup(name); !lookup.has_value()) {
                cromio::utils::Error::throwScopeError("Variable '" + name + "' not found", node, source);
            }
        }

        // In the future you will add:
        // - Block statements
        // - Functions (push new scope)
        // - Classes
        // - Loops
    }
}

std::any cromio::visitor::Visitor::visitProgram(Grammar::ProgramContext* ctx) {
    json node = createNode("", "Program", ctx->start, ctx->stop);

    json body;
    for (const auto child : ctx->children) {
        if (const std::any statement = visit(child); statement.has_value()) {
            body.push_back(std::any_cast<json>(statement));
        }
    }

    node["Body"] = body;
    return node;
}

std::any cromio::visitor::Visitor::visitStatements(Grammar::StatementsContext* ctx) {
    if (ctx->expression()) {
        const std::any expression = visit(ctx->expression());
        return std::any_cast<json>(expression);
    }

    if (ctx->variables()) {
        const std::any variableStatement = visit(ctx->variables());
        return std::any_cast<json>(variableStatement);
    }

    if (ctx->arrayDeclaration()) {
        const auto visitArrayDeclaration = visit(ctx->arrayDeclaration());
        return std::any_cast<json>(visitArrayDeclaration);
    }

    if (ctx->dictionaryDeclaration()) {
        const auto dictionaryDeclaration = visit(ctx->dictionaryDeclaration());
        return std::any_cast<json>(dictionaryDeclaration);
    }

    return json::object();
}
