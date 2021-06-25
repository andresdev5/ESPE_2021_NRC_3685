#pragma once
#include <decimal/decimal.h>
#include "utils.h"
#include "date.h"

class Payment {
public:
    Payment() = default;
    Payment(Date date, dec::decimal<2> capital, dec::decimal<2> interest);

    Date get_date();
    void set_date(Date date);

    dec::decimal<2> get_capital();
    void set_capital(dec::decimal<2> capital);

    dec::decimal<2> get_interest();
    void set_intereste(dec::decimal<2> interest);

private:
    Date date_;
    dec::decimal<2> capital_ = dec::decimal<2>(0);
    dec::decimal<2> interest_ = dec::decimal<2>(0);
};
