#include "executor.hpp"
#include "virtual_machine.hpp"

void Executor::loadBoolean(VirtualMachine *vm) {
    Value boolean = booleanFrom(static_cast<bool>(vm->advanceInstruction()));

    vm->stack.push(boolean);
}

void Executor::equalBoolean(VirtualMachine *vm) {
    Value firstBoolean = vm->stack.top();
    vm->stack.pop();

    Value secondBoolean = vm->stack.top();
    vm->stack.pop();

    vm->stack.push(booleanFrom(firstBoolean.booleanValue == secondBoolean.booleanValue));
}

void Executor::printBoolean(VirtualMachine *vm) {
    Value firstBoolean = vm->stack.top();
    vm->stack.pop();

    std::cout << firstBoolean.booleanValue << std::endl;
}