//
// Created by Brayhan De Aza on 10/19/25.
//

#include "VariablesVisitor.h"
#include "semantic/semantic.h"

namespace cromio::visitor {
    std::any VariablesVisitor::visitVariables(Grammar::VariablesContext* ctx) {
        if (ctx->variableDeclaration()) {
            const auto visitVariableDeclaration = visit(ctx->variableDeclaration());
            return std::any_cast<json>(visitVariableDeclaration);
        }

        if (ctx->variableDeclarationWithoutAssignment()) {
            const auto visitVariableDeclarationWithoutAssignment = visit(ctx->variableDeclarationWithoutAssignment());
            return std::any_cast<json>(visitVariableDeclarationWithoutAssignment);
        }

        if (ctx->variableReAssignment()) {
            const auto visitVariableAssignment = visit(ctx->variableReAssignment());
            return std::any_cast<json>(visitVariableAssignment);
        }

        if (ctx->variableAccessToMember()) {
            const auto visitVariableAccessToMember = visit(ctx->variableAccessToMember());
            return std::any_cast<json>(visitVariableAccessToMember);
        }

        return json::object();
    }

    std::any VariablesVisitor::visitVariableDeclarationWithoutAssignment(Grammar::VariableDeclarationWithoutAssignmentContext* ctx) {
        json node = createNode("", "VariableDeclaration", ctx->start, ctx->stop);

        const auto visitDataType = visit(ctx->variableDataType());
        const auto jDataType = std::any_cast<json>(visitDataType);

        const std::string rIdentifier = ctx->IDENTIFIER()->getText();
        if (scope->existsInCurrent(rIdentifier)) {
            throwScopeError("variable '" + rIdentifier + "' " + "is already declared", jDataType, source);
        }

        json identifier = createNode("", "VariableIdentifier", ctx->IDENTIFIER()->getSymbol(), ctx->IDENTIFIER()->getSymbol());
        identifier["value"] = rIdentifier;

        node["DataType"] = jDataType;
        node["Identifier"] = identifier;

        json variable = analyzeVariableWithoutAssignment(node, ctx->start, ctx->stop);
        scope->declareVariable(rIdentifier, variable["value"]);

        return variable;
    }

    std::any VariablesVisitor::visitVariableDeclaration(Grammar::VariableDeclarationContext* ctx) {
        json node = createNode("", "VariableDeclaration", ctx->start, ctx->stop);

        parser->inVarMode = true;
        const auto visitDataType = visit(ctx->variableDataType());
        const auto dataType = std::any_cast<json>(visitDataType);

        std::string identifier = ctx->IDENTIFIER()->getText();
        if (scope->existsInCurrent(identifier)) {
            throwScopeError("variable '" + identifier + "' " + "is already declared", dataType, source);
        }

        json identifierNode = createNode("", "VariableIdentifier", ctx->IDENTIFIER()->getSymbol(), ctx->IDENTIFIER()->getSymbol());
        identifierNode["value"] = identifier;

        const auto expression = visit(ctx->expression());
        const auto value = std::any_cast<json>(expression);

        parser->inVarMode = false;
        scope->declareVariable(identifier, value);

        node["DataType"] = dataType;
        node["Identifier"] = identifierNode;
        node["value"] = value;

        return analyzeVariableDeclaration(node, source);
    }

    std::any VariablesVisitor::visitVariableReAssignment(Grammar::VariableReAssignmentContext* ctx) {
        json node = createNode("", "VariableReAssignment", ctx->start, ctx->stop);

        parser->inVarMode = true;
        const auto expression = visit(ctx->expression());
        const auto jExpression = std::any_cast<json>(expression);
        parser->inVarMode = false;

        std::string identifier = ctx->IDENTIFIER()->getText();
        json jIdentifier = createNode("", "VariableIdentifier", ctx->IDENTIFIER()->getSymbol(), ctx->IDENTIFIER()->getSymbol());
        jIdentifier["value"] = identifier;

        if (!scope->existsInCurrent(identifier)) {
            throwScopeError("variable '" + identifier + "' " + "is not declared", jIdentifier, source);
        }

        node["Identifier"] = jIdentifier;
        node["value"] = jExpression;

        return node;
    }

    std::any VariablesVisitor::visitVariableDataType(Grammar::VariableDataTypeContext* ctx) {
        json node = createNode("", "DataType", ctx->start, ctx->stop);
        node["value"] = ctx->getText();

        return node;
    }

    std::any VariablesVisitor::visitVariableAccessToMember(Grammar::VariableAccessToMemberContext* ctx) {
        json node = createNode("", "VariableMember", ctx->start, ctx->stop);

        const auto identifier = ctx->IDENTIFIER()[0];
        json jIdentifier = createNode("", "VariableIdentifier", identifier->getSymbol(), identifier->getSymbol());
        jIdentifier["value"] = identifier->getText();

        const auto member = ctx->IDENTIFIER()[1];
        const json jMember = createNode("", "Member", member->getSymbol(), member->getSymbol());

        node["Identifier"] = jIdentifier;
        node["Member"] = jMember;

        return node;
    }
} // namespace cromio::visitor