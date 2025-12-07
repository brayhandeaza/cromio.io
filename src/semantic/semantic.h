//
// Created by Brayhan De Aza on 11/27/25.
//

#ifndef CROMIO_SEMANTIC_H
#define CROMIO_SEMANTIC_H

#include "semantic/arrays/Arrays.h"
#include "semantic/variables/Variables.h"

namespace cromio::semantic {
    class Semantic : public virtual Variables, public virtual Arrays {};
} // namespace cromio::semantic

#endif // CROMIO_SEMANTIC_H