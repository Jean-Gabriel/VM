#ifndef VIRTUAL_MACHINE_STATE_HPP
#define VIRTUAL_MACHINE_STATE_HPP

#include <vector>

typedef short InstructionPointer;

struct State {
    InstructionPointer instructionPointer = -1;
    bool isRunning = false;
};


#endif //VIRTUAL_MACHINE_STATE_HPP
