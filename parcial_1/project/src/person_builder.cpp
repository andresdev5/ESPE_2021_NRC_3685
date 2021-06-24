#include "person_builder.h"

PersonBuilder &PersonBuilder::id(string const &id) {
    fields_["id"] = id;
    return *this;
}

PersonBuilder &PersonBuilder::firstname(string const &firstname) {
    fields_["firstname"] = firstname;
    return *this;
}

PersonBuilder &PersonBuilder::lastname(string const &lastname) {
    fields_["lastname"] = lastname;
    return *this;
}

PersonBuilder &PersonBuilder::address(string const &address) {
    fields_["address"] = address;
    return *this;
}

PersonBuilder &PersonBuilder::phone(string const &phone) {
    fields_["phone"] = phone;
    return *this;
}

PersonBuilder &PersonBuilder::email(string const &email) {
    fields_["email"] = email;
    return *this;
}

PersonBuilder &PersonBuilder::automatic_email(string const &domain) {
    fields_["email_domain"] = domain;
    generate_email_ = true;
    return *this;
}

Person PersonBuilder::build() {
    Person person;

    if (generate_email_) {
        fields_["email"] = "generated";
    }

    person.id(fields_["id"]);
    person.firstname(fields_["firstname"]);
    person.lastname(fields_["lastname"]);
    person.address(fields_["address"]);
    person.phone(fields_["phone"]);
    person.email(fields_["email"]);

    reset();

    return person;
}

void PersonBuilder::reset() {
    fields_.clear();
    generate_email_ = false;
}
