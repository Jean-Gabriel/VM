#include "executor.hpp"
#include "virtual_machine.hpp"

void Executor::jumpIfTrue(VirtualMachine *vm) {
    InstructionPointer jumpInstructionPointer = vm->advanceInstruction();
    InstructionPointer elseJumpInstructionPointer = vm->advanceInstruction();
    Value topOfStack = vm->stack.top();
    vm->stack.pop();

    if(topOfStack.booleanValue) {
        vm->setInstructionPointerTo(jumpInstructionPointer);
    } else if(!topOfStack.booleanValue && elseJumpInstructionPointer != -1) {
        vm->setInstructionPointerTo(elseJumpInstructionPointer);
    }
}

void Executor::jumpIfFalse(VirtualMachine *vm) {
    InstructionPointer jumpInstructionPointer = vm->advanceInstruction();
    InstructionPointer elseJumpInstructionPointer = vm->advanceInstruction();
    Value topOfStack = vm->stack.top();
    vm->stack.pop();

    if(!topOfStack.booleanValue) {
        vm->setInstructionPointerTo(jumpInstructionPointer);
    } else if(topOfStack.booleanValue && elseJumpInstructionPointer != -1) {
        vm->setInstructionPointerTo(elseJumpInstructionPointer);
    }
}