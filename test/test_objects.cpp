#include <gtest/gtest.h>
#include "mocks/mock_virtual_machine.hpp"

TEST(GivenAnObjectWithADeclareObject_WhenAskingForOffsetOfGivenAttribute, ItShouldGiveCalculatedOffset) {
    const std::vector<uint8_t> program = {
            DECLARE_OBJECT, 0,
            DECLARE_OBJECT_ATTRIBUTE, 0, 0, NUMBER,
            DECLARE_OBJECT_ATTRIBUTE, 0, 1, BOOLEAN,
            DECLARE_OBJECT_ATTRIBUTE, 0, 2, OBJECT,

            HALT
    };
    auto virtualMachine = MockVirtualMachine::initializeWith(program);

    virtualMachine.run();

    EXPECT_EQ(calculateAttributeOffsetOf(virtualMachine.getDeclaredObject().at(0), 0), 1);
    EXPECT_EQ(calculateAttributeOffsetOf(virtualMachine.getDeclaredObject().at(0), 1), 5);
    EXPECT_EQ(calculateAttributeOffsetOf(virtualMachine.getDeclaredObject().at(0), 2), 6);
}

TEST(GivenAnObjectWithANumberAttribute, ItShouldStoreAttribute) {
    const std::vector<uint8_t> program = {
            DECLARE_OBJECT, 0,
            DECLARE_OBJECT_ATTRIBUTE, 0 , 0, NUMBER,

            LOAD_OBJECT, 0,
            STORE_GLOBAL, 0,

            LOAD_GLOBAL, 0,
            LOAD_NUMBER, 23,
            STORE_ATTRIBUTE, 0,

            HALT,
    };
    auto virtualMachine = MockVirtualMachine::initializeWith(program);
    std::vector<uint16_t> expectedBytes = bytesFrom(numberValueFrom(23));

    virtualMachine.run();
    std::vector<uint16_t> readBytes = virtualMachine.getMemory().readAt(2, 6);

    EXPECT_EQ(readBytes[0], expectedBytes[0]);
    EXPECT_EQ(readBytes[1], expectedBytes[1]);
    EXPECT_EQ(readBytes[2], expectedBytes[2]);
    EXPECT_EQ(readBytes[3], expectedBytes[3]);
}

TEST(GivenAnObjectWithABooleanAttribute, ItShouldStoreAttribute) {
    const std::vector<uint8_t> program = {
            DECLARE_OBJECT, 0,
            DECLARE_OBJECT_ATTRIBUTE, 0 , 0, BOOLEAN,

            LOAD_OBJECT, 0,
            STORE_GLOBAL, 0,

            LOAD_GLOBAL, 0,
            LOAD_BOOLEAN, 1,
            STORE_ATTRIBUTE, 0,

            HALT,
    };
    auto virtualMachine = MockVirtualMachine::initializeWith(program);
    std::vector<uint16_t> expectedBytes = bytesFrom(booleanValueFrom(true));

    virtualMachine.run();
    std::vector<uint16_t> readBytes = virtualMachine.getMemory().readAt(2, 1);

    EXPECT_EQ(readBytes[0], expectedBytes[0]);
}

TEST(GivenAnObjectWithAnObjectAttribute, ItShouldStoreAttribute) {
    const std::vector<uint8_t> program = {
            DECLARE_OBJECT, 0,
            DECLARE_OBJECT_ATTRIBUTE, 0 , 0, OBJECT,

            LOAD_OBJECT, 0,
            STORE_GLOBAL, 0,

            LOAD_GLOBAL, 0,
            LOAD_STRING, 'H', 'e', 'y', '\0',
            STORE_ATTRIBUTE, 0,

            HALT,
    };
    auto virtualMachine = MockVirtualMachine::initializeWith(program);
    std::vector<uint16_t> expectedBytes = bytesFrom(objectValueFrom(4, 3));

    virtualMachine.run();
    std::vector<uint16_t> readBytes = virtualMachine.getMemory().readAt(2, 2);

    EXPECT_EQ(readBytes[0], expectedBytes[0]);
    EXPECT_EQ(readBytes[1], expectedBytes[1]);
}

TEST(GivenAnObjectWithANumberAttribute, ItShouldLoadAttributeOnTheStack) {
    const std::vector<uint8_t> program = {
            DECLARE_OBJECT, 0,
            DECLARE_OBJECT_ATTRIBUTE, 0 , 0, NUMBER,

            LOAD_OBJECT, 0,
            STORE_GLOBAL, 0,

            LOAD_GLOBAL, 0,
            LOAD_NUMBER, 23,
            STORE_ATTRIBUTE, 0,

            LOAD_NUMBER, 1,

            LOAD_GLOBAL, 0,
            LOAD_ATTRIBUTE, 0,

            HALT
    };
    auto virtualMachine = MockVirtualMachine::initializeWith(program);

    virtualMachine.run();

    EXPECT_EQ(virtualMachine.getStack()->top().content.numberValue, 23);
}

