#ifndef VIRTUAL_MACHINE_FUNCTION_HPP
#define VIRTUAL_MACHINE_FUNCTION_HPP

#include <map>
#include "../type.hpp"

class VirtualMachine;
typedef uint8_t DeclarableID;

struct Function {
    std::map<DeclarableID, Type> declarables;
    InstructionPointer returnPoint;
};

Function buildFunctionWith(InstructionPointer);

#endif //VIRTUAL_MACHINE_FUNCTION_HPP
