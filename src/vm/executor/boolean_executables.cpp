#include "executor.hpp"
#include "virtual_machine.hpp"

void Executor::loadBoolean(VirtualMachine *vm) {
    Value boolean = booleanValueFrom(static_cast<bool>(vm->advanceInstruction()));

    vm->stack.push(boolean);
}

void Executor::equalBoolean(VirtualMachine *vm) {
    Value::Content firstBoolean = vm->stack.top().content;
    vm->stack.pop();

    Value::Content secondBoolean = vm->stack.top().content;
    vm->stack.pop();

    vm->stack.push(booleanValueFrom(firstBoolean.booleanValue == secondBoolean.booleanValue));
}

void Executor::printBoolean(VirtualMachine *vm) {
    Value::Content firstBoolean = vm->stack.top().content;
    vm->stack.pop();

    std::cout << firstBoolean.booleanValue << std::endl;
}