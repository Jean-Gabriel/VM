#include "object_declaration.hpp"

uint16_t calculateAttributeOffsetOf(ObjectDeclaration object, uint8_t attributeIndex) {
    uint16_t attributeOffset = 1;

    for(size_t i = 0; i<attributeIndex;i++) {
        attributeOffset += sizeOf(object.declarablesType.at(i));
    }

    return attributeOffset;
}