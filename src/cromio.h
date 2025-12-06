//
// Created by Brayhan De Aza on 11/27/25.
//

#ifndef CROMIO_CROMIO_H
#define CROMIO_CROMIO_H

// standard headers
#include <iostream>
#include <fstream>
#include <sstream>

// antlr headers
#include "antlr4-runtime.h"
#include "Tokens.h"
#include "Grammar.h"

// cromio headers
#include "backend/backend.h"
#include "lowering/lowering.h"
#include "runtime/runtime.h"
#include "semantic/semantic.h"
#include "visitor/visitor.h"

// utils headers
#include <utils/AntlrErrorListener.h>

#endif //CROMIO_CROMIO_H
