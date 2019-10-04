#include "virtual_machine.hpp"
#include <vector>

int main() {
    const std::vector<Bytecode> program = {
            LOAD_STRING, 'H', 'e', 'l', 'l', 'o', '\0',
            PRINT_STRING,
            HALT,
    };
    auto virtualMachine = VirtualMachine::initializeWith(program);

    virtualMachine.run();

    return 0;
}