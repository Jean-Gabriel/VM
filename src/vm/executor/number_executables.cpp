#include <cmath>
#include "executor.hpp"
#include "virtual_machine.hpp"

void Executor::loadNumber(VirtualMachine *vm) {
    Type number = numberFrom(static_cast<float>(vm->advanceInstruction()));

    vm->stack.push(number);
}

void Executor::addNumber(VirtualMachine *vm) {
    Type firstNumber = vm->stack.top();
    vm->stack.pop();

    Type secondNumber = vm->stack.top();
    vm->stack.pop();

    vm->stack.push(numberFrom(firstNumber.number_value + secondNumber.number_value));
}

void Executor::multiplyNumber(VirtualMachine *vm) {
    Type firstNumber = vm->stack.top();
    vm->stack.pop();

    Type secondNumber = vm->stack.top();
    vm->stack.pop();

    vm->stack.push(numberFrom(firstNumber.number_value * secondNumber.number_value));
}

void Executor::divideNumber(VirtualMachine *vm){
    Type firstNumber = vm->stack.top();
    vm->stack.pop();

    Type secondNumber = vm->stack.top();
    vm->stack.pop();

    vm->stack.push(numberFrom(firstNumber.number_value / secondNumber.number_value));
}

void Executor::subtractNumber(VirtualMachine *vm){
    Type firstNumber = vm->stack.top();
    vm->stack.pop();

    Type secondNumber = vm->stack.top();
    vm->stack.pop();

    vm->stack.push(numberFrom(firstNumber.number_value - secondNumber.number_value));
}

void Executor::modNumber(VirtualMachine *vm){
    Type firstNumber = vm->stack.top();
    vm->stack.pop();

    Type secondNumber = vm->stack.top();
    vm->stack.pop();

    vm->stack.push(numberFrom(static_cast<float>(std::fmod(firstNumber.number_value, secondNumber.number_value))));
}

void Executor::equalNumber(VirtualMachine *vm){
    Type firstNumber = vm->stack.top();
    vm->stack.pop();

    Type secondNumber = vm->stack.top();
    vm->stack.pop();

    vm->stack.push(boolFrom(firstNumber.number_value == secondNumber.number_value));
}

void Executor::greaterThanNumber(VirtualMachine *vm){
    Type firstNumber = vm->stack.top();
    vm->stack.pop();

    Type secondNumber = vm->stack.top();
    vm->stack.pop();

    vm->stack.push(boolFrom(firstNumber.number_value > secondNumber.number_value));
}

void Executor::greaterEqualThanNumber(VirtualMachine *vm){
    Type firstNumber = vm->stack.top();
    vm->stack.pop();

    Type secondNumber = vm->stack.top();
    vm->stack.pop();

    vm->stack.push(boolFrom(firstNumber.number_value >= secondNumber.number_value));
}

void Executor::printNumber(VirtualMachine *vm) {
    const Type number = vm->stack.top();
    vm->stack.pop();

    std::cout << number.number_value << std::endl;
}