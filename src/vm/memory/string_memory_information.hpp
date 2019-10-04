#ifndef VIRTUAL_MACHINE_STRING_MEMORY_INFORMATION_HPP
#define VIRTUAL_MACHINE_STRING_MEMORY_INFORMATION_HPP

#include "memory.hpp"

struct StringMemoryInformation {
    Pointer startingPoint;
    uint8_t length;
};

#endif //VIRTUAL_MACHINE_STRING_MEMORY_INFORMATION_HPP
