#include <gtest/gtest.h>
#include "mocks/mock_virtual_machine.hpp"

TEST(GivenANumber, ItShouldBeStoredAsAGlobal) {
    const std::vector<uint8_t> program = {
            LOAD_NUMBER, 20,
            STORE_GLOBAL, 1,

            LOAD_GLOBAL, 1,

            HALT,
    };
    auto virtualMachine = MockVirtualMachine::initializeWith(program);

    virtualMachine.run();

    EXPECT_EQ(virtualMachine.getStack()->top().content.numberValue, 20);
}
