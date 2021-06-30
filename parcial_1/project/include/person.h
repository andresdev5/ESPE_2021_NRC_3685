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

    Person(
        std::string id, std::string firstname, std::string lastname, std::string address, std::string phone, std::string email);

    void id(std::string const &id);

    /**
     * @brief cedula de identidad
     * @param id
     */
    std::string const &id() const;

    void firstname(std::string const &firstname);

    /**
     * @brief nombre de la persona
     * @return 
    */
    std::string const &firstname() const;

    void lastname(std::string const &lastname);

    /**
     * @brief apellido de la persona
     * @return 
    */
    std::string const &lastname() const;

    void address(std::string const &address);

    /**
     * @brief direccion de la persona
     * @return 
    */
    std::string const &address() const;

    void phone(std::string const &phone);

    /**
     * @brief telefono de la persona
     * @return 
    */
    std::string const &phone() const;

    void email(std::string const &email);

    /**
     * @brief email de la persona
     * @return 
    */
    std::string const& email() const;

private:
    std::string id_;
    std::string firstname_;
    std::string lastname_;
    std::string address_;
    std::string phone_;
    std::string email_;
};
