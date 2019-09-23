#include "executor.hpp"
#include "../virtual_machine.hpp"

Executor::Executor() {
    this->executables.reserve(OPCODES_COUNT);

    this->executables[LOAD_NUMBER] = Executor::loadNumber;
    this->executables[PRINT_NUMBER] = Executor::printNumber;

    this->executables[HALT] = Executor::halt;
}


void Executor::execute(VirtualMachine *vm, const Bytecode *operation) const {
    this->executables[*operation](vm);
}

void Executor::halt(VirtualMachine *vm) {
    vm->stop(0);
}
