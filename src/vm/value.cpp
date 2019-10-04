#include "value.hpp"

Value numberFrom(float numberValue) {
    Value value{};
    value.numberValue = numberValue;
    return value;
}

Value booleanFrom(bool booleanValue) {
    Value type{};
    type.booleanValue = booleanValue;
    return type;
}

Value stringInformationWith(Pointer startingPoint, uint8_t length) {
    Value value{};

    value.stringInformation.length = length;
    value.stringInformation.startingPoint = startingPoint;

    return value;
}
