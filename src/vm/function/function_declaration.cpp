#include "function_declaration.hpp"

FunctionDeclaration buildFunctionDeclarationWith(InstructionPointer startingPoint, uint8_t argumentCount) {
        FunctionDeclaration declaration{};

        declaration.startingPoint = startingPoint;
        declaration.argumentCount = argumentCount;

        return declaration;
}