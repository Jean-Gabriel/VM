#ifndef VIRTUAL_MACHINE_VIRTUAL_MACHINE_HPP
#define VIRTUAL_MACHINE_VIRTUAL_MACHINE_HPP

#include "state.hpp"
#include "type.hpp"
#include <string>
#include <stack>
#include <vector>

typedef unsigned char Instruction;
typedef unsigned char ReturnCode;

class VirtualMachine {
private:
    const std::vector<Instruction> program;
    State state;
    std::stack<Type*> stack;

    explicit VirtualMachine(std::vector<Instruction>);

    void stop(ReturnCode);
    bool instructionPointerIsOutOfBound();
    bool isRunning();
public:
    static VirtualMachine* initializeWith(const std::vector<Instruction> &program);
    void run();
    void goToNextInstruction();
};


#endif //VIRTUAL_MACHINE_VIRTUAL_MACHINE_HPP
