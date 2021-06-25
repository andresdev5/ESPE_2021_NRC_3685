#include "person.h"

Person::Person()
    : id_("__unknown__"),
      firstname_("__unknown__"),
      lastname_("__unknown__"),
      address_("__unknown__"),
      email_("__unknown__") {}

Person::Person(std::string id, std::string firstname, std::string lastname, std::string address, std::string phone, std::string email)
    : id_(id), firstname_(firstname), lastname_(lastname), address_(address), phone_(phone), email_(email) {}

void Person::id(std::string const &id) {
    this->id_ = id;
}

std::string const &Person::id() const {
    return id_;
}

void Person::firstname(std::string const &firstname) {
    this->firstname_ = firstname;
}

std::string const &Person::firstname() const {
    return firstname_;
}

void Person::lastname(std::string const &lastname) {
    this->lastname_ = lastname;
}

std::string const &Person::lastname() const {
    return lastname_;
}

void Person::address(std::string const &address) {
    this->address_ = address;
}

std::string const &Person::address() const {
    return address_;
}

void Person::phone(std::string const &phone) {
    this->phone_ = phone;
}

std::string const &Person::phone() const {
    return phone_;
}

void Person::email(std::string const &email) {
    this->email_ = email;
}

std::string const& Person::email() const {
    return email_;
}
