#include "executor.hpp"
#include "virtual_machine.hpp"

void Executor::jumpIfTrue(VirtualMachine *vm) {
    int jumpInstructionPointer = vm->advanceInstruction();
    int elseJumpInstructionPointer = vm->advanceInstruction();
    Value::Content topOfStack = vm->stack.top().content;
    vm->stack.pop();

    if(topOfStack.booleanValue) {
        vm->setInstructionPointerTo(jumpInstructionPointer);
    } else if(!topOfStack.booleanValue && elseJumpInstructionPointer != -1) {
        vm->setInstructionPointerTo(elseJumpInstructionPointer);
    }
}

void Executor::jumpIfFalse(VirtualMachine *vm) {
    int  jumpInstructionPointer = vm->advanceInstruction();
    int  elseJumpInstructionPointer = vm->advanceInstruction();
    Value::Content topOfStack = vm->stack.top().content;
    vm->stack.pop();

    if(!topOfStack.booleanValue) {
        vm->setInstructionPointerTo(jumpInstructionPointer);
    } else if(topOfStack.booleanValue && elseJumpInstructionPointer != -1) {
        vm->setInstructionPointerTo(elseJumpInstructionPointer);
    }
}