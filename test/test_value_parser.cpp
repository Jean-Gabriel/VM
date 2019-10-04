#include <gtest/gtest.h>
#include "../src/vm/value.hpp"

TEST(GivenANumber, ItShouldAssembleANumberValueObject) {
    float givenNumber = 42;

    Value assembledValue = numberFrom(givenNumber);

    ASSERT_EQ(assembledValue.numberValue, givenNumber);
}

TEST(GivenABoolean, ItShouldAssembleABooleanValueObject) {
    bool givenBoolean = true;

    Value assembledValue = booleanFrom(givenBoolean);

    ASSERT_EQ(assembledValue.booleanValue, givenBoolean);
}

TEST(GivenAStringSizeAndLength, ItShouldAssembleAStringInformationValueObject) {
    Pointer startingPoint = 1;
    uint8_t size = 2;

    Value assembledValue = stringInformationWith(startingPoint, size);

    ASSERT_EQ(assembledValue.stringInformation.startingPoint, 1);
    ASSERT_EQ(assembledValue.stringInformation.length, 2);
}