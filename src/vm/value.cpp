#include "value.hpp"

Value numberValueFrom(float number) {
    Value numberValue = {.type = NUMBER };

    numberValue.content.numberValue = number;

    return numberValue;
}

Value booleanValueFrom(bool boolean) {
    Value booleanValue = { .type = BOOLEAN };

    booleanValue.content.booleanValue = boolean;

    return booleanValue;
}

Value objectValueFrom(uint16_t statingPoint, uint8_t length) {
    Value objectValue {.type = OBJECT };

    objectValue.content.objectValue.length = length;
    objectValue.content.objectValue.startingPoint = statingPoint;

    return objectValue;
}

std::vector<uint8_t> bytesFrom(Value value) {
    switch(value.type) {
        case BOOLEAN: {
            return { value.content.booleanValue };
        }
        case NUMBER: {
            NumberValue numberValue = { .number = value.content.numberValue };
            return { numberValue.bytes[0], numberValue.bytes[1], numberValue.bytes[2], numberValue.bytes[3] };
        }
        default: {
            break;
        }
    }

    return {};
}

Value valueFrom(std::vector<uint8_t> bytes, ValueType type) {
    switch(type) {
        case BOOLEAN: {
            return booleanValueFrom(bytes.front());
        }
        case NUMBER: {
            NumberValue numberValue { .bytes = { bytes[0], bytes[1], bytes[2], bytes[3] } };
            return numberValueFrom(numberValue.number);
        }
        default:
            break;
    }

    return { .type = NIL };
}
