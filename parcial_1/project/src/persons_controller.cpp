#include "persons_controller.h"
#include "person_builder.h"
#include "utils.h"
#include <iostream>
#include <regex>
#include <vector>

PersonsController::PersonsController(Application *app) : Controller(app), menu_(Menu("Amortizacion / personas")) {}

void PersonsController::init() {
    // registar opcion del menu para registrar nuevas personas
    menu_.add_option(MenuOption("Registrar nueva persona", [&] (MenuOptionArguments args) {
        register_person();
    }));

    menu_.add_option(MenuOption("Ver personas", [&](MenuOptionArguments args) {
        view_persons();
    }));

    // opcion para regresar al menu principal
    menu_.add_option(MenuOption("Regresar", [this](MenuOptionArguments args) { menu_.stop(); }, false));
}

void PersonsController::run() {
    menu_.display();
}

void PersonsController::register_person() {
    PersonBuilder person_builder;

    std::string id;
    std::string firstname;
    std::string lastname;
    std::string address;
    std::string phone;

    std::regex name_pattern("^[\\w'\\-,.][^0-9_!¡?÷?¿\\/\\\+=@#$%ˆ&*(){}|~<>;:[\\]]{2,}$");

    do {
        id = read_line("ingresa la cedula: ");

        if (!is_person_id_valid(id)) {
            fmt::print(fg(fmt::color::red), "\n[la cedula es invalida]\n");
            continue;
        }

        break;
    } while (true);

    do {
        firstname = read_line("ingrese los nombres:");

        if (!std::regex_match(firstname, name_pattern)) {
            fmt::print(fg(fmt::color::red), "\n[formato incorrecto]\n");
            continue;
        }

        break;
    } while (true);

    do {
        lastname = read_line("ingrese los apellidos:");

        if (!std::regex_match(lastname, name_pattern)) {
            fmt::print(fg(fmt::color::red), "\n[formato incorrecto]\n");
            continue;
        }

        break;
    } while (true);

    address = read_line("ingrese la direccion:");

    do {
        address = read_line("ingrese el telefono (+593): ");

        if (!std::regex_match(address, std::regex("^(09[0-9]{8}|0?[1-8][0-9]{7})$"))) {
            fmt::print(fg(fmt::color::red), "\n[numero incorrecto]\n");
            continue;
        }

        break;
    } while (true);

    Person person = person_builder
        .id(id)
        .firstname(firstname)
        .lastname(lastname)
        .address(address)
        .phone(phone)
        .automatic_email("espe.edu.ec")
        .build();

    persons_.push_back(person);
}

void PersonsController::view_persons() {
    std::vector<int> columns_width;

    persons_.for_each([&](Person person) {

    });
}

LinkedList<Person> const &PersonsController::get_persons() {
    return persons_;
}
