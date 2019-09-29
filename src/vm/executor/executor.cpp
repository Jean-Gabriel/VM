#include "executor.hpp"
#include "../virtual_machine.hpp"

Executor::Executor() {
    this->executables.reserve(OPCODES_COUNT);

    this->executables[LOAD_NUMBER] = Executor::loadNumber;
    this->executables[PRINT_NUMBER] = Executor::printNumber;
    this->executables[ADD_NUMBER] = Executor::addNumber;
    this->executables[MULTIPLY_NUMBER] = Executor::multiplyNumber;
    this->executables[DIVIDE_NUMBER] = Executor::divideNumber;
    this->executables[SUBTRACT_NUMBER] = Executor::subtractNumber;
    this->executables[MOD_NUMBER] = Executor::modNumber;
    this->executables[EQUAL_NUMBER] = Executor::equalNumber;
    this->executables[GREATER_THAN_NUMBER] = Executor::greaterThanNumber;
    this->executables[GREATER_THAN_EQUAL_NUMBER] = Executor::greaterEqualThanNumber;

    this->executables[LOAD_BOOLEAN] = Executor::loadBoolean;
    this->executables[EQUAL_BOOLEAN] = Executor::equalBoolean;
    this->executables[PRINT_BOOLEAN] = Executor::printBoolean;

    this->executables[JUMP_TRUE] = Executor::jumpIfTrue;
    this->executables[JUMP_FALSE] = Executor::jumpIfFalse;
    this->executables[JUMP] = Executor::jump;

    this->executables[HALT] = Executor::halt;
}


void Executor::execute(VirtualMachine *vm, const Bytecode *operation) const {
    this->executables[*operation](vm);
}

void Executor::jump(VirtualMachine* vm) {
    InstructionPointer jumpInstructionPointer = vm->advanceInstruction();

    vm->setInstructionPointerTo(jumpInstructionPointer);
}

void Executor::halt(VirtualMachine *vm) {
    vm->stop(0);
}
