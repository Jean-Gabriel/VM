#include "virtualmachine.hpp"

#include <utility>
#include <iostream>

VirtualMachine* VirtualMachine::initializeWith(const std::vector<Instruction> &program) {
        return new VirtualMachine(program);
}

VirtualMachine::VirtualMachine(std::vector<Instruction> program): program(std::move(program)) {
    this->state.instructionPointer = 0;
}

void VirtualMachine::goToNextInstruction() {
    this->state.instructionPointer++;
}

bool VirtualMachine::isRunning() {
    return this->state.isRunning;
}

void VirtualMachine::run() {
    this->state.isRunning = true;
    while(this->isRunning()) {
        if(this->instructionPointerIsOutOfBound()) {
            this->stop();
        } else {
            this->goToNextInstruction();
        }
    }
}

void VirtualMachine::stop() {
    this->state.isRunning = false;
}

bool VirtualMachine::instructionPointerIsOutOfBound() {
    return this->state.instructionPointer >= program.size();
}
