#include "../include/date.h"
#include <exception>
#include <stdexcept>

void check_holiday() {
    Date date(25, 12, 2021);
    bool result = date.is_holiday();

    if (result != true) {
        throw std::runtime_error("25/12/2021 expected to be a holiday");
    }
}

int main() {
    check_holiday();
}
