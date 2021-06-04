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
}
