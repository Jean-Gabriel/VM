#include <cmath>
#include "executor.hpp"
#include "virtual_machine.hpp"

void Executor::loadNumber(VirtualMachine *vm) {
    Value number = numberFrom(static_cast<float>(vm->advanceInstruction()));

    vm->stack.push(number);
}

void Executor::addNumber(VirtualMachine *vm) {
    Value firstNumber = vm->stack.top();
    vm->stack.pop();

    Value secondNumber = vm->stack.top();
    vm->stack.pop();

    vm->stack.push(numberFrom(firstNumber.numberValue + secondNumber.numberValue));
}

void Executor::multiplyNumber(VirtualMachine *vm) {
    Value firstNumber = vm->stack.top();
    vm->stack.pop();

    Value secondNumber = vm->stack.top();
    vm->stack.pop();

    vm->stack.push(numberFrom(firstNumber.numberValue * secondNumber.numberValue));
}

void Executor::divideNumber(VirtualMachine *vm){
    Value firstNumber = vm->stack.top();
    vm->stack.pop();

    Value secondNumber = vm->stack.top();
    vm->stack.pop();

    vm->stack.push(numberFrom(firstNumber.numberValue / secondNumber.numberValue));
}

void Executor::subtractNumber(VirtualMachine *vm){
    Value firstNumber = vm->stack.top();
    vm->stack.pop();

    Value secondNumber = vm->stack.top();
    vm->stack.pop();

    vm->stack.push(numberFrom(firstNumber.numberValue - secondNumber.numberValue));
}

void Executor::modNumber(VirtualMachine *vm){
    Value firstNumber = vm->stack.top();
    vm->stack.pop();

    Value secondNumber = vm->stack.top();
    vm->stack.pop();

    vm->stack.push(numberFrom(static_cast<float>(std::fmod(firstNumber.numberValue, secondNumber.numberValue))));
}

void Executor::powNumber(VirtualMachine *vm){
    Value firstNumber = vm->stack.top();
    vm->stack.pop();

    Value secondNumber = vm->stack.top();
    vm->stack.pop();

    vm->stack.push(numberFrom(powf(firstNumber.numberValue, secondNumber.numberValue)));
}

void Executor::equalNumber(VirtualMachine *vm){
    Value firstNumber = vm->stack.top();
    vm->stack.pop();

    Value secondNumber = vm->stack.top();
    vm->stack.pop();

    vm->stack.push(booleanFrom(firstNumber.numberValue == secondNumber.numberValue));
}

void Executor::greaterThanNumber(VirtualMachine *vm){
    Value firstNumber = vm->stack.top();
    vm->stack.pop();

    Value secondNumber = vm->stack.top();
    vm->stack.pop();

    vm->stack.push(booleanFrom(firstNumber.numberValue > secondNumber.numberValue));
}

void Executor::greaterEqualThanNumber(VirtualMachine *vm){
    Value firstNumber = vm->stack.top();
    vm->stack.pop();

    Value secondNumber = vm->stack.top();
    vm->stack.pop();

    vm->stack.push(booleanFrom(firstNumber.numberValue >= secondNumber.numberValue));
}

void Executor::printNumber(VirtualMachine *vm) {
    const Value number = vm->stack.top();
    vm->stack.pop();

    std::cout << number.numberValue << std::endl;
}
