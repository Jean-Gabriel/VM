#include "type.hpp"

Type numberFrom(float value) {
    Type type{};
    type.number_value = value;
    return type;
}

Type booleanFrom(bool value) {
    Type type{};
    type.boolean_value = value;
    return type;
}

Type stringWith(Pointer offset, uint8_t length) {
    Type type{};

    type.string.length = length;
    type.string.startingPoint = offset;

    return type;
}
