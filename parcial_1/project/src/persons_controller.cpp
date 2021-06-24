#include "persons_controller.h"
#include "person_builder.h"
#include <iostream>

PersonsController::PersonsController(Application *app) : Controller(app) {}

void PersonsController::init() {
    std::cout << "inicializando controlador personas" << std::endl;
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

LinkedList<Person> const &PersonsController::get_persons() {
    return persons_;
}
