#include <vector>
#include "executor.hpp"
#include "virtual_machine.hpp"

void Executor::loadString(VirtualMachine *vm) {
    std::vector<uint8_t> stringValues;
    uint8_t byte = vm->advanceInstruction();

    while (byte != 0) {
        stringValues.push_back(byte);
        byte = vm->advanceInstruction();
    }

    uint16_t startingPoint = vm->memory.allocate(stringValues);
    vm->stack.push(objectValueFrom(startingPoint, stringValues.size()));
}

void Executor::appendString(VirtualMachine *vm) {
    Value::Content firstValue = vm->stack.top().content;
    vm->stack.pop();
    Value::Content secondValue = vm->stack.top().content;
    vm->stack.pop();

    std::string stringToAppend = vm->memory.stringFrom(firstValue.objectValue);
    std::string destinationString = vm->memory.stringFrom(secondValue.objectValue);
    std::string result = destinationString.append(stringToAppend);

    vm->memory.freeAt(firstValue.objectValue.startingPoint, firstValue.objectValue.length);
    vm->memory.freeAt(secondValue.objectValue.startingPoint, secondValue.objectValue.length);

    uint16_t resultStartingPoint = vm->memory.allocate(std::vector<uint8_t>(result.begin(),result.end()));
    vm->stack.push(objectValueFrom(resultStartingPoint, result.size()));
}

void Executor::substringAt(VirtualMachine *vm) {
    uint8_t indexToSubstring = vm->advanceInstruction();
    Value::Content value = vm->stack.top().content;
    vm->stack.pop();

    std::string stringToPortion = vm->memory.stringFrom(value.objectValue);
    std::string substring = stringToPortion.substr(indexToSubstring);

    vm->memory.freeAt(value.objectValue.startingPoint, value.objectValue.length);

    int substringStartingPointer = vm->memory.allocate(std::vector<uint8_t>(substring.begin(), substring.end()));
    vm->stack.push(objectValueFrom(substringStartingPointer, substring.size()));
}

void Executor::substringWithLength(VirtualMachine *vm) {
    uint8_t indexToSubstring = vm->advanceInstruction();
    uint8_t sizeOfSubstring = vm->advanceInstruction();
    Value::Content value = vm->stack.top().content;
    vm->stack.pop();

    std::string stringToPortion = vm->memory.stringFrom(value.objectValue);
    std::string substring = stringToPortion.substr(indexToSubstring, sizeOfSubstring);

    vm->memory.freeAt(value.objectValue.startingPoint, value.objectValue.length);

    uint16_t substringStartingPointer = vm->memory.allocate(std::vector<uint8_t>(substring.begin(), substring.end()));
    vm->stack.push(objectValueFrom(substringStartingPointer, substring.size()));
}

void Executor::printString(VirtualMachine *vm) {
    Value::Content value = vm->stack.top().content;
    vm->stack.top();

    std::string assembledStringToPrint = vm->memory.stringFrom(value.objectValue);

    std::cout << assembledStringToPrint << std::endl;
    vm->memory.freeAt(value.objectValue.startingPoint, value.objectValue.length);
}