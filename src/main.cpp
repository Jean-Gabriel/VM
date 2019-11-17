#include "virtual_machine.hpp"
#include <vector>

int main() {
    const std::vector<uint8_t > program = {
            DECLARE_FUNCTION, 0, 21, 0,

            DECLARE_OBJECT, 0,
            DECLARE_OBJECT_ATTRIBUTE, 0, 0, NUMBER,
            DECLARE_OBJECT_ATTRIBUTE, 0, 1, OBJECT,
            DECLARE_OBJECT_ATTRIBUTE, 0, 2, BOOLEAN,

            CALL_FUNCTION, 0,
            HALT,

            LOAD_OBJECT, 0,
            STORE_LOCAL, 0,

            LOAD_LOCAL, 0,
            LOAD_STRING, 'J', 'o', 'h', 'n', ' ', 'P', 'a', 'b', 'l', 'o', '\0',
            STORE_ATTRIBUTE, 1,

            LOAD_LOCAL, 0,
            LOAD_NUMBER, 21,
            STORE_ATTRIBUTE, 0,

            LOAD_LOCAL, 0,
            LOAD_BOOLEAN, 1,
            STORE_ATTRIBUTE, 2,

            LOAD_LOCAL, 0,
            LOAD_ATTRIBUTE, 1,
            PRINT_STRING,

            LOAD_LOCAL, 0,
            LOAD_ATTRIBUTE, 0,
            PRINT_NUMBER,

            LOAD_LOCAL, 0,
            LOAD_ATTRIBUTE, 2,
            PRINT_BOOLEAN,

            RETURN,
    };
    auto virtualMachine = VirtualMachine::initializeWith(program);

    virtualMachine.run();

    return 0;
}