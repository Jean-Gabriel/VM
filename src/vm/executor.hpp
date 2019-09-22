#ifndef VIRTUAL_MACHINE_EXECUTOR_HPP
#define VIRTUAL_MACHINE_EXECUTOR_HPP

#include <vector>
#include "opcodes.hpp"

class VirtualMachine;

class Executor {
private:
    std::vector<void (*)(VirtualMachine*)> executables;

    static void halt(VirtualMachine*);
public:
    explicit Executor();
    void execute(VirtualMachine*, const unsigned char*);
};

#endif //VIRTUAL_MACHINE_EXECUTOR_HPP
