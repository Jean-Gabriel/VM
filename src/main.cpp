#include "virtual_machine.hpp"
#include <vector>

int main() {

    /* void start() {
            print((20%2) == 0)
        }*/

    const std::vector<Bytecode> program = {
            LOAD_NUMBER, 2,
            LOAD_NUMBER, 20,
            MOD_NUMBER,
            LOAD_NUMBER, 0,
            EQUAL_NUMBER,
            LOAD_BOOLEAN, 1,
            EQUAL_BOOLEAN,
            PRINT_BOOLEAN,
            HALT
    };
    auto* virtualMachine = VirtualMachine::initializeWith(program);

    virtualMachine->run();

    free(virtualMachine);

    return 0;
}