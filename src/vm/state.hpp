#ifndef VIRTUAL_MACHINE_STATE_HPP
#define VIRTUAL_MACHINE_STATE_HPP

struct State {
    int instructionPointer = -1;
    bool isRunning = false;
};


#endif //VIRTUAL_MACHINE_STATE_HPP
