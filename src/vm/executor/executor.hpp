#ifndef VIRTUAL_MACHINE_EXECUTOR_HPP
#define VIRTUAL_MACHINE_EXECUTOR_HPP

#include <vector>
#include <cstdint>
#include "../opcodes.hpp"

class VirtualMachine;
typedef uint8_t Bytecode;

class Executor {
private:
    std::vector<void (*)(VirtualMachine*)> executables;

    static void halt(VirtualMachine*);

    static void loadNumber(VirtualMachine*);
    static void addNumber(VirtualMachine*);
    static void multiplyNumber(VirtualMachine*);
    static void divideNumber(VirtualMachine*);
    static void subtractNumber(VirtualMachine*);
    static void modNumber(VirtualMachine*);
    static void equalNumber(VirtualMachine*);
    static void notEqualNumber(VirtualMachine*);
    static void greaterThanNumber(VirtualMachine*);
    static void greaterEqualThanNumber(VirtualMachine*);
    static void lessThanNumber(VirtualMachine*);
    static void lessEqualThanNumber(VirtualMachine*);
    static void printNumber(VirtualMachine*);
public:
    explicit Executor();
    void execute(VirtualMachine*, const Bytecode* operation) const;
};

#endif //VIRTUAL_MACHINE_EXECUTOR_HPP