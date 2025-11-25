//
// Created by Brayhan De Aza on 11/24/25.
//

#ifndef CROMIO_OPTIMIZER_H
#define CROMIO_OPTIMIZER_H


#pragma once
#include <utils/Helpers.h>

class Optimizer {
public:
    static json optimize(const json& node);

private:
    static bool isConstant(const json& node);
    static double getNumericValue(const json& node);

    static json visitProgram(const json& node);
    static json visitExpression(const json& node);
};


#endif //CROMIO_OPTIMIZER_H