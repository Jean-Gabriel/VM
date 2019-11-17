#include "executor.hpp"
#include "virtual_machine.hpp"

void Executor::declareObject(VirtualMachine *vm) {
    uint8_t objectId = vm->advanceInstruction();

    vm->declaredObjects.insert(std::pair<uint8_t, ObjectDeclaration>(objectId, ObjectDeclaration()));
}

void Executor::declareObjectAttribute(VirtualMachine *vm) {
    uint8_t objectId = vm->advanceInstruction();
    uint8_t attributeId = vm->advanceInstruction();
    auto attributeType = static_cast<ValueType>(vm->advanceInstruction());

    vm->declaredObjects.at(objectId).declarablesType.insert(std::pair<uint8_t, ValueType>(attributeId, attributeType));
}

void Executor::storeAttribute(VirtualMachine *vm) {
    Value toStore = vm->stack.top();
    vm->stack.pop();

    Value object = vm->stack.top();
    vm->stack.pop();
    uint8_t attributeIndex = vm->advanceInstruction();

    uint16_t objectId = vm->memory.readAt(object.content.objectValue.startingPoint, 1).front();
    uint16_t attributeOffset = calculateAttributeOffsetOf(vm->declaredObjects.at(objectId), attributeIndex);

    std::vector<uint16_t> toStoreBytes = bytesFrom(toStore);
    vm->memory.updateAt(object.content.objectValue.startingPoint + attributeOffset, toStoreBytes);
}

void Executor::loadAttribute(VirtualMachine *vm) {
    Value object = vm->stack.top();
    vm->stack.pop();

    uint16_t objectId = vm->memory.readAt(object.content.objectValue.startingPoint, 1).front();
    uint8_t attributeIndex = vm->advanceInstruction();
    uint16_t attributeOffset = calculateAttributeOffsetOf(vm->declaredObjects.at(objectId), attributeIndex);
    ValueType attributeType = vm->declaredObjects.at(objectId).declarablesType.at(attributeIndex);

    std::vector<uint16_t> attributeBytes = vm->memory.readAt(object.content.objectValue.startingPoint + attributeOffset, sizeOf(attributeType));
    Value attributeValue = valueFrom(attributeBytes, attributeType);

    vm->stack.push(attributeValue);
}

void Executor::deleteObject(VirtualMachine *vm) {
    Value::Content value = vm->stack.top().content;
    vm->stack.pop();

    vm->memory.freeAt(value.objectValue.startingPoint, value.objectValue.length);
}

void Executor::loadObject(VirtualMachine *vm) {
    uint8_t objectId = vm->advanceInstruction();
    ObjectDeclaration demandedObject = vm->declaredObjects.at(objectId);
    std::vector<uint16_t> objectBytes{objectId};

    for(const auto declarable: demandedObject.declarablesType) {
        for(const auto byte: initialBytesOf(declarable.second)) {
            objectBytes.push_back(byte);
        }
    }

    uint16_t startingPoint = vm->memory.allocate(objectBytes);
    vm->stack.push(objectValueFrom(startingPoint, objectBytes.size()));
}