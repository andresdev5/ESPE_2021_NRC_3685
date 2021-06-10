#include "person.h"

Person::Person(std::string identify_card, std::string name) {
    this->identify_card = identify_card;
    this->name = name;
}

void Person::add_payment_date(Date payment_date) {
    payment_dates.push_back(payment_date);
}

std::string Person::get_identify_card() {
    return identify_card;
}

void Person::set_identify_card(std::string identify_card) {
    this->identify_card = identify_card;
}

std::string Person::get_name() {
    return name;
}

void Person::set_name(std::string name) {
    this->name = name;
}

std::vector<Date> Person::get_payment_dates() {
    return payment_dates;
}

void Person::set_payment_dates(std::vector<Date> payment_dates) {
    this->payment_dates.clear();

    for (Date payment_date : payment_dates) {
        this->payment_dates.push_back(payment_date);
    }
}
