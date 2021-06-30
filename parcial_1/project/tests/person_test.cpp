#include <gtest/gtest.h>
#include "../include/person.h"
#include "../src/person.cpp"
#include "../include/linked_list.h"
#include "../include/utils.h"

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

TEST(PersonTest, UniqueEmailCheck) {
    Person person_a("1726744293", "Jhon", "Doe", "Quito", "593998598514", "");
    Person person_b("1727620054", "Jerry", "Doe", "Coshapamba", "593959660968", "");

    LinkedList<Person> persons;

    std::string email = generateUniqueEmail(persons, person_a, "espe.edu.ec");
    person_a.email(email);
    persons.push_back(person_a);

    
    email = generateUniqueEmail(persons, person_b, "espe.edu.ec");
    person_b.email(email);
    persons.push_back(person_b);

    EXPECT_NE(person_a.email(), person_b.email());
}
