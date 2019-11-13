#include <gtest/gtest.h>
#include "mocks/mock_virtual_machine.hpp"

TEST(GivenAStoredLocal, ItShouldLoadTheLocalOnToTheStack) {
    const std::vector<uint8_t> program = {
            DECLARE_FUNCTION, 0, 6, 0,

            CALL_FUNCTION, 0,

            LOAD_NUMBER, 1,
            STORE_LOCAL, 0,
            LOAD_NUMBER, 2,
            LOAD_LOCAL, 0,
            HALT,
    };
    auto virtualMachine = MockVirtualMachine::initializeWith(program);

    virtualMachine.run();

    EXPECT_EQ(virtualMachine.getStack()->top().content.numberValue, 1);
}