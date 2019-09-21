#ifndef VIRTUAL_MACHINE_VIRTUALMACHINE_HPP
#define VIRTUAL_MACHINE_VIRTUALMACHINE_HPP

#include "state.hpp"
#include "type.hpp"
#include <string>
#include <stack>

typedef unsigned char Instruction;

template<typename T>
using Stack = std::stack<T>;

class VirtualMachine {
private:
    const Vector<Instruction> program;
    State state;
    Stack<Type> stack;

    explicit VirtualMachine(Vector<Instruction>);

    void stop();
    bool instructionPointerIsOutOfBound();
    bool isRunning();
public:
    static VirtualMachine* initializeWith(const Vector<Instruction> &program);
    void run();
    void goToNextInstruction();
};


#endif //VIRTUAL_MACHINE_VIRTUALMACHINE_HPP
