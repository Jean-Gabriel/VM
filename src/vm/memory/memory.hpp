#ifndef VIRTUAL_MACHINE_MEMORY_HPP
#define VIRTUAL_MACHINE_MEMORY_HPP

#include <vector>
#include "chunk.hpp"

struct StringMemoryInformation;
typedef uint16_t Pointer;

class Memory {
protected:
    friend class Executor;

    std::vector<Chunk> block;
    void resize(uint16_t);

    explicit Memory(uint16_t);
public:
    std::string stringFrom(StringMemoryInformation memoryInformation);

    static Memory createWithSize(uint16_t);
    Pointer allocate(std::vector<uint8_t>);
    void freeAt(Pointer,uint16_t);

    void dump();
};


#endif //VIRTUAL_MACHINE_MEMORY_HPP
