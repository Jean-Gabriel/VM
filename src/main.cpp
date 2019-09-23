#include "virtual_machine.hpp"
#include <vector>

int main() {
    const std::vector<Bytecode> program = {
            LOAD_NUMBER, 5,
            PRINT_NUMBER,
            HALT
    };
    auto* virtualMachine = VirtualMachine::initializeWith(program);

    virtualMachine->run();

    return 0;
}