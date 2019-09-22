#include "executor.hpp"
#include "../virtual_machine.hpp"

Executor::Executor() {
    this->executables.reserve(OPCODES_COUNT);

    this->executables[HALT] = Executor::halt;
}


void Executor::execute(VirtualMachine *vm, const unsigned char *opcode) {
    this->executables[*opcode](vm);
}

void Executor::halt(VirtualMachine *vm) {
    vm->stop(0);
}
