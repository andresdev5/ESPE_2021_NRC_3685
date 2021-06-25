#pragma once
#include <decimal/decimal.h>
#include "utils.h"
#include "date.h"
#include "person.h"
#include "linked_list.h"

class PersonCredit {
public:
    PersonCredit(Person person, Date date, dec::decimal<2> amount, float interest);
    Person get_person();
    void set_person(Person person);
    Date get_date();
    void set_date(Date date);
    float get_interest();
    void set_interest(float interest);
    dec::decimal<2> get_amount();
    void set_amount(dec::decimal<2> interest);

private:
    Person person_;
    Date date_;
    dec::decimal<2> amount_;
    float interest_;
};
