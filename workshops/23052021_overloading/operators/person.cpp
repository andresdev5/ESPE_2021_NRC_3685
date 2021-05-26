#include "person.h"

////////////////////////////// Sobrecarga Operadores ///////////////////////////////////
Person::Person(std::string name, std::string last_name_1, std::string last_name_2) {
    this->name = name;
    this->last_name_one = last_name_1;
    this->last_name_two = last_name_2; 
}

std::string Person::operator &(Person &person) {
    return last_name_one;
}

std::string Person::operator &&(Person &person) {
    return last_name_two;
}

std::string Person::operator &=(Person &person) {
    return last_name_one + " " + last_name_two;
}

///////////////////////////// Getters and setters ///////////////////////////////////////////
std::string Person::get_last_name_1() {
    return last_name_one;
}

void Person::set_last_name_1(std::string last_name_1) {
    this->last_name_one = last_name_1;
}

std::string Person::get_last_name_2() {
    return last_name_two;
}

void Person::set_last_name_2(std::string last_name_2) {
    this->last_name_two = last_name_2;
}

std::string Person::get_name() {
    return name;
}

void Person::set_name(std::string name) {
    this->name = name;
}
