#include "virtual_machine.hpp"
#include <vector>

/*
 * number num = 20
 * boolean isPair = num%2 == 0
 *
 * void start() {
 *      if(isPair) {
 *          print(0)
 *      } else {
 *          print(1)
 *      }
 * }
 */

int main() {
    const std::vector<Bytecode> program = {
            LOAD_NUMBER, 20,
            STORE_GLOBAL_NUMBER, 0, // number num = 20

            LOAD_NUMBER, 2,
            LOAD_GLOBAL, 0,
            MOD_NUMBER,
            LOAD_NUMBER, 0,
            EQUAL_NUMBER,
            STORE_GLOBAL_BOOLEAN, 1, // boolean isPair = num%2 == 0

            LOAD_BOOLEAN, 1,
            LOAD_GLOBAL, 1,
            EQUAL_BOOLEAN,
            JUMP_TRUE, 22, 27, //if(isPair), else

            LOAD_NUMBER, 0,
            PRINT_NUMBER,
            JUMP, 30, // print(0), skip block

            LOAD_NUMBER, 1,
            PRINT_NUMBER, // print(1), continue

            HALT,
    };
    auto* virtualMachine = VirtualMachine::initializeWith(program);

    virtualMachine->run();

    free(virtualMachine);

    return 0;
}