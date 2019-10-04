#ifndef VIRTUAL_MACHINE_MOCK_VIRTUAL_MACHINE_HPP
#define VIRTUAL_MACHINE_MOCK_VIRTUAL_MACHINE_HPP
#include "../../src/vm/virtual_machine.hpp"

class MockVirtualMachine: public VirtualMachine {
public:
    std::stack<Type>* getStack() {
        return &this->stack;
    };
    explicit MockVirtualMachine(const std::vector<Bytecode>& program) : VirtualMachine(program) {}

    static MockVirtualMachine initializeWith(const std::vector<Bytecode> &program) {
        return MockVirtualMachine(program);
    }
};

#endif //VIRTUAL_MACHINE_MOCK_VIRTUAL_MACHINE_HPP
