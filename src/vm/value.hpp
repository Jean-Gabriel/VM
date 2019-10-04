#ifndef VIRTUAL_MACHINE_VALUE_HPP
#define VIRTUAL_MACHINE_VALUE_HPP

#include <iostream>
#include "memory/string_memory_information.hpp"

union Value {
    bool booleanValue;
    float numberValue;
    StringMemoryInformation stringInformation;
};

Value numberFrom(float);
Value booleanFrom(bool);
Value stringInformationWith(Pointer, uint8_t);

#endif //VIRTUAL_MACHINE_VALUE_HPP
