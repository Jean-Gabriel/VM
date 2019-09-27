#ifndef VIRTUAL_MACHINE_TYPE_HPP
#define VIRTUAL_MACHINE_TYPE_HPP

#include <iostream>

typedef uint64_t Pointer;

union Type {
    std::string string_value = "";
    bool boolean_value;
    float number_value;
    Pointer pointer_value;

    Type(std::string value): string_value(value) {};
    Type(float value): number_value(value) {};
    Type(bool value): boolean_value(value) {};
    Type(Pointer value): pointer_value(value) {};
};

#endif //VIRTUAL_MACHINE_TYPE_HPP
