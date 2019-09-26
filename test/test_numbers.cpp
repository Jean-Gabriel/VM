#include <gtest/gtest.h>
#include "../src/vm/virtual_machine.hpp"

class MockVirtualMachine: public VirtualMachine {
public:
    std::stack<Type*> getStack() {
        return this->stack;
    };
    explicit MockVirtualMachine(const std::vector<Bytecode>& program) : VirtualMachine(program) {}

    static MockVirtualMachine* initializeWith(const std::vector<Bytecode> &program) {
        return new MockVirtualMachine(program);
    }
};

TEST(GivenTwoNumbersOnTheStack, ItShouldAddTheNumbers) {
    const std::vector<Bytecode> program = {
            LOAD_NUMBER, 1,
            LOAD_NUMBER, 2,
            ADD_NUMBER,
    };
    auto* virtualMachine = MockVirtualMachine::initializeWith(program);

    virtualMachine->run();

    EXPECT_EQ(virtualMachine->getStack().top()->number_value, 3);

    free(virtualMachine);
}

TEST(GivenTwoNumbersOnTheStack, ItShouldMultiplyTheNumbers) {
    const std::vector<Bytecode> program = {
            LOAD_NUMBER, 2,
            LOAD_NUMBER, 3,
            MULTIPLY_NUMBER,
    };
    auto* virtualMachine = MockVirtualMachine::initializeWith(program);

    virtualMachine->run();

    EXPECT_EQ(virtualMachine->getStack().top()->number_value, 6);

    free(virtualMachine);
}