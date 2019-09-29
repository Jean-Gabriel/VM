#include "virtual_machine.hpp"
#include <vector>

int main() {

    /* void start() {
            if(20%2 == 0) {
                print(0)
            } else {
                print(20%2);
            }
        }*/

    const std::vector<Bytecode> program = {
            //if(21%2==0)
            LOAD_NUMBER, 2,
            LOAD_NUMBER, 21,
            MOD_NUMBER,
            LOAD_NUMBER, 0,
            EQUAL_NUMBER,
            JUMP_TRUE, 11, 16, // if true jump to 11 else jump to 16

            // { print(0) }
            LOAD_NUMBER, 0,
            PRINT_NUMBER,
            JUMP, 22, // jump over else block

            // { print(21%2) }
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