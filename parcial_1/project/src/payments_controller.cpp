#include "payments_controller.h"
#include "persons_controller.h"
#include <decimal/decimal.h>
#include "utils.h"
#include "date.h"
#include "person_credit.h"

PaymentsController::PaymentsController(Application *app) : Controller(app), menu_(Menu("Amortizacion / credito")) {}

void PaymentsController::init() {
    menu_.add_option(MenuOption("crear credito", [&](MenuOptionArguments args) {
        create_credit();
    }));

    // opcion salir
    menu_.add_option(MenuOption(
        "Salir", [&](MenuOptionArguments args) { menu_.stop(); }, false));
}

void PaymentsController::run() {
    // ...

    // mostrar menu
    menu_.display();
}

void PaymentsController::create_credit() {
    std::string id;  // cedula
    double amount; // monto
    float interest; // interes
    int months; // plazos

    auto persons = app()->get_controller<PersonsController>("persons")->get_persons();

    do {
        id = read_line("ingresa la cedula: ");

        if (!is_person_id_valid(id)) {
            fmt::print(fg(fmt::color::red), "\n[la cedula es invalida]\n");
            continue;
        }

        bool exists = (persons.find([id](Person person) { return person.id() == id; })) != nullptr;

        if (!exists) {
            fmt::print(fg(fmt::color::red), "\n[no existe una persona con esa cedula]\n");
            continue;
        }

        break;
    } while (true);

    auto person_node = persons.find([id](Person person) { return person.id() == id; });

    if (person_node == nullptr) {
        fmt::print(fg(fmt::color::red), "\n[no se encontro esa persona]\n");
        return;
    }

    amount = read_double("ingrese un monto: ", 0);
    months = read_int("ingrese el total de meses: ", 1);
    interest = read_double("ingrese la taza de interes: ", 0);

    Date date = Date::read("Ingrese una fecha (dd/mm/yyyy): ");
    Day day = date.get_weekday();
    bool moved = false;

    while (day == Day::Saturday || day == Day::Sunday || date.is_holiday()) {
        date.add_days(1);
        day = date.get_weekday();
        moved = true;
    }

    if (moved) {
        fmt::print(fg(fmt::color::aqua), "\n[se ha movido la fecha a otro dia]\n");
    }

    dec::decimal<2> fixed_amount(amount);

    Date previous(date);
    PersonCredit person_credit(person_node->get_data(), date, fixed_amount, interest);

    std::cout << std::endl;

    for (int i = 0; i < months; i++) {
        date.add_days(date.last_month_day());

        Date last(date.get_day(), date.get_month(), date.get_year());

        while (last.get_weekday() == Day::Saturday || last.get_weekday() == Day::Sunday || last.is_holiday()) {
            last.add_days(1);
        }

        Date current(last.get_day(), last.get_month(), last.get_year());
        std::cout << last.get_day() << "/" << last.get_month() << "/" << last.get_year() << std::endl;
    }
}
