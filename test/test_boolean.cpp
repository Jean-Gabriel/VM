#include <gtest/gtest.h>
#include "mocks/mock_virtual_machine.hpp"

TEST(GivenTwoBoolean, TheyShouldBeEqual) {
    const std::vector<Bytecode> program = {
            LOAD_BOOLEAN, 1,
            LOAD_BOOLEAN, 1,
            EQUAL_BOOLEAN,
    };
    auto virtualMachine = MockVirtualMachine::initializeWith(program);

    virtualMachine.run();

    EXPECT_EQ(virtualMachine.getStack()->top().boolean_value,true);
}

TEST(GivenTwoBoolean, TheyShouldNotBeEqual) {
    const std::vector<Bytecode> program = {
            LOAD_BOOLEAN, 0,
            LOAD_BOOLEAN, 1,
            EQUAL_BOOLEAN,
    };
    auto virtualMachine = MockVirtualMachine::initializeWith(program);

    virtualMachine.run();

    EXPECT_EQ(virtualMachine.getStack()->top().boolean_value,false);
}
