#include "virtual_machine.hpp"

#include <utility>
#include <iostream>

VirtualMachine* VirtualMachine::initializeWith(const std::vector<Bytecode> &program) {
        return new VirtualMachine(program);
}

VirtualMachine::VirtualMachine(std::vector<Bytecode> program): program(std::move(program)) {
    this->state.instructionPointer = 0;
}

Bytecode VirtualMachine::advanceInstruction() {
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

void VirtualMachine::stop(ReturnCode code) {
    std::cout << "Machine exited with code " << code << std::endl;
    this->state.isRunning = false;
}

bool VirtualMachine::instructionPointerIsOutOfBound() {
    return this->state.instructionPointer >= program.size();
}

void VirtualMachine::setInstructionPointerTo(InstructionPointer pointer) {
    this->state.instructionPointer = pointer;
}
