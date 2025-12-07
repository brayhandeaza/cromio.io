//
// Created by Brayhan De Aza on 10/19/25.
//

#include "ArraysVisitor.h"
#include "semantic/semantic.h"
#include "semantic/BaseSemantic.h"


namespace cromio::visitor {
    std::any ArraysVisitor::visitArrayDeclaration(Grammar::ArrayDeclarationContext* ctx) {
        json node = createNode("", "ArrayDeclaration", ctx->start, ctx->stop);

        const auto arrayType = visit(ctx->variableDataType());
        const auto jArrayType = std::any_cast<json>(arrayType);

        const auto arraySize = visit(ctx->arrayDeclarationTypeSize());
        const auto jArraySize = std::any_cast<json>(arraySize);

        json value = createNode("", "ArrayAssignment", ctx->start, ctx->stop);
        json items = json::array();

        json identifier = createNode("", "ArrayIdentifier", ctx->start, ctx->stop);
        identifier["value"] = ctx->IDENTIFIER()->getText();

        for (const auto child : ctx->expression()) {
            const auto item = visit(child);
            auto jItem = std::any_cast<json>(item);

            std::string dataType = jArrayType["value"];
            std::string returnType = jItem["type"];

            const std::string rValue = jItem["numberValue"];
            const std::string stringValue = jItem["stringValue"];

            analyzeSignedInteger(rValue, dataType, identifier["value"], source, jItem);
            if (const auto passArrayDataType = checkArrayDataType(dataType, returnType); !passArrayDataType) {
                throwTypeError(identifier["value"], dataType, jItem, source);
            }

            items.push_back(jItem);
        }

        value["items"] = items;

        node["DataType"] = jArrayType;
        node["ArraySize"] = jArraySize["value"];
        node["Identifier"] = identifier;
        node["value"] = value;

        return analyzeArrayDeclaration(node, source);
    }

    std::any ArraysVisitor::visitArrayDeclarationTypeSize(Grammar::ArrayDeclarationTypeSizeContext* ctx) {
        json node = createNode("", "ArraySize", ctx->start, ctx->stop);

        std::any expression;

        // Only visit expression if it exists
        if (ctx->expression() != nullptr) {
            expression = visit(ctx->expression());
        }

        if (!expression.has_value()) {
            json size = createNode("auto", "Auto", ctx->start, ctx->stop);
            size["value"] = "auto";
            node["value"] = size;
        } else {
            node["value"] = std::any_cast<json>(expression);
        }

        return node;
    }

} // namespace cromio::visitor