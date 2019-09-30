#include "executor.hpp"
#include "virtual_machine.hpp"

void Executor::storeLocal(VirtualMachine *vm) {
    DeclarableID id = vm->advanceInstruction();
    Type localToStore = vm->stack.top();
    vm->stack.pop();

    vm->callStack.top().declarables.insert(std::pair<DeclarableID, Type>(id, localToStore));
}

void Executor::loadLocal(VirtualMachine *vm) {
    DeclarableID id = vm->advanceInstruction();
    Type demandedLocal = vm->callStack.top().declarables.at(id);

    vm->stack.push(demandedLocal);
}