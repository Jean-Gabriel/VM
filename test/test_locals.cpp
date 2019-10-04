#include <gtest/gtest.h>
#include "mocks/mock_virtual_machine.hpp"

TEST(GivenAStoredLocal, ItShouldLoadTheLocalOnToTheStack) {
    const std::vector<Bytecode> program = {
            DECLARE_GLOBAL_FUNCTION, 0, 6, 0,

            CALL_GLOBAL_FUNCTION, 0,

            LOAD_NUMBER, 1,
            STORE_LOCAL, 0,
            LOAD_NUMBER, 2,
            LOAD_LOCAL, 0,
            HALT,
    };
    auto virtualMachine = MockVirtualMachine::initializeWith(program);

    virtualMachine.run();

    EXPECT_EQ(virtualMachine.getStack()->top().number_value,1);
}