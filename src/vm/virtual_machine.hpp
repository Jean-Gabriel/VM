#ifndef VIRTUAL_MACHINE_VIRTUAL_MACHINE_HPP
#define VIRTUAL_MACHINE_VIRTUAL_MACHINE_HPP

#include "state.hpp"
#include "type.hpp"
#include "executor/executor.hpp"
#include "function/function.hpp"
#include "function/function_declaration.hpp"
#include <string>
#include <stack>
#include <vector>
#include <unordered_map>

typedef uint8_t Bytecode;
typedef uint16_t ReturnCode;
typedef uint8_t DeclarableID;

class VirtualMachine {
protected:
    friend class Executor;

    const std::vector<Bytecode> program;
    State state;
    Executor executor;

    std::unordered_map<DeclarableID, FunctionDeclaration> declaredFunctions;
    std::unordered_map<DeclarableID, Type> globals;
    std::stack<Type> stack;
    std::stack<Function> callStack;

    bool instructionPointerIsOutOfBound();
    explicit VirtualMachine(std::vector<Bytecode>);
public:
    static VirtualMachine* initializeWith(const std::vector<Bytecode> &program);
    void run();
    void stop(ReturnCode);
    void setInstructionPointerTo(InstructionPointer);
    Bytecode advanceInstruction();
    bool isRunning();
};


#endif //VIRTUAL_MACHINE_VIRTUAL_MACHINE_HPP
