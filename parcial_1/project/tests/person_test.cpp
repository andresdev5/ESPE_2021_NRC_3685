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

TEST(PersonTest, PersonConstructor) {
    Person person("1726744293", "John", "Doe", "Quito", "0998598514", "jhondoe@espe.edu.ec");

    EXPECT_EQ(person.id(), "1726744293");
    EXPECT_EQ(person.firstname(), "John");
    EXPECT_EQ(person.lastname(), "Doe");
    EXPECT_EQ(person.address(), "Quito");
    EXPECT_EQ(person.phone(), "0998598514");
    EXPECT_EQ(person.email(), "jhondoe@espe.edu.ec");
}
