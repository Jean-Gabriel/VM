#include <gtest/gtest.h>
#include <vector>
#include "../src/vm/virtual_machine.hpp"

TEST(Given_a_virtual_machine_with_a_program, It_should_stop_after_execution) {
    const std::vector<Instruction> program = { HALT };
    auto* virtualMachine = VirtualMachine::initializeWith(program);

    virtualMachine->run();

    EXPECT_EQ(virtualMachine->isRunning(), false);
}