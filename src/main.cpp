#include "virtual_machine.hpp"
#include <vector>

int main() {
    const std::vector<uint8_t > program = {
            HALT,
    };
    auto virtualMachine = VirtualMachine::initializeWith(program);

    virtualMachine.run();

    return 0;
}