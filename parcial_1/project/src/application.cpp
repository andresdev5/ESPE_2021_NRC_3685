#include <iostream>
#include <fmt/format.h>
#include <fmt/color.h>

#include "application.h"
#include "menu.h"
#include "menu_option.h"
#include "person_builder.h"
#include "persons_controller.h"
#include "payments_controller.h"

Application::Application() {
    register_dependencies();
}

void Application::run() {
    Menu menu("Amortizacion");

    // inicializar todos los controladores
    for (auto const &item : controllers_) {
        Controller *controller = item.second;
        controller->init();
    }

    // sub menu personas
    menu.add_option(MenuOption(
        "Personas",
        [&](MenuOptionArguments args) {
            auto controller = get_controller<PersonsController>("persons");
            controller->run();
        },
        false));

    // sub menu creditos
    menu.add_option(MenuOption(
        "Credito", [&](MenuOptionArguments args) {
            auto controller = get_controller<PaymentsController>("payments");
            controller->run();
        },
        false));

    // opcion salir
    menu.add_option(MenuOption(
        "Salir", [&menu](MenuOptionArguments args) { menu.stop(); }, false));

    menu.display();
}

void Application::register_dependencies() {
    // registro de los controladores
    controllers_.insert(std::make_pair("persons", new PersonsController(this)));
    controllers_.insert(std::make_pair("payments", new PaymentsController(this)));
}
