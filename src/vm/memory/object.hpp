#ifndef VIRTUAL_MACHINE_OBJECT_HPP
#define VIRTUAL_MACHINE_OBJECT_HPP

#include "memory.hpp"

struct Object {
    uint16_t startingPoint;
    uint8_t length;
};

#endif //VIRTUAL_MACHINE_OBJECT_HPP
