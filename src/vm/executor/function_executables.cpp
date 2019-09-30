#include "executor.hpp"
#include "virtual_machine.hpp"

void Executor::doReturn(VirtualMachine *vm) {
    vm->setInstructionPointerTo(vm->callStack.top().returnPoint);
    vm->callStack.pop();
}