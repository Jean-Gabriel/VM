#include <gtest/gtest.h>
#include "../src/vm/type.hpp"

TEST(GivenANumber, ItShouldAssembleANumberTypeObject) {
    float givenNumber = 42;

    Type assembledNumber = numberFrom(givenNumber);

    ASSERT_EQ(assembledNumber.number_value, givenNumber);
}

TEST(GivenABoolean, ItShouldAssembleABooleanTypeObject) {
    bool givenBoolean = true;

    Type assembledBoolean = booleanFrom(givenBoolean);

    ASSERT_EQ(assembledBoolean.boolean_value, givenBoolean);
}