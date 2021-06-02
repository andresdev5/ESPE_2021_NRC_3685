#include "user.h"

User::User(std::string identify_card, std::string name, int age) {
    this->identify_card = identify_card;
    this->name = name;
    this->age = age;
}

bool User::operator ==(User &user) {
    return identify_card == user.get_identify_card();
}

bool User::operator !=(User &user) {
    return identify_card != user.get_identify_card();
}

bool User::operator >(User &user) {
    return age > user.get_age();
}

bool User::operator <(User &user) {
    return age < user.get_age();
}

std::string User::get_identify_card() {
    return identify_card;
}

void User::set_identify_card(std::string identify_card) {
    this->identify_card = identify_card;
}

std::string User::get_name() {
    return name;
}

void User::set_name(std::string name) {
    this->name = name;
}

int User::get_age() {
    return age;
}

void User::set_age(int age) {
    this->age = age;
}
