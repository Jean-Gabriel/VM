#ifndef VIRTUAL_MACHINE_VALUE_HPP
#define VIRTUAL_MACHINE_VALUE_HPP

#include <iostream>
#include "memory/object.hpp"

enum ValueType {
    NUMBER,
    BOOLEAN,
    OBJECT,
    NIL,
};

union NumberValue {
    uint8_t bytes[4];
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

std::vector<uint8_t> bytesFrom(Value value);
Value valueFrom(std::vector<uint8_t> bytes, ValueType type);

#endif //VIRTUAL_MACHINE_VALUE_HPP
