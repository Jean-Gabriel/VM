#include <gtest/gtest.h>
#include "mock_virtual_machine.hpp"

TEST(GivenATrueCondition, ItShouldJumpToFirstInstruction) {
    const std::vector<Bytecode> program = {
        LOAD_NUMBER, 3,
        LOAD_NUMBER, 3,
        EQUAL_NUMBER,
        JUMP_TRUE, 8, 12,

        LOAD_NUMBER, 1,
        JUMP, 14,

        LOAD_NUMBER, 2,

        HALT
    };
    auto* virtualMachine = MockVirtualMachine::initializeWith(program);

    virtualMachine->run();

    EXPECT_EQ(virtualMachine->getStack()->top().number_value, 1);

    free(virtualMachine);
}

TEST(GivenAFalseCondition, ItShouldJumpToSecondInstruction) {
    const std::vector<Bytecode> program = {
            LOAD_NUMBER, 1,
            LOAD_NUMBER, 3,
            EQUAL_NUMBER,
            JUMP_TRUE, 8, 12,

            LOAD_NUMBER, 1,
            JUMP, 14,

            LOAD_NUMBER, 2,

            HALT
    };
    auto* virtualMachine = MockVirtualMachine::initializeWith(program);

    virtualMachine->run();

    EXPECT_EQ(virtualMachine->getStack()->top().number_value, 2);

    free(virtualMachine);
}