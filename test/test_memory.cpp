#include <gtest/gtest.h>
#include "mocks/mock_memory.hpp"

TEST(GivenAFullMemory, ItShouldResizeAndAllocate) {
    auto memory = MockMemory::createWithSize(1);
    memory.allocate({1});
    const std::vector<uint16_t> values = { 1, 2, 3 };

    memory.allocate(values);

    EXPECT_EQ(memory.getBlock().size(), 5);
}

TEST(GivenAnEmptyMemory, ItShouldWriteToMemory) {
    auto memory = MockMemory::createWithSize(3);
    const std::vector<uint16_t> values = { 1, 2, 3 };

    memory.allocate(values);

    EXPECT_EQ(memory.getBlock()[0].read(), 0);
    EXPECT_EQ(memory.getBlock()[1].read(), 1);
    EXPECT_EQ(memory.getBlock()[2].read(), 2);
    EXPECT_EQ(memory.getBlock()[3].read(), 3);
}

TEST(GivenAMemoryWithAllocatedChunks, ItShouldFreeFromPointerAndSize) {
    auto memory = MockMemory::createWithSize(2);
    const std::vector<uint16_t> values = { 1, 2 };
    uint16_t startingPoint = memory.allocate(values);

    memory.freeAt(startingPoint, values.size());

    EXPECT_EQ(memory.getBlock()[0].isAllocated(), true);
    EXPECT_EQ(memory.getBlock()[1].isAllocated(), false);
    EXPECT_EQ(memory.getBlock()[2].isAllocated(), false);
}

TEST(GivenAMemoryWithAllocatedChunks, ItShouldUpdateMemory) {
    auto memory = MockMemory::createWithSize(10);
    std::vector<uint16_t> initialValues = {1, 2, 3};
    uint16_t startingPoint = memory.allocate(initialValues);

    initialValues = {10, 11 ,12};
    memory.updateAt(startingPoint, initialValues);

    std::vector<uint16_t> afterUpdateValues = memory.readAt(startingPoint, initialValues.size());
    EXPECT_EQ(afterUpdateValues[0], 10);
    EXPECT_EQ(afterUpdateValues[1], 11);
    EXPECT_EQ(afterUpdateValues[2], 12);

    EXPECT_EQ(memory.getBlock()[0].read(), 0);
    EXPECT_EQ(memory.getBlock()[1].read(), 10);
    EXPECT_EQ(memory.getBlock()[2].read(), 11);
    EXPECT_EQ(memory.getBlock()[3].read(), 12);
    EXPECT_EQ(memory.getBlock()[4].isAllocated(), false);
}