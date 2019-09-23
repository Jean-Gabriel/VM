#ifndef VIRTUAL_MACHINE_TYPE_HPP
#define VIRTUAL_MACHINE_TYPE_HPP

#include <iostream>

typedef uint64_t Pointer;

union Type {
    std::string string_value;
    bool boolean_value;
    float number_value;
    Pointer pointer_value;
};

#endif //VIRTUAL_MACHINE_TYPE_HPP
