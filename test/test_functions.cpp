#include <gtest/gtest.h>
#include "mocks/mock_virtual_machine.hpp"

TEST(GivenADeclaredFunction, ItShouldBeCalledWhenInstructedTo) {
const std::vector<uint8_t> program = {
        DECLARE_FUNCTION, 0, 11, 1,

        LOAD_NUMBER, 7,
        CALL_FUNCTION, 0,
        HALT,

        LOAD_NUMBER, 1,
        LOAD_LOCAL, 0,
        RETURN,

        LOAD_NUMBER, 1,
};
auto virtualMachine = MockVirtualMachine::initializeWith(program);

virtualMachine.run();

EXPECT_EQ(virtualMachine.getStack()->top().content.numberValue, 7);
}