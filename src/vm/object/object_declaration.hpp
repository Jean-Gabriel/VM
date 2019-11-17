#ifndef VIRTUAL_MACHINE_OBJECT_DECLARATION_HPP
#define VIRTUAL_MACHINE_OBJECT_DECLARATION_HPP

#include <map>
#include "../value.hpp"

struct ObjectDeclaration {
    std::map<uint8_t, ValueType> declarablesType;
};

uint16_t calculateAttributeOffsetOf(ObjectDeclaration object, uint8_t attributeIndex);


#endif //VIRTUAL_MACHINE_OBJECT_DECLARATION_HPP
