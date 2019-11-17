#include <cmath>
#include "executor.hpp"
#include "virtual_machine.hpp"

void Executor::loadNumber(VirtualMachine *vm) {
    Value number = numberValueFrom(static_cast<float>(vm->advanceInstruction()));

    vm->stack.push(number);
}

void Executor::addNumber(VirtualMachine *vm) {
    Value::Content firstNumber = vm->stack.top().content;
    vm->stack.pop();

    Value::Content secondNumber = vm->stack.top().content;
    vm->stack.pop();

    vm->stack.push(numberValueFrom(firstNumber.numberValue + secondNumber.numberValue));
}

void Executor::multiplyNumber(VirtualMachine *vm) {
    Value::Content firstNumber = vm->stack.top().content;
    vm->stack.pop();

    Value::Content secondNumber = vm->stack.top().content;
    vm->stack.pop();

    vm->stack.push(numberValueFrom(firstNumber.numberValue * secondNumber.numberValue));
}

void Executor::divideNumber(VirtualMachine *vm){
    const Value::Content firstNumber = vm->stack.top().content;
    vm->stack.pop();

    const Value::Content secondNumber = vm->stack.top().content;
    vm->stack.pop();

    vm->stack.push(numberValueFrom(firstNumber.numberValue / secondNumber.numberValue));
}

void Executor::subtractNumber(VirtualMachine *vm){
    const Value::Content firstNumber = vm->stack.top().content;
    vm->stack.pop();

    const Value::Content secondNumber = vm->stack.top().content;
    vm->stack.pop();

    vm->stack.push(numberValueFrom(firstNumber.numberValue - secondNumber.numberValue));
}

void Executor::modNumber(VirtualMachine *vm){
    const Value::Content firstNumber = vm->stack.top().content;
    vm->stack.pop();

    const Value::Content secondNumber = vm->stack.top().content;
    vm->stack.pop();

    vm->stack.push(numberValueFrom(static_cast<float>(std::fmod(firstNumber.numberValue, secondNumber.numberValue))));
}

void Executor::powNumber(VirtualMachine *vm){
    const Value::Content firstNumber = vm->stack.top().content;
    vm->stack.pop();

    const Value::Content secondNumber = vm->stack.top().content;
    vm->stack.pop();

    vm->stack.push(numberValueFrom(powf(firstNumber.numberValue, secondNumber.numberValue)));
}

void Executor::equalNumber(VirtualMachine *vm){
    const Value::Content firstNumber = vm->stack.top().content;
    vm->stack.pop();

    const Value::Content secondNumber = vm->stack.top().content;
    vm->stack.pop();

    vm->stack.push(booleanValueFrom(firstNumber.numberValue == secondNumber.numberValue));
}

void Executor::greaterThanNumber(VirtualMachine *vm){
    const Value::Content firstNumber = vm->stack.top().content;
    vm->stack.pop();

    const Value::Content secondNumber = vm->stack.top().content;
    vm->stack.pop();

    vm->stack.push(booleanValueFrom(firstNumber.numberValue > secondNumber.numberValue));
}

void Executor::greaterEqualThanNumber(VirtualMachine *vm){
    const Value::Content firstNumber = vm->stack.top().content;
    vm->stack.pop();

    const Value::Content secondNumber = vm->stack.top().content;
    vm->stack.pop();

    vm->stack.push(booleanValueFrom(firstNumber.numberValue >= secondNumber.numberValue));
}

void Executor::printNumber(VirtualMachine *vm) {
    const Value::Content number = vm->stack.top().content;
    vm->stack.pop();

    std::cout << number.numberValue << std::endl;
}
