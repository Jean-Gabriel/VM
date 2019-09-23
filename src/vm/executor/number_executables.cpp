#include "executor.hpp"
#include "virtual_machine.hpp"

void Executor::loadNumber(VirtualMachine *vm) {
    Type *number = new Type(static_cast<float>(vm->advanceInstruction()));

    vm->stack.push(number);
}

void Executor::printNumber(VirtualMachine *vm) {
    Type *const number = vm->stack.top();
    vm->stack.pop();

    std::cout << number->number_value << std::endl;
}