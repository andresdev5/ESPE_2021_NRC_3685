#include "date.h"
#include <date/date.h>
#include <iostream>
#include <regex>
#include <limits>

Date::Date() {
    Date current = Date::current();

    day = current.get_day();
    month = current.get_month();
    year = current.get_year();
}

Date::Date(int day, int month, int year) {
    this->day = day;
    this->month = month;
    this->year = year;
}

std::chrono::system_clock::time_point Date::system_now() {
    auto now = std::chrono::system_clock::now();
    auto since_epoch = now.time_since_epoch();
    since_epoch -= std::chrono::hours{5};  // GMT-5 bogota/Lima/Quito

    std::chrono::system_clock::time_point utc_now{since_epoch};

    return utc_now;
}

Date Date::current() {
    auto now = Date::system_now();
    auto dp = date::floor<date::days>(now);
    date::year_month_day ymd{dp};

    int day = unsigned(ymd.day());
    int month = unsigned(ymd.month());
    int year = int(ymd.year());

    return Date(day, month, year);
}

Date Date::read(std::string label) {
    Date current_date = Date::current();
    bool valid;
    int month;
    int day;
    int year;

    do {
        valid = true;
        std::string date_str;

        std::cout << (label.empty() ? "Ingrese una fecha (dd/MM/YYY): " : label);
        std::cin >> date_str;

        std::regex pattern("^(0?[1-9]|[12][0-9]|3[01])[\\/\\-](0?[1-9]|1[012])[\\/\\-](\\d{4})$");
        std::smatch matches;

        if (!std::regex_match(date_str, matches, pattern)) {
            std::cout << std::endl << "[Formato incorrecto, intenta: (dd/mm/yyyy)]" << std::endl;
            valid = false;
        } else {
            day = std::stoi(matches[1]);
            month = std::stoi(matches[2]);
            year = std::stoi(matches[3]);

            if (day < 1 || day > 31) {
                std::cout << std::endl << "[dia incorrecto]" << std::endl;
                valid = false;
            } else if (month < 1 || month > 12) {
                std::cout << std::endl << "[mes incorrecto]" << std::endl;
                valid = false;
            } else if (year < 1990) {
                std::cout << std::endl << "[Año incorrecto]" << std::endl;
                valid = false;
            }

            if (!Date::is_valid(day, month, year)) {
                std::cout << std::endl << "[Fecha incorrecta]" << std::endl;
                valid = false;
            }
        }

        if (!valid) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    } while (!valid);

    return Date(day, month, year);
}

bool Date::is_valid(int day, int month, int year) {
    if (day < 1 || day > 31) {
        return false;
    } else if (month < 1 || month > 12) {
        return false;
    }

    if ((month == 4 || month == 6 || month == 9 || month == 11) && day == 31) {
        return false;
    } else if ((month == 2) && (year % 4 == 0) && day > 29) {
        return false;

    } else if ((month == 2) && (year % 4 != 0) && day > 28) {
        return false;
    }

    return true;
}

std::chrono::system_clock::time_point Date::to_time_point() {
    std::tm tm = {
        0,
        0,
        0,
        day,
        month - 1,
        year - 1900,
    };
    tm.tm_isdst = -1;

    auto utc_date = std::chrono::system_clock::from_time_t(std::mktime(&tm));
    auto since_epoch = utc_date.time_since_epoch();
    since_epoch -= std::chrono::hours{5};  // GMT-5 bogota/Lima/Quito

    std::chrono::system_clock::time_point utc_now{since_epoch};

    return utc_now;
}

Day Date::get_weekday() {
    auto dp = date::floor<date::days>(to_time_point());
    date::weekday weekday{dp};
    return static_cast<Day>(weekday.iso_encoding());
}

void Date::update(std::chrono::system_clock::time_point time_point) {
    auto dp = date::floor<date::days>(time_point);
    date::year_month_day ymd{dp};

    day = unsigned(ymd.day());
    month = unsigned(ymd.month());
    year = int(ymd.year());
}

void Date::add_days(int days) {
    int hours = days / 86400;
    auto time_point = to_time_point();
    auto date = date::floor<date::days>(time_point);

    date::year_month_day future = date + date::days{days};

    update(date::sys_days{future});
}

int Date::last_month_day() {
    auto time_point = to_time_point();
    auto date = date::floor<date::days>(time_point);
    date::year_month_day ymd{date};
    date::year_month_day_last last_day{ymd.year(), date::month_day_last{ymd.month()}};

    return unsigned(last_day.day());
}

bool Date::is_holiday() {
    std::vector<std::pair<int, int>> holidays = {std::make_pair(1, 1), std::make_pair(1, 2), std::make_pair(5, 1),
        std::make_pair(5, 24), std::make_pair(7, 25), std::make_pair(8, 10), std::make_pair(10, 9),
        std::make_pair(11, 2), std::make_pair(11, 3), std::make_pair(12, 25), std::make_pair(12, 31)};

    bool is_holiday = false;

    for (std::pair<int, int> holiday : holidays) {
        if (holiday.first == get_month() && holiday.second == get_day()) {
            is_holiday = true;
            break;
        }
    }

    return is_holiday;
}

int Date::get_day() {
    return day;
}

int Date::get_month() {
    return month;
}

int Date::get_year() {
    return year;
}
