#include <gtest/gtest.h>
#include "mocks/mock_virtual_machine.hpp"

TEST(GivenTwoBoolean, TheyShouldBeEqual) {
    const std::vector<uint8_t> program = {
            LOAD_BOOLEAN, 1,
            LOAD_BOOLEAN, 1,
            EQUAL_BOOLEAN,
    };
    auto virtualMachine = MockVirtualMachine::initializeWith(program);

    virtualMachine.run();

    EXPECT_EQ(virtualMachine.getStack()->top().content.booleanValue, true);
}

TEST(GivenTwoBoolean, TheyShouldNotBeEqual) {
    const std::vector<uint8_t> program = {
            LOAD_BOOLEAN, 0,
            LOAD_BOOLEAN, 1,
            EQUAL_BOOLEAN,
    };
    auto virtualMachine = MockVirtualMachine::initializeWith(program);

    virtualMachine.run();

    EXPECT_EQ(virtualMachine.getStack()->top().content.booleanValue, false);
}
