#include "virtual_machine.hpp"

#include <utility>
#include <iostream>

VirtualMachine VirtualMachine::initializeWith(const std::vector<uint8_t> &program) {
        return VirtualMachine(program);
}

VirtualMachine::VirtualMachine(std::vector<uint8_t> program): program(std::move(program)), memory(Memory::createWithSize(1000)) {
    this->state.instructionPointer = 0;
}

uint8_t VirtualMachine::advanceInstruction() {
    return this->program[this->state.instructionPointer++];
}

bool VirtualMachine::isRunning() {
    return this->state.isRunning;
}

void VirtualMachine::run() {
    this->state.isRunning = true;
    while(this->isRunning()) {
        if(this->instructionPointerIsOutOfBound()) {
            this->stop(0);
        } else {
            this->executor.execute(this, &this->program[this->state.instructionPointer++]);
        }
    }
}

void VirtualMachine::stop(uint8_t returnCode) {
    std::cout << "Machine exited with code " << std::to_string(returnCode) << std::endl;
    this->state.isRunning = false;
}

bool VirtualMachine::instructionPointerIsOutOfBound() {
    return this->state.instructionPointer >= program.size();
}

void VirtualMachine::setInstructionPointerTo(int pointer) {
    this->state.instructionPointer = pointer;
}
