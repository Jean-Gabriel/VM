#include <vector>
#include "executor.hpp"
#include "virtual_machine.hpp"

void Executor::loadString(VirtualMachine *vm) {
    std::vector<uint8_t> stringValues;
    Bytecode byte = vm->advanceInstruction();

    while (byte != 0) {
        stringValues.push_back(byte);
        byte = vm->advanceInstruction();
    }

    Pointer startingPoint = vm->memory.allocate(stringValues);
    vm->stack.push(stringWith(startingPoint, stringValues.size()));
}

void Executor::appendString(VirtualMachine *vm) {
    Type memoryInformationOfFirst = vm->stack.top();
    vm->stack.pop();
    Type memoryInformationOfSecond = vm->stack.top();
    vm->stack.pop();

    std::string stringToAppend = vm->memory.stringFrom(memoryInformationOfFirst.string);
    std::string destinationString = vm->memory.stringFrom(memoryInformationOfSecond.string);
    std::string result = destinationString.append(stringToAppend);

    vm->memory.freeAt(memoryInformationOfFirst.string.startingPoint, memoryInformationOfFirst.string.length);
    vm->memory.freeAt(memoryInformationOfSecond.string.startingPoint, memoryInformationOfSecond.string.length);

    Pointer resultStartingPoint = vm->memory.allocate(std::vector<uint8_t>(result.begin(),result.end()));
    vm->stack.push(stringWith(resultStartingPoint, result.size()));
}

void Executor::substringAt(VirtualMachine *vm) {
    Bytecode indexToSubstring = vm->advanceInstruction();
    Type memoryInformation = vm->stack.top();
    vm->stack.pop();

    std::string stringToPortion = vm->memory.stringFrom(memoryInformation.string);
    std::string substring = stringToPortion.substr(indexToSubstring);

    vm->memory.freeAt(memoryInformation.string.startingPoint, memoryInformation.string.length);

    Pointer substringStartingPointer = vm->memory.allocate(std::vector<uint8_t>(substring.begin(), substring.end()));
    vm->stack.push(stringWith(substringStartingPointer, substring.size()));
}

void Executor::substringWithLength(VirtualMachine *vm) {
    Bytecode indexToSubstring = vm->advanceInstruction();
    Bytecode sizeOfSubstring = vm->advanceInstruction();
    Type memoryInformation = vm->stack.top();
    vm->stack.pop();

    std::string stringToPortion = vm->memory.stringFrom(memoryInformation.string);
    std::string substring = stringToPortion.substr(indexToSubstring, sizeOfSubstring);

    vm->memory.freeAt(memoryInformation.string.startingPoint, memoryInformation.string.length);

    Pointer substringStartingPointer = vm->memory.allocate(std::vector<uint8_t>(substring.begin(), substring.end()));
    vm->stack.push(stringWith(substringStartingPointer, substring.size()));
}

void Executor::printString(VirtualMachine *vm) {
    Type memoryInformation = vm->stack.top();
    vm->stack.top();

    std::string assembledStringToPrint = vm->memory.stringFrom(memoryInformation.string);

    std::cout << assembledStringToPrint << std::endl;
    vm->memory.freeAt(memoryInformation.string.startingPoint, memoryInformation.string.length);
}