#ifndef VIRTUAL_MACHINE_VIRTUAL_MACHINE_HPP
#define VIRTUAL_MACHINE_VIRTUAL_MACHINE_HPP

#include "state.hpp"
#include "value.hpp"
#include "executor/executor.hpp"
#include "function/function.hpp"
#include "function/function_declaration.hpp"
#include "memory/memory.hpp"
#include "object/object_declaration.hpp"
#include <string>
#include <stack>
#include <vector>

class VirtualMachine {
protected:
    friend class Executor;

    const std::vector<uint8_t> program;
    State state;
    Executor executor;
    Memory memory;

    std::map<uint8_t, FunctionDeclaration> declaredFunctions;
    std::map<uint8_t, ObjectDeclaration> declaredObjects;
    std::map<uint8_t, Value> globals;

    std::stack<Value> stack;
    std::stack<Function> callStack;

    bool instructionPointerIsOutOfBound();
    explicit VirtualMachine(std::vector<uint8_t> program);
public:
    static VirtualMachine initializeWith(const std::vector<uint8_t> &program);
    void run();
    void stop(uint8_t returnCode);
    void setInstructionPointerTo(int pointer);
    uint8_t advanceInstruction();
    bool isRunning();
};


#endif //VIRTUAL_MACHINE_VIRTUAL_MACHINE_HPP
