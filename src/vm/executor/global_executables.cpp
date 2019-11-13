#include <value.hpp>
#include "executor.hpp"
#include "virtual_machine.hpp"

void Executor::storeGlobal(VirtualMachine *vm) {
    uint8_t id = vm->advanceInstruction();
    Value globalToStore = vm->stack.top();
    vm->stack.pop();

    vm->globals.insert(std::pair<uint8_t, Value>(id, globalToStore));
}

void Executor::loadGlobal(VirtualMachine *vm) {
    uint8_t idToLoad = vm->advanceInstruction();
    Value requestedGlobal = vm->globals.at(idToLoad);

    vm->stack.push(requestedGlobal);
}
