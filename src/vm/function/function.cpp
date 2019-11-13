#include "function.hpp"

Function buildFunctionWith(int returnPoint) {
    Function function{};

    function.returnPoint = returnPoint;

    return function;
}