#include <gtest/gtest.h>
#include <vector>
#include "mocks/mock_virtual_machine.hpp"

TEST(GivenAVirtualMachineWithAProgram, ItShouldStopAfterExecution) {
    const std::vector<Bytecode> program = { HALT };
    auto virtualMachine = VirtualMachine::initializeWith(program);

    virtualMachine.run();

    EXPECT_EQ(virtualMachine.isRunning(), false);
}