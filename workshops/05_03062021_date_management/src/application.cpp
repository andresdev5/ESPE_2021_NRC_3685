#include "application.h"
#include "date.h"
#include <iostream>
#include <limits>
#include <vector>
#include <utility>

Application::Application() {}

void Application::run() {
    Date date;
    Day day = date.get_weekday();

    do {
        date = Date::read("Ingrese una fecha (dd/mm/yyyy): ");
        Day day = date.get_weekday();

        if (day == Day::Saturday || day == Day::Sunday) {
            std::cout << std::endl << "[Ese dia no es laborable]" << std::endl;
            continue;
        }

        break;
    } while (true);

    int years;

    do {
        std::cout << "ingrese el total de anios: ";
        std::cin >> years;

        if (std::cin.fail() || years < 0) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    } while (years < 1);

    std::cout << std::endl;
    std::cout << "fechas generadas: " << std::endl << std::endl;

    Date previous(date);

    for (int i = 0; i < years * 12; i++) {
        date.add_days(date.last_month_day());

        Date last(date.get_day(), date.get_month(), date.get_year());

        while (last.get_weekday() == Day::Saturday || last.get_weekday() == Day::Sunday || last.is_holiday()) {
            last.add_days(1);
        }

        Date current(last.get_day(), last.get_month(), last.get_year());
        std::cout << last.get_day() << "/" << last.get_month() << "/" << last.get_year() << std::endl;
    }
}
