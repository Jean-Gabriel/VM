#include "virtual_machine.hpp"
#include <vector>

/*
 * boolean isPair(num) {
 *      return num%2==0
 * }
 *
 * void start() {
 *      number givenNumber = 20;
 *      if(isPair(givenNumber)) {
 *          print(0)
 *      } else {
 *          print(1)
 *      }
 * }
 */

int main() {
    const std::vector<Bytecode> program = {
            DECLARE_GLOBAL_FUNCTION, 0, 10, 0, //void start(), at, args count
            DECLARE_GLOBAL_FUNCTION, 1, 30, 1, //boolean isPair(givenNumber), at, args count

            CALL_GLOBAL_FUNCTION, 0, // calls start()

            //void start()
            LOAD_NUMBER, 21,
            STORE_LOCAL, 0, // number givenNumber = 21
            LOAD_LOCAL, 0,
            CALL_GLOBAL_FUNCTION, 1, // isPair(givenNumber)
            JUMP_TRUE, 21, 26, // if(true), else
            LOAD_NUMBER, 0,
            PRINT_NUMBER,
            JUMP, 29,
            LOAD_NUMBER,1,
            PRINT_NUMBER,
            HALT,

            //boolean isPair(givenNumber)
            LOAD_NUMBER, 2,
            LOAD_LOCAL, 0,
            MOD_NUMBER, //givenNumber%2
            LOAD_NUMBER, 0,
            EQUAL_NUMBER, // == 0
            RETURN,

    };
    auto virtualMachine = VirtualMachine::initializeWith(program);

    virtualMachine.run();

    return 0;
}