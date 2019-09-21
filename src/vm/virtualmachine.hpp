#ifndef VIRTUAL_MACHINE_VIRTUALMACHINE_HPP
#define VIRTUAL_MACHINE_VIRTUALMACHINE_HPP

#include "state.hpp"
#include "type.hpp"
#include <string>
#include <stack>
#include <vector>

typedef unsigned char Instruction;

class VirtualMachine {
private:
    const std::vector<Instruction> program;
    State state;
    std::stack<Type*> stack;

    explicit VirtualMachine(std::vector<Instruction>);

    void stop();
    bool instructionPointerIsOutOfBound();
    bool isRunning();
public:
    static VirtualMachine* initializeWith(const std::vector<Instruction> &program);
    void run();
    void goToNextInstruction();
};


#endif //VIRTUAL_MACHINE_VIRTUALMACHINE_HPP
