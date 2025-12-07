//
// Created by Brayhan De Aza on 11/27/25.
//

#ifndef CROMIO_SEMANTIC_H
#define CROMIO_SEMANTIC_H

#include "Variables.h"
#include "arrays/Arrays.h"

namespace cromio::semantic {
    class Semantic : public virtual Variables, public virtual Arrays {};
} // namespace cromio::semantic

#endif // CROMIO_SEMANTIC_H