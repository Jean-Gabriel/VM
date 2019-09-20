#include "virtualmachine.hpp"

#include <utility>
#include <iostream>

VirtualMachine* VirtualMachine::initializeWith(const std::vector<Instruction> &program) {
        return new VirtualMachine(program);
}

VirtualMachine::VirtualMachine(std::vector<Instruction> program): program(std::move(program)) {
    state.instructionPointer = 0;
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
            this->stopWithError("The program ran out of instructions before halting!");
        } else {
            this->goToNextInstruction();
        }
    }
}

void VirtualMachine::stop() {
    this->state.isRunning = false;
}

void VirtualMachine::stopWithError(const std::string& error) {
    std::cout << "[ERROR]: " << error << std::endl;
    this->stop();
}

bool VirtualMachine::instructionPointerIsOutOfBound() {
    return this->state.instructionPointer >= program.size();
}
