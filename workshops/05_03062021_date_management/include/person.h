#pragma once
#include "date.h"
#include <string>
#include <vector>

class Person {
public:
    Person(std::string name);

private:
    std::string name;
    std::vector<Date> dates;
};
