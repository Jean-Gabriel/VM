#ifndef VIRTUAL_MACHINE_VIRTUAL_MACHINE_HPP
#define VIRTUAL_MACHINE_VIRTUAL_MACHINE_HPP

#include "state.hpp"
#include "type.hpp"
#include "executor/executor.hpp"
#include <string>
#include <stack>
#include <vector>

typedef uint8_t Instruction;
typedef uint16_t ReturnCode;

class VirtualMachine {
private:
    const std::vector<Instruction> program;
    State state;
    Executor executor;
    std::stack<Type*> stack;

    explicit VirtualMachine(std::vector<Instruction>);

    bool instructionPointerIsOutOfBound();
public:
    static VirtualMachine* initializeWith(const std::vector<Instruction> &program);
    void run();
    void stop(ReturnCode);
    void goToNextInstruction();
    bool isRunning();
};


#endif //VIRTUAL_MACHINE_VIRTUAL_MACHINE_HPP
