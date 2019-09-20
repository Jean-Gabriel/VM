#ifndef VIRTUAL_MACHINE_STATE_HPP
#define VIRTUAL_MACHINE_STATE_HPP

#include <vector>

typedef short InstructionPointer;
typedef unsigned char StackPointer;

struct State {
    StackPointer  stackPointer = 0;
    InstructionPointer instructionPointer = -1;
    bool isRunning = false;
};


#endif //VIRTUAL_MACHINE_STATE_HPP
