#include "virtual_machine.hpp"
#include <vector>

int main() {
    const std::vector<Bytecode> program = {
            LOAD_NUMBER, 2,
            LOAD_NUMBER, 21,
            MOD_NUMBER,
            PRINT_NUMBER,
            HALT
    };
    auto* virtualMachine = VirtualMachine::initializeWith(program);

    virtualMachine->run();

    free(virtualMachine);

    return 0;
}