#include "payments_controller.h"
#include "persons_controller.h"
#include <decimal/decimal.h>
#include <fmt/chrono.h>
#include "utils.h"
#include "date.h"
#include <regex>
#include <sstream>
#include <fstream>
#include "TextTable.h"

PaymentsController::PaymentsController(Application *app)
    : Controller(app), menu_(Menu("Amortizacion / credito")), credits_storage_({make_credits_storage()}) {}

void PaymentsController::init() {
    menu_.add_option(MenuOption("crear credito", [this](MenuOptionArguments args) { create_credit(); }));
    menu_.add_option(MenuOption("ver credito", [this](MenuOptionArguments args) { view_credits(); }));

    // opcion salir
    menu_.add_option(MenuOption(
        "Regresar", [&](MenuOptionArguments args) { menu_.stop(); }, false));
}

void PaymentsController::run() {
    load_data();

    // mostrar menu
    menu_.display();
}

void PaymentsController::load_data() {
    auto rows = credits_storage_.storage.get_all<PersonCreditDbRow>();
    auto persons = app()->get_controller<PersonsController>("persons")->get_persons();

    credits_.clear();

    for (auto row : rows) {
        auto person_node = persons.find([row](Person person) { return person.id() == row.person_id; });
        bool found = (person_node != nullptr);

        if (!found) {
            continue;
        }

        std::regex pattern("^(0?[1-9]|[12][0-9]|3[01])[\\/\\-](0?[1-9]|1[012])[\\/\\-](\\d{4})$");
        std::smatch matches;
        std::regex_match(row.date, matches, pattern);

        int day = std::stoi(matches[1]);
        int month = std::stoi(matches[2]);
        int year = std::stoi(matches[3]);

        Date date(day, month, year);
        dec::decimal<2> amount(row.amount);
        float interest = row.interest;

        PersonCredit person_credit(person_node->get_data(), date, amount, interest, row.total_months);
        credits_.insert(std::make_pair(row.person_id, person_credit));
    }
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

    if ((credits_.find(id) != credits_.end())) {
        fmt::print(fg(fmt::color::red), "\n[ya existe un credito para esa persona]\n");
        return;
    }

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
    PersonCredit person_credit(person_node->get_data(), date, fixed_amount, interest, months);
    std::string date_fmt = fmt::format("{:02d}/{:02d}/{:02d}", date.get_day(), date.get_month(), date.get_year());
    PersonCreditDbRow row{person_node->get_data().id(), months, fixed_amount.getAsDouble(), interest, date_fmt};

    credits_storage_.storage.insert(row);
    std::cout << std::endl;
}

