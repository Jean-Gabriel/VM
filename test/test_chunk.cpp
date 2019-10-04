#include <gtest/gtest.h>
#include "../src/vm/memory/chunk.hpp"

TEST(GivenANewChunk, ItShoudlBeFreeByDefault) {
    auto chunk = Chunk();

    ASSERT_EQ(chunk.isAllocated(), false);
}

TEST(GivenAChunk, ItShouldBecomeAllocatedOnceWritten) {
    auto chunk = Chunk();
    const uint8_t aValue = 1;

    chunk.write(aValue);

    EXPECT_EQ(chunk.isAllocated(), true);
}

TEST(GivenAChunk, ItShouldBeRestoredToInitializationOnceFreed) {
    auto chunk = Chunk();
    const uint8_t aValue = 1;
    chunk.write(aValue);

    chunk.free();

    EXPECT_EQ(chunk.isAllocated(), false);
    EXPECT_EQ(chunk.read(), 0);
}