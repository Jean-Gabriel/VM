#ifndef VIRTUAL_MACHINE_TYPE_HPP
#define VIRTUAL_MACHINE_TYPE_HPP

#include <iostream>

typedef int Pointer;
typedef std::string String;

template <typename T>
using Vector = std::vector<T>;

union Type {
    String string_value;
    bool boolean_value;
    float number_value;
    Pointer pointer_value;
};

#endif //VIRTUAL_MACHINE_TYPE_HPP
