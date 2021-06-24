#include <iostream>

#include "application.h"
#include "menu.h"
#include "menu_option.h"
#include "person_builder.h"
#include "persons_controller.h"

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

    menu.add_option(MenuOption("Registrar una persona", [&](MenuOptionArguments args) {
        auto controller = get_controller<PersonsController>("persons");
        controller->register_person();
    }));

    menu.add_option(MenuOption("ver personas", [&](MenuOptionArguments args) {
        auto controller = get_controller<PersonsController>("persons");
        auto persons = controller->get_persons();

        persons.for_each([](Person person) { cout << person.firstname() << endl; });
    }));

    menu.add_option(MenuOption(
        "Salir", [&menu](MenuOptionArguments args) { menu.stop(); }, false));

    menu.display();
}

void Application::register_dependencies() {
    // registro de los controladores
    controllers_.insert(std::make_pair("persons", new PersonsController(this)));
}
