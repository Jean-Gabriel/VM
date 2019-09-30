#ifndef VIRTUAL_MACHINE_STATE_HPP
#define VIRTUAL_MACHINE_STATE_HPP

#include <stdint-gcc.h>

typedef uint16_t InstructionPointer;
typedef uint8_t FunctionPointer;

struct State {
    InstructionPointer instructionPointer = -1;
    bool isRunning = false;
};


#endif //VIRTUAL_MACHINE_STATE_HPP
