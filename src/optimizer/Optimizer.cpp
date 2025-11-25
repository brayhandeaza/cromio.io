#include "Optimizer.h"


bool Optimizer::isConstant(const json& node) {
    std::string k = node["kind"];
    return k == "IntegerLiteral" ||
        k == "FloatLiteral" ||
        k == "BooleanLiteral";
}

double Optimizer::getNumericValue(const json& node) {
    std::string k = node["kind"];

    if (k == "FloatLiteral")
        return node["value"].get<double>();
    if (k == "IntegerLiteral")
        return node["value"].get<int>();
    if (k == "BooleanLiteral")
        return node["value"].get<bool>() ? 1.0 : 0.0;

    throw std::runtime_error("Not a constant literal");
}

json Optimizer::visitProgram(const json& node) {
    json result = node;
    for (auto& stmt : result["Body"]) {
        stmt = optimize(stmt);
    }
    return result;
}

json Optimizer::visitExpression(const json& node) {
    const json left = optimize(node["left"]);
    const json right = optimize(node["right"]);
    const std::string op = node["operator"];

    // If both constant → fold it
    if (isConstant(left) && isConstant(right)) {
        const double L = getNumericValue(left);
        const double R = getNumericValue(right);
        double result;

        if (op == "+")
            result = L + R;
        else if (op == "-")
            result = L - R;
        else if (op == "*")
            result = L * R;
        else if (op == "/")
            result = L / R;
        else
            throw std::runtime_error("Unknown operator");

        return json{
            {"kind", "FloatLiteral"},
            {"value", result},
            {"raw", std::to_string(result)}
        };
    }

    // If it cannot fold → return rebuilt expression
    json result = node;
    result["left"] = left;
    result["right"] = right;
    return result;
}

json Optimizer::optimize(const json& node) {
    const std::string kind = node["kind"];

    if (kind == "Expression") {
        return visitExpression(node);
    }

    return node;
}