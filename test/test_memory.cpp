#include <gtest/gtest.h>
#include "mocks/mock_memory.hpp"

TEST(GivenAFullMemory, ItShouldResizeAndAllocate) {
    auto memory = MockMemory::createWithSize(1);
    memory.allocate({1});
    const std::vector<uint8_t > values = { 1, 2, 3 };

    memory.allocate(values);

    EXPECT_EQ(memory.getBlock().size(), 4);
}

TEST(GivenAnEmptyMemory, ItShouldWriteToMemory) {
    auto memory = MockMemory::createWithSize(3);
    const std::vector<uint8_t > values = { 1, 2, 3 };

    memory.allocate(values);

    EXPECT_EQ(memory.getBlock()[0].read(), 1);
    EXPECT_EQ(memory.getBlock()[1].read(), 2);
    EXPECT_EQ(memory.getBlock()[2].read(), 3);
}

TEST(GivenAMemoryWithAllocatedChunks, ItShouldFreeFromPointerAndSize) {
    auto memory = MockMemory::createWithSize(2);
    const std::vector<uint8_t > values = { 1, 2};
    uint16_t startingPoint = memory.allocate(values);

    memory.freeAt(startingPoint, values.size());

    EXPECT_EQ(memory.getBlock()[0].isAllocated(), false);
    EXPECT_EQ(memory.getBlock()[1].isAllocated(), false);
}