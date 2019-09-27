#include "executor.hpp"
#include "virtual_machine.hpp"

void Executor::loadBoolean(VirtualMachine *vm) {
    Type boolean = booleanFrom(static_cast<bool>(vm->advanceInstruction()));

    vm->stack.push(boolean);
}

void Executor::equalBoolean(VirtualMachine *vm) {
    Type firstBoolean = vm->stack.top();
    vm->stack.pop();

    Type secondBoolean = vm->stack.top();
    vm->stack.pop();

    vm->stack.push(booleanFrom(firstBoolean.boolean_value == secondBoolean.boolean_value));
}

void Executor::printBoolean(VirtualMachine *vm) {
    Type firstBoolean = vm->stack.top();
    vm->stack.pop();

    std::cout << firstBoolean.boolean_value << std::endl;
}