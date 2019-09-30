#include <gtest/gtest.h>
#include "mock_virtual_machine.hpp"

TEST(GivenTwoNumbersOnTheStack, ItShouldAddTheNumbers) {
    const std::vector<Bytecode> program = {
            LOAD_NUMBER, 1,
            LOAD_NUMBER, 2,
            ADD_NUMBER,
    };
    auto virtualMachine = MockVirtualMachine::initializeWith(program);

    virtualMachine.run();

    EXPECT_EQ(virtualMachine.getStack()->top().number_value, 3);


}

TEST(GivenTwoNumbersOnTheStack, ItShouldMultiplyTheNumbers) {
    const std::vector<Bytecode> program = {
            LOAD_NUMBER, 2,
            LOAD_NUMBER, 3,
            MULTIPLY_NUMBER,
    };
    auto virtualMachine = MockVirtualMachine::initializeWith(program);

    virtualMachine.run();

    EXPECT_EQ(virtualMachine.getStack()->top().number_value, 6);


}

TEST(GivenTwoNumbersOnTheStack, ItShouldSubstractTheNumbers) {
    const std::vector<Bytecode> program = {
            LOAD_NUMBER, 2,
            LOAD_NUMBER, 5,
            SUBTRACT_NUMBER,
    };
    auto virtualMachine = MockVirtualMachine::initializeWith(program);

    virtualMachine.run();

    EXPECT_EQ(virtualMachine.getStack()->top().number_value, 3);


}

TEST(GivenTwoNumbersOnTheStack, ItShouldDevideTheNumbers) {
    const std::vector<Bytecode> program = {
            LOAD_NUMBER, 2,
            LOAD_NUMBER, 4,
            DIVIDE_NUMBER,
    };
    auto virtualMachine = MockVirtualMachine::initializeWith(program);

    virtualMachine.run();

    EXPECT_EQ(virtualMachine.getStack()->top().number_value, 2);


}

TEST(GivenTwoNumbersOnTheStack, ItShouldFindModuloOfGivenNumbers) {
    const std::vector<Bytecode> program = {
            LOAD_NUMBER, 2,
            LOAD_NUMBER, 4,
            MOD_NUMBER,
    };
    auto virtualMachine = MockVirtualMachine::initializeWith(program);

    virtualMachine.run();

    EXPECT_EQ(virtualMachine.getStack()->top().number_value, 0);


}

TEST(GivenTwoNumbersOnTheStack, ItShouldCalculatePowerOfGivenNumbers) {
    const std::vector<Bytecode> program = {
            LOAD_NUMBER, 2,
            LOAD_NUMBER, 3,
            POW_NUMBER,
    };
    auto virtualMachine = MockVirtualMachine::initializeWith(program);

    virtualMachine.run();

    EXPECT_EQ(virtualMachine.getStack()->top().number_value, 9);


}

TEST(GivenTwoNumbersOnTheStack, TheyShouldBeEqual) {
    const std::vector<Bytecode> program = {
            LOAD_NUMBER, 2,
            LOAD_NUMBER, 2,
            EQUAL_NUMBER,
    };
    auto virtualMachine = MockVirtualMachine::initializeWith(program);

    virtualMachine.run();

    EXPECT_EQ(virtualMachine.getStack()->top().boolean_value, true);


}

TEST(GivenTwoNumbersOnTheStack, TheyShouldNotBeEqual) {
    const std::vector<Bytecode> program = {
            LOAD_NUMBER, 2,
            LOAD_NUMBER, 3,
            EQUAL_NUMBER,
    };
    auto virtualMachine = MockVirtualMachine::initializeWith(program);

    virtualMachine.run();

    EXPECT_EQ(virtualMachine.getStack()->top().boolean_value, false);


}

TEST(GivenTwoNumbersOnTheStack, TheSecondShouldBeGreater) {
    const std::vector<Bytecode> program = {
            LOAD_NUMBER, 2,
            LOAD_NUMBER, 3,
            GREATER_THAN_NUMBER,
    };
    auto virtualMachine = MockVirtualMachine::initializeWith(program);

    virtualMachine.run();

    EXPECT_EQ(virtualMachine.getStack()->top().boolean_value, true);


}

TEST(GivenTwoNumbersOnTheStack, TheSecondShouldBeGreaterOrEqual) {
    const std::vector<Bytecode> program = {
            LOAD_NUMBER, 2,
            LOAD_NUMBER, 3,
            GREATER_THAN_EQUAL_NUMBER,
            LOAD_NUMBER, 3,
            LOAD_NUMBER, 3,
            GREATER_THAN_EQUAL_NUMBER,
    };
    auto virtualMachine = MockVirtualMachine::initializeWith(program);

    virtualMachine.run();

    EXPECT_EQ(virtualMachine.getStack()->top().boolean_value, true);
    virtualMachine.getStack()->pop();

    EXPECT_EQ(virtualMachine.getStack()->top().boolean_value, true);


}

TEST(GivenTwoNumbersOnTheStack, TheSecondShouldBeLowerOrEqual) {
    const std::vector<Bytecode> program = {
            LOAD_NUMBER, 3,
            LOAD_NUMBER, 2,
            GREATER_THAN_NUMBER,
            LOAD_NUMBER, 3,
            LOAD_NUMBER, 3,
            GREATER_THAN_NUMBER,

    };
    auto virtualMachine = MockVirtualMachine::initializeWith(program);

    virtualMachine.run();

    EXPECT_EQ(virtualMachine.getStack()->top().boolean_value, false);
    virtualMachine.getStack()->pop();

    EXPECT_EQ(virtualMachine.getStack()->top().boolean_value, false);


}

TEST(GivenTwoNumbersOnTheStack, TheSecondShouldBeLower) {
    const std::vector<Bytecode> program = {
            LOAD_NUMBER, 5,
            LOAD_NUMBER, 2,
            GREATER_THAN_EQUAL_NUMBER,
    };
    auto virtualMachine = MockVirtualMachine::initializeWith(program);

    virtualMachine.run();

    EXPECT_EQ(virtualMachine.getStack()->top().boolean_value, false);
}