//
// Created by Brayhan De Aza on 10/19/25.
//

#include "ArraysVisitor.h"
#include "semantic/semantic.h"

namespace cromio::visitor {
    std::any ArraysVisitor::visitArrayDeclaration(Grammar::ArrayDeclarationContext* ctx) {
        json node = createNode("", "ArrayDeclaration", ctx->start, ctx->stop);

        const auto arrayType = visit(ctx->variableDataType());
        const auto jArrayType = std::any_cast<json>(arrayType);

        const auto arraySize = visit(ctx->arrayDeclarationTypeSize());
        const auto jArraySize = std::any_cast<json>(arraySize);

        const auto arrayAssignment = visit(ctx->arrayAssignment());
        const auto jArrayAssignment = std::any_cast<json>(arrayAssignment);

        json identifier = createNode("", "ArrayIdentifier", ctx->start, ctx->stop);
        identifier["value"] = ctx->IDENTIFIER()->getText();

        node["DataType"] = jArrayType;
        node["ArraySize"] = jArraySize;
        node["Identifier"] = identifier;
        node["value"] = jArrayAssignment;

        return node;
    }

    std::any ArraysVisitor::visitArrayAssignment(Grammar::ArrayAssignmentContext* ctx) {
        json node = createNode("", "ArrayAssignment", ctx->start, ctx->stop);
        json items = json::array();

        for (const auto child : ctx->expression()) {
            const auto item = visit(child);
            const auto jItem = std::any_cast<json>(item);

            items.push_back(jItem);
        }

        node["items"] = items;

        return node;
    }

    std::any ArraysVisitor::visitArrayDeclarationTypeSize(Grammar::ArrayDeclarationTypeSizeContext* ctx) {
        json node = createNode("", "ArraySize", ctx->start, ctx->stop);

        std::any expression;

        // Only visit expression if it exists
        if (ctx->expression() != nullptr) {
            expression = visit(ctx->expression());
        }

        if (!expression.has_value()) {
            node["value"] = "auto";
        } else {
            node["value"] = std::any_cast<json>(expression);
        }

        return node;
    }

} // namespace cromio::visitor