#include <iostream>
#include "memory.hpp"

Memory Memory::createWithSize(uint16_t bytes) {
    return Memory(bytes);
}

Memory::Memory(uint16_t size) {
    this->block.resize(size);
}

void Memory::resize(uint16_t toSize){
    this->block.resize(toSize);
}

Pointer Memory::allocate(std::vector<uint8_t> values) {
    uint16_t sizeOfAllocation = values.size();
    uint16_t numberOfFreeBytesInARow = 0;
    Pointer memoryIndex = 0;

    while(numberOfFreeBytesInARow != sizeOfAllocation) {
        if(this->block.size() <= memoryIndex) {
            this->resize(this->block.size() + sizeOfAllocation - numberOfFreeBytesInARow);
        }

        if(!this->block[memoryIndex++].isAllocated()) {
            numberOfFreeBytesInARow++;
        } else {
            numberOfFreeBytesInARow = 0;
        }
    }

    auto startingPointer = memoryIndex - sizeOfAllocation;

    for(size_t i = startingPointer;i<memoryIndex;i++) {
        this->block[i].write(values.front());
        values.erase(values.begin(), values.begin()+1);
    }

    return startingPointer;
}

void Memory::freeAt(Pointer offset, uint16_t sizeOfDeletion) {
    Pointer endOfDeletionIndex = offset + sizeOfDeletion;

    for(Pointer index = offset;index<endOfDeletionIndex;index++) {
        this->block[index].free();
    }
}

void Memory::dump() {
    for(auto & chunk : this->block) {
        if(chunk.isAllocated()) {
            std::cout << chunk.read() << std::endl;
        }
    }
}