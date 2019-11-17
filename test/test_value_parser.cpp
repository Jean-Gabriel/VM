#include <gtest/gtest.h>
#include "../src/vm/value.hpp"

TEST(GivenANumber, ItShouldAssembleANumberValueObject) {
    float givenNumber = 42;

    Value assembledValue = numberValueFrom(givenNumber);

    ASSERT_EQ(assembledValue.content.numberValue, givenNumber);
}

TEST(GivenABoolean, ItShouldAssembleABooleanValueObject) {
    bool givenBoolean = true;

    Value assembledValue = booleanValueFrom(givenBoolean);

    ASSERT_EQ(assembledValue.content.booleanValue, givenBoolean);
}

TEST(GivenAStringSizeAndLength, ItShouldAssembleAStringInformationValueObject) {
    uint16_t startingPoint = 1;
    uint8_t size = 2;

    Value assembledValue = objectValueFrom(startingPoint, size);

    ASSERT_EQ(assembledValue.content.objectValue.startingPoint, 1);
    ASSERT_EQ(assembledValue.content.objectValue.length, 2);
}

TEST(GivenABooleanValue, ItShouldGiveBytesOfGivenBoolean) {
    Value assembledBoolean = booleanValueFrom(true);

    const auto bytes = bytesFrom(assembledBoolean);

    ASSERT_EQ(bytes.at(0), 1);
    ASSERT_EQ(bytes.size(), 1);
    ASSERT_EQ(valueFrom(bytes, BOOLEAN).content.booleanValue, true);
}

TEST(GivenANumberValue, ItShouldGiveBytesOfGivenNumber) {
    Value assembledNumber = numberValueFrom(152);

    const auto bytes = bytesFrom(assembledNumber);

    ASSERT_EQ(bytes.size(), 4);
    ASSERT_EQ(valueFrom(bytes, NUMBER).content.numberValue, 152);
}

TEST(GivenAValue, ItShouldGiveItsSize) {
    Value number = numberValueFrom(12);
    Value boolean = booleanValueFrom(true);
    Value object = objectValueFrom(10, 2);

    ASSERT_EQ(sizeOf((ValueType)number.type), 4);
    ASSERT_EQ(sizeOf((ValueType)boolean.type), 1);
    ASSERT_EQ(sizeOf((ValueType)object.type), 2);
}