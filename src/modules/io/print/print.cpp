//
// Created by Brayhan De Aza on 12/6/25.
//

#include "print.h"
#include <iostream>

extern "C" void cromio_print(const char* msg) {
    std::cout << msg << std::endl;
}
