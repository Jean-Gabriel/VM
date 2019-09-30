#include <gtest/gtest.h>
#include "mock_virtual_machine.hpp"

TEST(GivenANumber, ItShouldBeStoredAsAGlobal) {
    const std::vector<Bytecode> program = {
            LOAD_NUMBER, 20,
            STORE_GLOBAL, 1,

            LOAD_GLOBAL, 1,

            HALT,
    };
    auto virtualMachine = MockVirtualMachine::initializeWith(program);

    virtualMachine.run();

    EXPECT_EQ(virtualMachine.getStack()->top().number_value,20);
}

TEST(GivenADeclaredGlobalFunction, ItShouldBeCalledWhenInstructedTo) {
    const std::vector<Bytecode> program = {
            DECLARE_GLOBAL_FUNCTION, 0, 11, 1,

            LOAD_NUMBER, 7,
            CALL_GLOBAL_FUNCTION, 0,
            HALT,

            LOAD_NUMBER, 1,
            LOAD_LOCAL, 0,
            RETURN,

            LOAD_NUMBER, 1,
    };
    auto virtualMachine = MockVirtualMachine::initializeWith(program);

    virtualMachine.run();

    EXPECT_EQ(virtualMachine.getStack()->top().number_value,7);
}