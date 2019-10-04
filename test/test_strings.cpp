#include <gtest/gtest.h>
#include "mocks/mock_virtual_machine.hpp"

TEST(GivenAStringToLoadOnTheStack, ItShouldStoreItsHeapInformationOnTopOfStack) {
    const std::vector<Bytecode> program = {
            LOAD_STRING, 'H', 'e', 'l', 'l', 'o', '\0',
    };
    auto virtualMachine = MockVirtualMachine::initializeWith(program);
    virtualMachine.run();

    Value value = virtualMachine.getStack()->top();
    std::string loadedString = virtualMachine.getMemory().stringFrom(value.stringInformation);

    EXPECT_EQ(loadedString, "Hello");
}

TEST(GivenTwoStringOnTheStack, ItShouldAppendTheStrings) {
    const std::vector<Bytecode> program = {
            LOAD_STRING, 'H', 'e', 'l', 'l', 'o', '\0',
            LOAD_STRING, ' ', 'w', 'o', 'r', 'l', 'd', '\0',
            APPEND_STRING
    };
    auto virtualMachine = MockVirtualMachine::initializeWith(program);
    virtualMachine.run();

    Value value = virtualMachine.getStack()->top();
    std::string loadedString = virtualMachine.getMemory().stringFrom(value.stringInformation);

    EXPECT_EQ(loadedString, "Hello world");
}

TEST(GivenAStringOnTheStack, ItShouldCreateSubstringOfGivenStringAndIndex) {
    const std::vector<Bytecode> program = {
            LOAD_STRING, 'H', 'e', 'l', 'l', 'o', ' ', 'w', 'o', 'r', 'l', 'd', '\0',
            SUBSTRING_AT, 6
    };
    auto virtualMachine = MockVirtualMachine::initializeWith(program);
    virtualMachine.run();

    Value value = virtualMachine.getStack()->top();
    std::string loadedString = virtualMachine.getMemory().stringFrom(value.stringInformation);

    EXPECT_EQ(loadedString, "world");
}

TEST(GivenAStringOnTheStack, ItShouldCreateSubstringWithGivenIndexAndLength) {
    const std::vector<Bytecode> program = {
            LOAD_STRING, 'H', 'e', 'l', 'l', 'o', ' ', 'w', 'o', 'r', 'l', 'd', '\0',
            SUBSTRING_WITH_LENGTH, 0, 5,
    };
    auto virtualMachine = MockVirtualMachine::initializeWith(program);
    virtualMachine.run();

    Value value = virtualMachine.getStack()->top();
    std::string loadedString = virtualMachine.getMemory().stringFrom(value.stringInformation);

    EXPECT_EQ(loadedString, "Hello");
}