#ifndef VIRTUAL_MACHINE_FUNCTION_HPP
#define VIRTUAL_MACHINE_FUNCTION_HPP

#include <map>
#include "../value.hpp"

class VirtualMachine;

struct Function {
    std::map<uint8_t, Value> declarables;
    int returnPoint;
};

Function buildFunctionWith(int returnPoint);

#endif //VIRTUAL_MACHINE_FUNCTION_HPP
