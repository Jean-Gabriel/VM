#include <gtest/gtest.h>
#include "mock_virtual_machine.hpp"

TEST(GivenANumber, ItShouldBeStoredAsAGlobal) {
    const std::vector<Bytecode> program = {
            LOAD_NUMBER, 20,
            STORE_GLOBAL_NUMBER, 1,

            LOAD_GLOBAL, 1,

            HALT,
    };
    auto* virtualMachine = MockVirtualMachine::initializeWith(program);

    virtualMachine->run();

    EXPECT_EQ(virtualMachine->getStack()->top().number_value,20);

    free(virtualMachine);
}

TEST(GivenABoolean, ItShouldBeStoredAsAGlobal) {
    const std::vector<Bytecode> program = {
            LOAD_BOOLEAN, 1,
            STORE_GLOBAL_BOOLEAN, 1,

            LOAD_GLOBAL, 1,

            HALT,
    };
    auto* virtualMachine = MockVirtualMachine::initializeWith(program);

    virtualMachine->run();

    EXPECT_EQ(virtualMachine->getStack()->top().boolean_value,true);

    free(virtualMachine);
}