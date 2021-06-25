#include "person_credit.h"

PersonCredit::PersonCredit(Person person, Date date, dec::decimal<2> amount, float interest, int months)
    : person_(person), date_(date), amount_(amount), interest_(interest), months_(months) {}

Person PersonCredit::get_person() {
    return person_;
}

void PersonCredit::set_person(Person person) {
    person_ = person;
}

Date PersonCredit::get_date() {
    return date_;
}

void PersonCredit::set_date(Date date) {
    date_ = date;
}

float PersonCredit::get_interest() {
    return interest_;
}

void PersonCredit::set_interest(float interest) {
    interest_ = interest;
}

dec::decimal<2> PersonCredit::get_amount() {
    return amount_;
}

void PersonCredit::set_amount(dec::decimal<2> amount) {
    amount_ = amount;
}

int PersonCredit::get_months() {
    return months_;
}

void PersonCredit::set_months(int months) {
    months_ = months;
}
