//
// Created by Brayhan De Aza on 10/19/25.
//

#include "DictionaryVisitor.h"

namespace cromio::visitor {
    std::any DictionaryVisitor::visitDictionaryDeclaration(Grammar::DictionaryDeclarationContext* ctx) {
        json node = createNode("", "DictionaryDeclaration", ctx->start, ctx->stop);

        const auto type = visit(ctx->dictionaryDeclarationType());
        const auto typeNode = std::any_cast<json>(type);

        const std::string keyType = typeNode["KeyType"]["value"];
        const std::string valueType = typeNode["ValueType"]["value"];

        json assignment = createNode("", "DictionaryAssignment", ctx->start, ctx->stop);
        json members = json::object();
        for (const auto child : ctx->dictionaryAssignmentBody()) {
            const auto memberCtx = visit(child);
            const auto memberFullNode = std::any_cast<json>(memberCtx);

            const json keyNode = memberFullNode["Key"];
            const std::string memberKeyRaw = keyNode["raw"];
            const std::string memberKeyType = keyNode["type"];
            const json valueNode = memberFullNode["Value"];

            if (keyType != memberKeyType) {
                throwTypeError(memberKeyRaw, keyType, memberFullNode, source);
            }

            if (json member = memberFullNode["Value"]; member["kind"] == "IdentifierLiteral") {
                const std::string identifier = member["raw"];
                const auto variable = scope->lookup(identifier);

                if (!scope->existsInCurrent(identifier) || !variable.has_value()) {
                    throwScopeError("identifier '" + identifier + "' " + "not found in scope", member, source);
                }

                if (variable.has_value()) {
                    const json value = variable.value();
                    if (const std::string memberValueType = value["type"]; memberValueType != valueType) {
                        throwTypeError(value["raw"], keyType, valueNode, source);
                    }
                    members[memberKeyRaw] = value;
                }

            } else {
                members[memberKeyRaw] = member;
            }
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

        const auto keyType = visit(ctx->dictionaryDataType(0));
        const auto valueType = visit(ctx->dictionaryDataType(1));

        const auto keyTypeNode = std::any_cast<json>(keyType);
        const auto valueTypeNode = std::any_cast<json>(valueType);

        node["KeyType"] = keyTypeNode;
        node["ValueType"] = valueTypeNode;

        return node;
    }

    std::any DictionaryVisitor::visitDictionaryDataType(Grammar::DictionaryDataTypeContext* ctx) {
        json node = createNode("", "DataType", ctx->start, ctx->stop);
        node["value"] = ctx->getText();

        return node;
    }

} // namespace cromio::visitor