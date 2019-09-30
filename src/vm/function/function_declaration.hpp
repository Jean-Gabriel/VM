#ifndef VIRTUAL_MACHINE_FUNCTION_DECLARATION_HPP
#define VIRTUAL_MACHINE_FUNCTION_DECLARATION_HPP

#include <stdint-gcc.h>
#include "../state.hpp"

typedef uint8_t DeclarableID;

struct FunctionDeclaration {
    uint8_t argumentCount;
    InstructionPointer startingPoint;
};

FunctionDeclaration buildFunctionDeclarationWith(InstructionPointer, uint8_t);

#endif //VIRTUAL_MACHINE_FUNCTION_DECLARATION_HPP
