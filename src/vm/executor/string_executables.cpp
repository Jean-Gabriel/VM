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
    vm->stack.push(stringInformationWith(startingPoint, stringValues.size()));
}

void Executor::appendString(VirtualMachine *vm) {
    Value firstValue = vm->stack.top();
    vm->stack.pop();
    Value secondValue = vm->stack.top();
    vm->stack.pop();

    std::string stringToAppend = vm->memory.stringFrom(firstValue.stringInformation);
    std::string destinationString = vm->memory.stringFrom(secondValue.stringInformation);
    std::string result = destinationString.append(stringToAppend);

    vm->memory.freeAt(firstValue.stringInformation.startingPoint, firstValue.stringInformation.length);
    vm->memory.freeAt(secondValue.stringInformation.startingPoint, secondValue.stringInformation.length);

    Pointer resultStartingPoint = vm->memory.allocate(std::vector<uint8_t>(result.begin(),result.end()));
    vm->stack.push(stringInformationWith(resultStartingPoint, result.size()));
}

void Executor::substringAt(VirtualMachine *vm) {
    Bytecode indexToSubstring = vm->advanceInstruction();
    Value value = vm->stack.top();
    vm->stack.pop();

    std::string stringToPortion = vm->memory.stringFrom(value.stringInformation);
    std::string substring = stringToPortion.substr(indexToSubstring);

    vm->memory.freeAt(value.stringInformation.startingPoint, value.stringInformation.length);

    Pointer substringStartingPointer = vm->memory.allocate(std::vector<uint8_t>(substring.begin(), substring.end()));
    vm->stack.push(stringInformationWith(substringStartingPointer, substring.size()));
}

void Executor::substringWithLength(VirtualMachine *vm) {
    Bytecode indexToSubstring = vm->advanceInstruction();
    Bytecode sizeOfSubstring = vm->advanceInstruction();
    Value value = vm->stack.top();
    vm->stack.pop();

    std::string stringToPortion = vm->memory.stringFrom(value.stringInformation);
    std::string substring = stringToPortion.substr(indexToSubstring, sizeOfSubstring);

    vm->memory.freeAt(value.stringInformation.startingPoint, value.stringInformation.length);

    Pointer substringStartingPointer = vm->memory.allocate(std::vector<uint8_t>(substring.begin(), substring.end()));
    vm->stack.push(stringInformationWith(substringStartingPointer, substring.size()));
}

void Executor::printString(VirtualMachine *vm) {
    Value value = vm->stack.top();
    vm->stack.top();

    std::string assembledStringToPrint = vm->memory.stringFrom(value.stringInformation);

    std::cout << assembledStringToPrint << std::endl;
    vm->memory.freeAt(value.stringInformation.startingPoint, value.stringInformation.length);
}