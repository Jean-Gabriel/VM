#include <value.hpp>
#include "executor.hpp"
#include "virtual_machine.hpp"

void Executor::storeGlobal(VirtualMachine *vm) {
    DeclarableID id = vm->advanceInstruction();
    Value globalToStore = vm->stack.top();
    vm->stack.pop();

    vm->globals.insert(std::pair<DeclarableID, Value>(id, globalToStore));
}

void Executor::loadGlobal(VirtualMachine *vm) {
    DeclarableID idToLoad = vm->advanceInstruction();
    Value requestedGlobal = vm->globals.at(idToLoad);

    vm->stack.push(requestedGlobal);
}

void Executor::declareGlobalFunction(VirtualMachine *vm) {
    DeclarableID id = vm->advanceInstruction();
    InstructionPointer startingPoint = vm->advanceInstruction();
    uint8_t argumentCount = vm->advanceInstruction();

    FunctionDeclaration declaration = buildFunctionDeclarationWith(startingPoint, argumentCount);

    vm->declaredFunctions.insert(std::pair<DeclarableID, FunctionDeclaration>(id, declaration));
}

void Executor::callGlobalFunction(VirtualMachine *vm) {
    DeclarableID demandedFunctionId = vm->advanceInstruction();
    FunctionDeclaration demandedFunction =  vm->declaredFunctions.at(demandedFunctionId);
    InstructionPointer returnPoint = vm->state.instructionPointer;

    Function calledFunction = buildFunctionWith(returnPoint);

    vm->callStack.push(calledFunction);
    vm->setInstructionPointerTo(demandedFunction.startingPoint);
    Executor::loadArgumentsFor(demandedFunction, vm);
}

void Executor::loadArgumentsFor(FunctionDeclaration demandedFunction, VirtualMachine *vm) {
    for(DeclarableID i = 0;i<demandedFunction.argumentCount;i++) {
        Value value =  vm->stack.top();
        vm->stack.pop();

        vm->callStack.top().declarables.insert(std::pair<DeclarableID, Value>(i, value));
    }
}