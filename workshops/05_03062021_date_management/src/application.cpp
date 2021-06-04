#include "application.h"
#include "date.h"
#include <iostream>

Application::Application() {}

void Application::run() {
    Date date = Date::read("Ingrese una fecha (dd/mm/yyyy): ");
    Day day = date.get_weekday();

    std::cout << std::endl;

    if (day == Day::Saturday || day == Day::Sunday) {
        std::cout << "dia feriado";
    } else {
        std::cout << "dia laborable";
    }

    std::cout << std::endl;
    std::cout << "en 31 dias la fecha es: ";

    date.add_days(31);

    std::cout << date.get_day() << "/" << date.get_month() << "/" << date.get_year() << std::endl;
}
