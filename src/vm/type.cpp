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