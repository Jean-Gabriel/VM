#ifndef VIRTUAL_MACHINE_MOCK_MEMORY_HPP
#define VIRTUAL_MACHINE_MOCK_MEMORY_HPP

#include "../../src/vm/memory/memory.hpp"

class MockMemory: public Memory {
public:
    std::vector<Chunk> getBlock() const {
        return this->block;
    }

    explicit MockMemory(uint16_t size): Memory(size) {}

    static MockMemory createWithSize(uint16_t bytes) {
        return MockMemory(bytes);
    }
};

#endif //VIRTUAL_MACHINE_MOCK_MEMORY_HPP
