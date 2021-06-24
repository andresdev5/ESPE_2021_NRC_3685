#include "payment.h"
#include "date/date.h"

Payment::Payment(Date date, dec::decimal<2> capital, dec::decimal<2> interest) {
    date_ = date;
    capital_ = capital;
    interest_ = interest;
}

Date Payment::get_date() {
    return date_;
}

void Payment::set_date(Date date) {
    date_ = date;
}

dec::decimal<2> Payment::get_capital() {
    return capital_;
}

void Payment::set_capital(dec::decimal<2> capital) {
    capital_ = capital;
}

dec::decimal<2> Payment::get_interest() {
    return interest_;
}

void Payment::set_intereste(dec::decimal<2> interest) {
    interest_ = interest;
}
