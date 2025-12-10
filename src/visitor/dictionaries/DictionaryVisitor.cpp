//
// Created by Brayhan De Aza on 10/19/25.
//

#include "DictionaryVisitor.h"

namespace cromio::visitor {
    std::any DictionaryVisitor::visitDictionaryDeclaration(Grammar::DictionaryDeclarationContext* ctx) {
        json node = createNode("", "DictionaryDeclaration", ctx->start, ctx->stop);

        const auto type = visit(ctx->dictionaryDeclarationType());
        const auto typeNode = std::any_cast<json>(type);
        const std::string valueType = typeNode["ValueType"]["value"];

        auto keyTypeNode = typeNode["KeyType"];
        auto valueTypeNode = typeNode["ValueType"];

        const std::string keyType = typeNode["KeyType"]["value"];

        json assignment = createNode("", "DictionaryAssignment", ctx->start, ctx->stop);
        json members = json::object();
        for (const auto child : ctx->dictionaryAssignmentBody()) {
            const auto memberCtx = visit(child);
            auto memberNode = std::any_cast<json>(memberCtx);

            members = analyzeDictionaryItemsDataType(keyTypeNode, valueTypeNode, memberNode, scope, source);
        }

        node["Type"] = typeNode;
        node["Members"] = members;

        // std::cout << node.dump(1);

        return node;
    }

    std::any DictionaryVisitor::visitDictionaryAssignmentBody(Grammar::DictionaryAssignmentBodyContext* ctx) {
        json node = createNode("", "DictionaryAssignmentBody", ctx->start, ctx->stop);

        const auto key = visit(ctx->literal());
        const auto value = visit(ctx->expression());

        const auto keyNode = std::any_cast<json>(key);
        const auto valueNode = std::any_cast<json>(value);

        node["Key"] = keyNode;
        node["Value"] = valueNode;

        return node;
    }

    std::any DictionaryVisitor::visitDictionaryDeclarationType(Grammar::DictionaryDeclarationTypeContext* ctx) {
        json node = createNode("", "DictionaryType", ctx->start, ctx->stop);

        // Visit both type elements (key and value)
        const auto keyType = visit(ctx->dictionaryTypeElement(0));
        const auto valueType = visit(ctx->dictionaryTypeElement(1));

        node["KeyType"] = std::any_cast<json>(keyType);
        node["ValueType"] = std::any_cast<json>(valueType);

        return node;
    }

    std::any DictionaryVisitor::visitDictionaryDeclarationTypeArray(Grammar::DictionaryDeclarationTypeArrayContext* ctx) {
        json node = createNode("", "TypeArray", ctx->start, ctx->stop);
        std::string type = ctx->dictionaryDataType()->getText() + "[]";

        if (ctx->expression()) {
            const auto expression = visit(ctx->expression());
            node["size"] = std::any_cast<json>(expression);
        } else {
            node["size"] = "auto";
        }

        node["value"] = type;
        return node;
    }

    std::any DictionaryVisitor::visitDictionaryTypeElement(Grammar::DictionaryTypeElementContext* ctx) {
        if (ctx->dictionaryDeclarationTypeArray()) {
            return visit(ctx->dictionaryDeclarationTypeArray());
        }
        return visit(ctx->dictionaryDataType());
    }

    std::any DictionaryVisitor::visitDictionaryDataType(Grammar::DictionaryDataTypeContext* ctx) {
        json node = createNode("", "DataType", ctx->start, ctx->stop);
        node["value"] = ctx->getText();

        return node;
    }

} // namespace cromio::visitor