//
// Created by Brayhan De Aza on 10/19/25.
//

#include "VariablesVisitor.h"
#include "semantic/semantic.h"

std::any cromio::visitor::VariablesVisitor::visitVariables(Grammar::VariablesContext* ctx) {
    if (ctx->variableDeclaration()) {
        const auto visitVariableDeclaration = visit(ctx->variableDeclaration());
        return std::any_cast<json>(visitVariableDeclaration);
    }

    if (ctx->variableDeclarationWithoutAssignment()) {
        const auto visitVariableDeclarationWithoutAssignment = visit(ctx->variableDeclarationWithoutAssignment());
        return std::any_cast<json>(visitVariableDeclarationWithoutAssignment);
    }

    if (ctx->variableAssignment()) {
        const auto visitVariableAssignment = visit(ctx->variableAssignment());
        return std::any_cast<json>(visitVariableAssignment);
    }

    if (ctx->variableAccessToMember()) {
        const auto visitVariableAccessToMember = visit(ctx->variableAccessToMember());
        return std::any_cast<json>(visitVariableAccessToMember);
    }

    return json::object();
}

std::any cromio::visitor::VariablesVisitor::visitVariableDeclarationWithoutAssignment(Grammar::VariableDeclarationWithoutAssignmentContext* ctx) {
    json node = utils::Helpers::createNode("", "VariableDeclaration", ctx->start, ctx->stop);

    const auto visitDataType = visit(ctx->variableDataType());
    const auto jDataType = std::any_cast<json>(visitDataType);

    json identifier = utils::Helpers::createNode("", "VariableIdentifier", ctx->IDENTIFIER()->getSymbol(), ctx->IDENTIFIER()->getSymbol());
    identifier["value"] = ctx->IDENTIFIER()->getText();

    node["DataType"] = jDataType;
    node["Identifier"] = identifier;

    return analyzeVariableWithoutAssignment(node, ctx->start, ctx->stop);
}

std::any cromio::visitor::VariablesVisitor::visitVariableDeclaration(Grammar::VariableDeclarationContext* ctx) {
    json node = utils::Helpers::createNode("", "VariableDeclaration", ctx->start, ctx->stop);

    const auto visitDataType = visit(ctx->variableDataType());
    const auto jDataType = std::any_cast<json>(visitDataType);

    const auto variableAssignment = visit(ctx->variableAssignment());
    const auto jVariableAssignment = std::any_cast<json>(variableAssignment);

    node["DataType"] = jDataType;
    node["Identifier"] = jVariableAssignment["Identifier"];
    node["value"] = jVariableAssignment["value"];

    json variable = analyzeVariableDeclaration(node, source);

    json scopeInfo = utils::Helpers::createNode("", "VariableInfo", ctx->start, ctx->stop);
    scopeInfo["value"] = variable["value"]["value"];
    scopeInfo["type"] = variable["DataType"]["value"];

    return variable;
}

std::any cromio::visitor::VariablesVisitor::visitVariableAssignment(Grammar::VariableAssignmentContext* ctx) {
    json node = utils::Helpers::createNode("", "VariableAssignment", ctx->start, ctx->stop);

    const auto expression = visit(ctx->expression());
    const auto jExpression = std::any_cast<json>(expression);

    json identifier = utils::Helpers::createNode("", "VariableIdentifier", ctx->IDENTIFIER()->getSymbol(), ctx->IDENTIFIER()->getSymbol());
    identifier["value"] = ctx->IDENTIFIER()->getText();

    node["Identifier"] = identifier;
    node["value"] = jExpression;

    return node;
}

std::any cromio::visitor::VariablesVisitor::visitVariableDataType(Grammar::VariableDataTypeContext* ctx) {
    json node = utils::Helpers::createNode("", "DataType", ctx->start, ctx->stop);
    node["value"] = ctx->getText();

    return node;
}

std::any cromio::visitor::VariablesVisitor::visitVariableAccessToMember(Grammar::VariableAccessToMemberContext* ctx) {
    json node = utils::Helpers::createNode("", "VariableMember", ctx->start, ctx->stop);

    const auto identifier = ctx->IDENTIFIER()[0];
    json jIdentifier = utils::Helpers::createNode("", "VariableIdentifier", identifier->getSymbol(), identifier->getSymbol());
    jIdentifier["value"] = identifier->getText();

    const auto member = ctx->IDENTIFIER()[1];
    const json jMember = utils::Helpers::createNode("", "Member", member->getSymbol(), member->getSymbol());

    node["Identifier"] = jIdentifier;
    node["Member"] = jMember;

    return node;
}
