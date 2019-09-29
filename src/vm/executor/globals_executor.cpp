#include <type.hpp>
#include "executor.hpp"
#include "virtual_machine.hpp"

void Executor::storeGlobalNumber(VirtualMachine *vm) {
    VariableID id = vm->advanceInstruction();
    Type numberToStore = vm->stack.top();
    vm->stack.pop();

    vm->globals.insert(std::pair<VariableID, Type>(id, numberToStore));
}

void Executor::storeGlobalBoolean(VirtualMachine *vm){
    VariableID id = vm->advanceInstruction();
    Type booleanToStore = vm->stack.top();
    vm->stack.pop();

    vm->globals.insert(std::pair<VariableID, Type>(id, booleanToStore));
}

void Executor::loadGlobal(VirtualMachine *vm) {
    VariableID idToLoad = vm->advanceInstruction();
    Type requestedGlobal = vm->globals.at(idToLoad);

    vm->stack.push(requestedGlobal);
}