void PaymentsController::view_credits() {
    std::ostringstream html;
    std::string id;

    load_data();

    do {
        id = read_line("ingresa la cedula: ");

        if (!is_person_id_valid(id)) {
            fmt::print(fg(fmt::color::red), "\n[la cedula es invalida]\n");
            continue;
        }

        break;
    } while (true);

    bool exists = credits_.find(id) != credits_.end();

    if (!exists) {
        fmt::print(fg(fmt::color::red), "\n[no existe una persona con esa cedula]\n");
        return;
    }

    TextTable t('-', '|', '+');

    t.add(" Cedula ");
    t.add(" Nombre ");
    t.add(" Apellido ");
    t.add(" Direccion ");
    t.add(" Telefono ");
    t.add(" Email ");
    t.add(" Periodo ");
    t.add(" Fecha ");
    t.add(" Cuota ");
    t.add(" Intereses ");
    t.add(" Capital ");
    t.add(" Saldo ");
    t.endOfRow();

    html << "<html>"
            "<head><title>Amortizacion</title></head>"
            "<body>"
            "<table><thead><tr>"
            "<th>Cedula</th>"
            "<th>Nombre</th>"
            "<th>Apellido</th>"
            "<th>Direccion</th>"
            "<th>Telefono</th>"
            "<th>Email</th>"
            "<th>Periodo</th>"
            "<th>Fecha</th>"
            "<th>Cuota</th>"
            "<th>Intereses</th>"
            "<th>Capital</th>"
            "<th>Saldo</th>"
            "</tr></thead><tbody>";

    for (auto entry : credits_) {
        auto credit = entry.second;
        auto person = credit.get_person();

        Date date = credit.get_date();

        double amount = credit.get_amount().getAsDouble();
        float interest = credit.get_interest() / 100;
        int months = credit.get_months();
        double payment =
            (amount * ((std::pow((1 + interest), months) * interest) /
                                                   (std::pow((1 + interest), months) - 1)));

        dec::decimal<2> fixed_payment(payment);

        Date previous(date);
        std::vector<Date> dates;

        dates.push_back(date);

        for (int i = 0; i < months - 1; i++) {
            date.add_days(date.last_month_day());
            Date last(date.get_day(), date.get_month(), date.get_year());

            while (last.get_weekday() == Day::Saturday || last.get_weekday() == Day::Sunday || last.is_holiday()) {
                last.add_days(1);
            }

            Date current(last.get_day(), last.get_month(), last.get_year());
            dates.push_back(date);
            // std::cout << last.get_day() << "/" << last.get_month() << "/" << last.get_year() << std::endl;
        }

        for (int i = 0; i < months; i++) {
            std::string date_fmt = fmt::format(
                "{:02d}/{:02d}/{:02d}", dates.at(i).get_day(), dates.at(i).get_month(), dates.at(i).get_year());

            double interests = amount * interest;
            double capital = payment - interests;
            double balance = amount - capital;
            amount = balance;

            t.add(" " + person.id() + " ");
            t.add(" " + person.firstname() + " ");
            t.add(" " + person.lastname() + " ");
            t.add(" " + person.address() + " ");
            t.add(" " + person.phone() + " ");
            t.add(" " + person.email() + " ");
            t.add(" " + std::to_string(i + 1) + " ");
            t.add(" " + date_fmt + " ");
            t.add(" " + fmt::format("{0:.2f}", fixed_payment.getAsDouble()) + " ");
            t.add(" " + fmt::format("{0:.2f}", interests) + " ");
            t.add(" " + fmt::format("{0:.2f}", capital) + " ");
            t.add(" " + fmt::format("{0:.2f}", balance) + " ");
            t.endOfRow();

            html << "<tr>"
                 << "<td>" + person.id() + "</td>"
                 << "<td>" + person.firstname() + "</td>"
                 << "<td>" + person.lastname() + "</td>"
                 << "<td>" + person.address() + "</td>"
                 << "<td>" + person.phone() + "</td>"
                 << "<td>" + person.email() + "</td>"
                 << "<td>" + std::to_string(i + 1) + "</td>"
                 << "<td>" + date_fmt + "</td>"
                 << "<td>" + fmt::format("{0:.2f}", fixed_payment.getAsDouble()) + "</td>"
                 << "<td>" + fmt::format("{0:.2f}", interests) + "</td>"
                 << "<td>" + fmt::format("{0:.2f}", capital) + "</td>"
                 << "<td>" + fmt::format("{0:.2f}", balance) + "</td>"
                 << "</tr>";
        }
    }

    html << "</tbody></table></body></html>";

    t.setAlignment(2, TextTable::Alignment::LEFT);
    std::cout << t << std::endl;

    std::ostringstream plain;
    std::string html_filename = "data_" + id + ".html";
    std::string pdf_filename = "data_" + id + ".pdf";
    std::ofstream out_html(html_filename, std::ios::trunc);
    std::ofstream out_txt("data_" + id + ".txt", std::ios::trunc);

    plain << t;
    out_txt << t;
    out_html << html.str();
    out_txt.close();
    out_html.close();

    if (std::ifstream(pdf_filename.c_str()).good()) {
        std::remove(pdf_filename.c_str());
    }

    system((std::string("wkhtmltopdf.exe ") + html_filename + " " + pdf_filename).c_str());
    std::cout << std::endl << "archivo pdf generado!";
}
