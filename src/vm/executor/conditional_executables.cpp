#include "executor.hpp"
#include "virtual_machine.hpp"

void Executor::jumpIfTrue(VirtualMachine *vm) {
    InstructionPointer jumpInstructionPointer = vm->advanceInstruction();
    InstructionPointer elseJumpInstructionPointer = vm->advanceInstruction();
    Type topOfStack = vm->stack.top();
    vm->stack.pop();

    if(topOfStack.boolean_value) {
        vm->setInstructionPointerTo(jumpInstructionPointer);
    } else if(!topOfStack.boolean_value && elseJumpInstructionPointer != -1) {
        vm->setInstructionPointerTo(elseJumpInstructionPointer);
    }
}

void Executor::jumpIfFalse(VirtualMachine *vm) {
    InstructionPointer jumpInstructionPointer = vm->advanceInstruction();
    InstructionPointer elseJumpInstructionPointer = vm->advanceInstruction();
    Type topOfStack = vm->stack.top();
    vm->stack.pop();

    if(!topOfStack.boolean_value) {
        vm->setInstructionPointerTo(jumpInstructionPointer);
    } else if(topOfStack.boolean_value && elseJumpInstructionPointer != -1) {
        vm->setInstructionPointerTo(elseJumpInstructionPointer);
    }
}