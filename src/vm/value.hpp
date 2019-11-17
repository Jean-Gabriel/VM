#ifndef VIRTUAL_MACHINE_VALUE_HPP
#define VIRTUAL_MACHINE_VALUE_HPP

#include <iostream>
#include "object/object.hpp"

enum ValueType {
    NIL = 0,
    NUMBER = 1,
    BOOLEAN = 2,
    OBJECT = 3
};

union NumberValue {
    uint16_t bytes[4];
    float number;
};

struct Value {
    uint8_t type;
    union Content {
        bool booleanValue;
        float numberValue;
        Object objectValue;
    } content;
};

Value numberValueFrom(float number);
Value booleanValueFrom(bool boolean);
Value objectValueFrom(uint16_t statingPoint, uint8_t length);

std::vector<uint16_t> initialBytesOf(ValueType);
std::vector<uint16_t> bytesFrom(Value value);
Value valueFrom(std::vector<uint16_t> bytes, ValueType type);

uint16_t sizeOf(ValueType);

#endif //VIRTUAL_MACHINE_VALUE_HPP
