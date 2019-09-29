#ifndef VIRTUAL_MACHINE_EXECUTOR_HPP
#define VIRTUAL_MACHINE_EXECUTOR_HPP

#include <map>
#include <cstdint>
#include "../opcodes.hpp"

class VirtualMachine;
typedef uint8_t Bytecode;

class Executor {
private:
    std::map<Bytecode,void (*)(VirtualMachine*)> executables;

    static void halt(VirtualMachine*);

    static void loadNumber(VirtualMachine*);
    static void addNumber(VirtualMachine*);
    static void multiplyNumber(VirtualMachine*);
    static void divideNumber(VirtualMachine*);
    static void subtractNumber(VirtualMachine*);
    static void modNumber(VirtualMachine*);
    static void powNumber(VirtualMachine *);
    static void equalNumber(VirtualMachine*);
    static void greaterThanNumber(VirtualMachine*);
    static void greaterEqualThanNumber(VirtualMachine*);
    static void printNumber(VirtualMachine*);

    static void loadBoolean(VirtualMachine*);
    static void equalBoolean(VirtualMachine*);
    static void printBoolean(VirtualMachine*);

    static void jumpIfTrue(VirtualMachine*);
    static void jumpIfFalse(VirtualMachine*);
    static void jump(VirtualMachine *);

    static void storeGlobalNumber(VirtualMachine *);
    static void storeGlobalBoolean(VirtualMachine *);
    static void loadGlobal(VirtualMachine *);
;public:
    explicit Executor();
    void execute(VirtualMachine*, const Bytecode* operation) const;
};

#endif //VIRTUAL_MACHINE_EXECUTOR_HPP