#ifndef VIRTUAL_MACHINE_FUNCTION_DECLARATION_HPP
#define VIRTUAL_MACHINE_FUNCTION_DECLARATION_HPP

#include <stdint-gcc.h>
#include "../state.hpp"

struct FunctionDeclaration {
    uint8_t argumentCount;
    int startingPoint;
};

FunctionDeclaration buildFunctionDeclarationWith(int, uint8_t);

#endif //VIRTUAL_MACHINE_FUNCTION_DECLARATION_HPP
