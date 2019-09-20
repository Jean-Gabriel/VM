#include <virtualmachine.hpp>
#include <vector>

int main() {
    const std::vector<Instruction> program = {};
    auto* virtualMachine = VirtualMachine::initializeWith(program);

    virtualMachine->run();

    return 0;
}