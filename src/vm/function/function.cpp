#include <state.hpp>
#include "function.hpp"

Function buildFunctionWith(InstructionPointer returnPoint) {
    Function function{};

    function.returnPoint = returnPoint;

    return function;
}