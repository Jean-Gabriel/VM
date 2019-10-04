#ifndef VIRTUAL_MACHINE_TYPE_HPP
#define VIRTUAL_MACHINE_TYPE_HPP

#include <iostream>
#include "string.hpp"

union Type {
    bool boolean_value;
    float number_value;
    String string;
};

Type numberFrom(float);
Type booleanFrom(bool);
Type stringWith(Pointer, uint8_t);

#endif //VIRTUAL_MACHINE_TYPE_HPP
