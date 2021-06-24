#pragma once
#include <string>
#include <map>
#include "person.h"

using namespace std;

class PersonBuilder {
public:
    PersonBuilder() = default;

    PersonBuilder &id(string const &id);
    PersonBuilder &firstname(string const &firstname);
    PersonBuilder &lastname(string const &lastname);
    PersonBuilder &address(string const &address);
    PersonBuilder &phone(string const &phone);
    PersonBuilder &email(string const &email);
    PersonBuilder &automatic_email(string const &domain);

    Person build();

private:
    void reset();

    map<string, string> fields_;
    bool generate_email_ = false;
};
