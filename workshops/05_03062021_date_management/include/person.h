#pragma once
#include "date.h"
#include <string>
#include <vector>

class Person {
public:
    Person(std::string identiy_card, std::string name);

    void set_identify_card (std::string set_identify_card);
    std::string get_identify_card();

    void set_name (std:: string name);
    std::string get_name ();

    void set_payment_dates (std::vector <Date> payment_dates);
    std::vector <Date> payment_dates ();

private:
    std::string identify_card;
    std::string name;
    std::vector<Date> payment_dates;
};
