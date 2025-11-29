//
// Created by Brayhan De Aza on 11/29/25.
//

#ifndef CROMIO_AST_H
#define CROMIO_AST_H

#include <utils/Helpers.h>

namespace cromio::semantic {
    class ASTAnalizy {
       public:
        static json analyze(json& ast);

       private:
        void analyzeVariableDeclaration();
    };
} // namespace cromio::semantic

#endif // CROMIO_AST_H
