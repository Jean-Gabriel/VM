#ifndef VIRTUAL_MACHINE_EXECUTOR_HPP
#define VIRTUAL_MACHINE_EXECUTOR_HPP

#include <map>
#include <cstdint>

#include "../opcodes.hpp"

struct FunctionDeclaration;
class VirtualMachine;

class Executor {
private:
    std::map<uint8_t,void (*)(VirtualMachine*)> executables;

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

    static void loadString(VirtualMachine*);
    static void appendString(VirtualMachine*);
    static void substringAt(VirtualMachine*);
    static void substringWithLength(VirtualMachine*);
    static void printString(VirtualMachine*);

    static void jumpIfTrue(VirtualMachine*);
    static void jumpIfFalse(VirtualMachine*);
    static void jump(VirtualMachine*);

    static void storeGlobal(VirtualMachine*);
    static void loadGlobal(VirtualMachine*);

    static void storeLocal(VirtualMachine*);
    static void loadLocal(VirtualMachine*);

    static void declareFunction(VirtualMachine*);
    static void callFunction(VirtualMachine*);
    static void loadArgumentsFor(FunctionDeclaration, VirtualMachine*);
    static void doReturn(VirtualMachine*);

    static void declareObject(VirtualMachine*);
    static void declareObjectAttribute(VirtualMachine*);
    static void deleteObject(VirtualMachine*);
    static void storeAttribute(VirtualMachine*);
    static void loadAttribute(VirtualMachine*);
    static void loadObject(VirtualMachine*);
public:
    explicit Executor();
    void execute(VirtualMachine*, const uint8_t *operation) const;
};

#endif //VIRTUAL_MACHINE_EXECUTOR_HPP