#ifndef VIRTUAL_MACHINE_TYPE_HPP
#define VIRTUAL_MACHINE_TYPE_HPP

#include <iostream>

union Type {
    bool boolean_value;
    float number_value;
};

Type numberFrom(float);
Type booleanFrom(bool);

#endif //VIRTUAL_MACHINE_TYPE_HPP
