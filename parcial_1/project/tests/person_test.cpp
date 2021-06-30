#include <gtest/gtest.h>
#include "../include/person.h"
#include "../src/person.cpp"

// check person attributes
TEST(PersonTest, FieldsPerson) {
    Person person_a;

    person_a.id("1726744293");
    person_a.firstname("john doe");

    EXPECT_EQ(person_a.id(), "1726744293");
    EXPECT_EQ(person_a.firstname(), "john doe");
}
