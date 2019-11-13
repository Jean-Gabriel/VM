#ifndef VIRTUAL_MACHINE_MEMORY_HPP
#define VIRTUAL_MACHINE_MEMORY_HPP

#include <vector>
#include "chunk.hpp"

struct Object;

class Memory {
protected:
    friend class Executor;

    std::vector<Chunk> block;
    void resize(uint16_t size);

    explicit Memory(uint16_t size);
public:
    std::string stringFrom(Object memoryInformation);

    static Memory createWithSize(uint16_t);
    uint16_t allocate(std::vector<uint8_t> bytes);
    void freeAt(uint16_t offset, uint16_t sizeOfAllocation);

    void dump();
};


#endif //VIRTUAL_MACHINE_MEMORY_HPP
