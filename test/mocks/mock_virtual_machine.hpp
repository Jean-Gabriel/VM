#ifndef VIRTUAL_MACHINE_MOCK_VIRTUAL_MACHINE_HPP
#define VIRTUAL_MACHINE_MOCK_VIRTUAL_MACHINE_HPP
#include "../../src/vm/virtual_machine.hpp"

class MockVirtualMachine: public VirtualMachine {
public:
    std::stack<Value>* getStack() {
        return &this->stack;
    };

    Memory getMemory() const {
        return this->memory;
    }

    explicit MockVirtualMachine(const std::vector<uint8_t>& program) : VirtualMachine(program) {}

    static MockVirtualMachine initializeWith(const std::vector<uint8_t> &program) {
        return MockVirtualMachine(program);
    }
};

#endif //VIRTUAL_MACHINE_MOCK_VIRTUAL_MACHINE_HPP
