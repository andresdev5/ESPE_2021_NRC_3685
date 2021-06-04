#pragma once
#include "date.h"
#include <string>
#include <vector>

class Person {
public:
    Person(std::string identiy_card, std::string name);

private:
    std::string identify_card;
    std::string name;
    std::vector<Date> payment_dates;
};
