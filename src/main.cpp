#include "virtual_machine.hpp"
#include "executor/executor.hpp"
#include <vector>

int main() {
    const std::vector<Instruction> program = {
            HALT
    };
    auto* virtualMachine = VirtualMachine::initializeWith(program);

    virtualMachine->run();

    return 0;
}