TEST(GivenAnObjectWithABooleanAttribute, ItShouldLoadAttributeOnTheStack) {
    const std::vector<uint8_t> program = {
            DECLARE_OBJECT, 0,
            DECLARE_OBJECT_ATTRIBUTE, 0 , 0, BOOLEAN,

            LOAD_OBJECT, 0,
            STORE_GLOBAL, 0,

            LOAD_GLOBAL, 0,
            LOAD_BOOLEAN, 1,
            STORE_ATTRIBUTE, 0,

            LOAD_BOOLEAN, 0,

            LOAD_GLOBAL, 0,
            LOAD_ATTRIBUTE, 0,

            HALT
    };
    auto virtualMachine = MockVirtualMachine::initializeWith(program);

    virtualMachine.run();

    EXPECT_EQ(virtualMachine.getStack()->top().content.booleanValue, true);
}

TEST(GivenAnObjectWithStringAttribute, ItShouldLoadAttributeOnTheStack) {
    const std::vector<uint8_t> program = {
            DECLARE_OBJECT, 0,
            DECLARE_OBJECT_ATTRIBUTE, 0 , 0, OBJECT,

            LOAD_OBJECT, 0,
            STORE_GLOBAL, 0,

            LOAD_GLOBAL, 0,
            LOAD_STRING, 'H', 'e', 'l', 'l', 'o', '\0',
            STORE_ATTRIBUTE, 0,

            LOAD_STRING, 'H', 'I', '\0',

            LOAD_GLOBAL, 0,
            LOAD_ATTRIBUTE, 0,

            HALT
    };
    auto virtualMachine = MockVirtualMachine::initializeWith(program);

    virtualMachine.run();
    std::string loadedString = virtualMachine.getMemory().stringFrom(virtualMachine.getStack()->top().content.objectValue);

    EXPECT_EQ(loadedString, "Hello");
}

TEST(GivenAnObjectWithMultipleAttribute, ItShouldCorrectlyUpdateAttributes) {
    const std::vector<uint8_t> program = {
            DECLARE_OBJECT, 0,
            DECLARE_OBJECT_ATTRIBUTE, 0, 0, NUMBER,
            DECLARE_OBJECT_ATTRIBUTE, 0, 1, OBJECT,
            DECLARE_OBJECT_ATTRIBUTE, 0, 2, BOOLEAN,

            LOAD_OBJECT, 0,
            STORE_GLOBAL, 0,

            LOAD_GLOBAL, 0,
            LOAD_NUMBER, 23,
            STORE_ATTRIBUTE, 0,

            LOAD_GLOBAL, 0,
            LOAD_STRING, 'H', 'e', 'y', '\0',
            STORE_ATTRIBUTE, 1,

            LOAD_GLOBAL, 0,
            LOAD_STRING, 'H', 'e', 'y', ' ', 'y', 'o', 'u', '\0',
            STORE_ATTRIBUTE, 1,

            LOAD_GLOBAL, 0,
            LOAD_BOOLEAN, 1,
            STORE_ATTRIBUTE, 2,

            LOAD_GLOBAL, 0,
            LOAD_ATTRIBUTE, 2,

            LOAD_GLOBAL, 0,
            LOAD_ATTRIBUTE, 1,

            LOAD_GLOBAL, 0,
            LOAD_ATTRIBUTE, 0,

            HALT
    };
    auto virtualMachine = MockVirtualMachine::initializeWith(program);

    virtualMachine.run();

    Value firstAttribute = virtualMachine.getStack()->top();
    virtualMachine.getStack()->pop();

    std::string secondAttributeValue = virtualMachine.getMemory().stringFrom(virtualMachine.getStack()->top().content.objectValue);
    virtualMachine.getStack()->pop();

    Value thirdAttribute = virtualMachine.getStack()->top();
    virtualMachine.getStack()->pop();

    EXPECT_EQ(firstAttribute.content.numberValue, 23);
    EXPECT_EQ(secondAttributeValue, "Hey you");
    EXPECT_EQ(thirdAttribute.content.booleanValue, true);
}

TEST(GivenAnObject, ItShouldFreeObjectMemory) {
    const std::vector<uint8_t> program = {
            DECLARE_OBJECT, 0,
            DECLARE_OBJECT_ATTRIBUTE, 0 , 0, BOOLEAN,

            LOAD_OBJECT, 0,
            STORE_GLOBAL, 0,

            LOAD_GLOBAL, 0,
            LOAD_BOOLEAN, 1,
            STORE_ATTRIBUTE, 0,

            LOAD_GLOBAL, 0,
            DELETE_OBJECT,

            HALT,
    };
    auto virtualMachine = MockVirtualMachine::initializeWith(program);

    virtualMachine.run();
    std::vector<uint16_t> readBytes = virtualMachine.getMemory().readAt(1, 2);

    EXPECT_EQ(readBytes[0], 0);
    EXPECT_EQ(readBytes[1], 0);
}