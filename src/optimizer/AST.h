//
// Created by Brayhan De Aza on 11/24/25.
//


#ifndef CROMIO_AST_H
#define CROMIO_AST_H

#include <vector>
#include <string>

struct Node {
    virtual ~Node() = default;
};

struct FloatLiteral final : Node {
    double value;
};

struct IntegerLiteral final : Node {
    int value;
};

struct BooleanLiteral final : Node {
    bool value;
};

struct Expression final : Node {
    std::string op;
    Node* left;
    Node* right;
};

struct Statement final : Node {
    Node* expr;
};

struct Program final : Node {
    std::vector<Node*> body;
};


#endif //CROMIO_AST_H