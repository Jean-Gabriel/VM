#ifndef VIRTUAL_MACHINE_STRING_HPP
#define VIRTUAL_MACHINE_STRING_HPP

#include "memory/memory.hpp"

struct String {
    Pointer startingPoint;
    uint8_t length;
};

#endif //VIRTUAL_MACHINE_STRING_HPP
