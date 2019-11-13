#include "executor.hpp"
#include "virtual_machine.hpp"


void Executor::declareFunction(VirtualMachine *vm) {
    uint8_t id = vm->advanceInstruction();
    int startingPoint = vm->advanceInstruction();
    uint8_t argumentCount = vm->advanceInstruction();

    FunctionDeclaration declaration = buildFunctionDeclarationWith(startingPoint, argumentCount);

    vm->declaredFunctions.insert(std::pair<uint8_t, FunctionDeclaration>(id, declaration));
}

void Executor::callFunction(VirtualMachine *vm) {
    uint8_t demandedFunctionId = vm->advanceInstruction();
    FunctionDeclaration demandedFunction =  vm->declaredFunctions.at(demandedFunctionId);
    int  returnPoint = vm->state.instructionPointer;

    Function calledFunction = buildFunctionWith(returnPoint);

    vm->callStack.push(calledFunction);
    vm->setInstructionPointerTo(demandedFunction.startingPoint);
    Executor::loadArgumentsFor(demandedFunction, vm);
}

void Executor::loadArgumentsFor(FunctionDeclaration demandedFunction, VirtualMachine *vm) {
    for(uint8_t i = 0;i<demandedFunction.argumentCount;i++) {
        Value value =  vm->stack.top();
        vm->stack.pop();

        vm->callStack.top().declarables.insert(std::pair<uint8_t, Value>(i, value));
    }
}

void Executor::doReturn(VirtualMachine *vm) {
    vm->setInstructionPointerTo(vm->callStack.top().returnPoint);
    vm->callStack.pop();
}