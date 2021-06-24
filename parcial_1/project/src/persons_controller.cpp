#include "persons_controller.h"
#include "person_builder.h"
#include <iostream>

PersonsController::PersonsController(Application *app) : Controller(app), menu_(Menu("Amortizacion / personas")) {}

void PersonsController::init() {
    // registar opcion del menu para registrar nuevas personas
    menu_.add_option(MenuOption("registrar nueva persona", [&] (MenuOptionArguments args) {
        register_person();
    }));

    menu_.add_option(MenuOption("ver personas", [&](MenuOptionArguments args) {
        view_persons();
    }));

    // opcion para regresar al menu principal
    menu_.add_option(MenuOption("regresar", [this](MenuOptionArguments args) { menu_.stop(); }, false));
}

void PersonsController::run() {
    menu_.display();
}

void PersonsController::register_person() {
    PersonBuilder person_builder;
    Person person = person_builder
                        .id("1726744293")
                        .firstname("Andres Jonathan")
                        .lastname("Jacome Navarrete")
                        .address("Villaflora")
                        .phone("0998598514")
                        .automatic_email("espe.edu.ec")
                        .build();

    persons_.push_back(person);
}

void PersonsController::view_persons() {
    persons_.for_each([](Person person) { cout << person.firstname() << endl; });
}

LinkedList<Person> const &PersonsController::get_persons() {
    return persons_;
}
