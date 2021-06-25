#pragma once
#include <string>

struct PersonPojo {
    std::string id;
    std::string firstname;
    std::string lastname;
    std::string address;
    std::string phone;
    std::string email;
};

class Person {
public:
    Person();

    explicit Person(
        std::string id, std::string firstname, std::string lastname, std::string address, std::string phone, std::string email);

    void id(std::string const &id);
    std::string const &id() const;

    void firstname(std::string const &firstname);
    std::string const &firstname() const;

    void lastname(std::string const &lastname);
    std::string const &lastname() const;

    void address(std::string const &address);
    std::string const &address() const;

    void phone(std::string const &phone);
    std::string const &phone() const;

    void email(std::string const &email);
    std::string const& email() const;

private:
    std::string id_;
    std::string firstname_;
    std::string lastname_;
    std::string address_;
    std::string phone_;
    std::string email_;
};
