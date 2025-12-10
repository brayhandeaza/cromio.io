//
// Created by Brayhan De Aza on 10/19/25.
//

#include "ArraysVisitor.h"
#include "semantic/BaseSemantic.h"
#include "semantic/semantic.h"

namespace cromio::visitor {
    std::any ArraysVisitor::visitArrayDeclaration(Grammar::ArrayDeclarationContext* ctx) {
        json node = createNode("", "ArrayDeclaration", ctx->start, ctx->stop);

        const auto arrayType = visit(ctx->arrayType());
        const auto jArrayType = std::any_cast<json>(arrayType);

        json value = createNode("", "ArrayAssignment", ctx->start, ctx->stop);
        json items = json::array();

        json identifier = createNode("", "ArrayIdentifier", ctx->start, ctx->stop);
        identifier["value"] = ctx->IDENTIFIER()->getText();

        parser->inVarMode = true;
        for (const auto child : ctx->expression()) {
            const auto item = visit(child);
            auto jItem = std::any_cast<json>(item);

            if (jItem.contains("error")) {
                throwError("Error", jItem["error"], jItem, source);
            }

            const std::string dataType = jArrayType["value"];
            const std::string returnType = jItem["type"];
            const std::string rValue = jItem["numberValue"];
            const std::string stringValue = jItem["stringValue"];

            if (const auto passArrayDataType = checkArrayDataType(dataType, returnType); !passArrayDataType) {
                throwTypeError(identifier["value"], dataType, jItem, source);
            }

            analyzeSignedInteger(rValue, dataType, identifier["value"], source, jItem);

            if (jItem["kind"] == "IdentifierLiteral") {
                items.push_back(jItem["value"]);
            } else {
                items.push_back(jItem);
            }
        }

        parser->inVarMode = false;
        value["items"] = items;

        node["Type"] = jArrayType;
        node["Identifier"] = identifier;
        node["value"] = value;

        json varInfo = json::object();
        varInfo["type"] = node["Type"]["raw"];
        varInfo["size"] = node["Type"]["size"];
        varInfo["name"] = identifier["value"];
        varInfo["value"] = value;

        scope->declareVariable(varInfo["name"], varInfo);
        const auto analyzeedNode = analyzeArrayDeclaration(node, source);

        return analyzeedNode;
    }

    std::any ArraysVisitor::visitArrayDeclarationTypeSize(Grammar::ArrayDeclarationTypeSizeContext* ctx) {
        json node = createNode("", "ArraySize", ctx->start, ctx->stop);

        // Only visit expression if it exists
        std::any expression;
        if (ctx->expression() != nullptr) {
            expression = visit(ctx->expression());
        }

        if (!expression.has_value()) {
            json size = createNode("auto", "Auto", ctx->start, ctx->stop);
            size["value"] = "auto";
            size["raw"] = "auto";
            node["value"] = size;
        } else {
            const auto expr = std::any_cast<json>(expression);
            node["value"] = expr;
            node["raw"] = expr["raw"];
        }

        return node;
    }

    std::any ArraysVisitor::visitArrayType(Grammar::ArrayTypeContext* ctx) {
        json node = createNode("", "ArrayType", ctx->start, ctx->stop);

        const auto arrayDataType = ctx->arrayDataType()->getText();
        const auto arraySize = visit(ctx->arrayDeclarationTypeSize());
        const auto jArraySize = std::any_cast<json>(arraySize);
        const auto size = jArraySize["value"]["raw"].get<std::string>();

        node["raw"] = arrayDataType + "[]";
        node["value"] = arrayDataType;
        node["size"] = size;

        return node;
    }

    std::any ArraysVisitor::visitArrayDataType(Grammar::ArrayDataTypeContext* ctx) {
        return visitChildren(ctx);
    }

} // namespace cromio::visitor