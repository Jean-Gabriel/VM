#ifndef VIRTUAL_MACHINE_CHUNK_HPP
#define VIRTUAL_MACHINE_CHUNK_HPP

#include <cstdint>

enum ChunkFlag {
    ALLOCATED,
    FREE,
};

class Chunk {
private:
    ChunkFlag flag = FREE;
    uint8_t value;
public:
    void write(uint8_t value) {
        this->flag = ALLOCATED;
        this->value = value;
    }

    uint8_t read() {
        return this->value;
    }

    void free() {
        this->value = 0;
        this->flag = FREE;
    }

    bool isAllocated() {
        return this->flag == ALLOCATED;
    }
};

#endif //VIRTUAL_MACHINE_CHUNK_HPP
