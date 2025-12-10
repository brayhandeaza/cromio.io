//
// Created by Brayhan De Aza on 12/2/25.
//

#include "Dictionaries.h"

#include <llvm/Support/Error.h>

namespace cromio::semantic {
    json Dictionaries::analyzeDictionariesDeclaration(json& node, const std::string& source) {
        return node;
    }

    json Dictionaries::analyzeDictionaryItemsDataType(json& keyNode, json& valueNode, json& memberNode, Scope* scope, const std::string& source) {
        // JSON NODES
        json members = json::object();

        const json memberKey = memberNode["Key"];
        const json memberValue = memberNode["Value"];

        // VALUES
        const std::string memberKeyType = memberKey["type"];
        const std::string memberKeyRaw = memberKey["raw"];

        const std::string memberValueType = memberValue["type"];
        const std::string memberValueRaw = memberValue["raw"];

        const std::string keyType = keyNode["value"];
        const std::string valueType = valueNode["value"];

        // std::cout << memberKeyType << " " << memberKeyRaw << std::endl;
        // std::cout << memberValueType << " " << memberValueRaw << std::endl;
        // std::cout << keyType << " " << valueType << std::endl;
        if (memberKeyType != keyType) {
            utils::Error::throwTypeError(memberKeyRaw, keyType, memberKey, source);
        }

        // std::cout << memberValue.dump(1) << std::endl;
        if (memberValue["kind"] == "IdentifierLiteral") {
            const std::string identifier = memberValue["raw"];
            const auto variable = scope->lookup(identifier);

            if (!scope->existsInCurrent(identifier) || !variable.has_value()) {
                utils::Error::throwScopeError("identifier '" + identifier + "' " + "not found in scope", memberValue, source);
            }

            if (variable.has_value()) {
                const json value = variable.value();

                std::cout << memberValueType << " " << valueType << value.dump(1) << std::endl;
                if (memberValueType != valueType) {
                    utils::Error::throwTypeError(memberKeyRaw, valueType, memberNode, source);
                }

                members[memberKeyRaw] = value;
            }

        } else {
            if (memberValueType != valueType) {
                utils::Error::throwTypeError(memberKeyRaw, valueType, memberValue, source);
            }

            members[memberKeyRaw] = memberValue;
        }

        return members;
    }

} // namespace cromio::semantic