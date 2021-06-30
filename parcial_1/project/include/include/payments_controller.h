#pragma once
#include "controller.h"
#include "menu.h"
#include "person_credit.h"

using namespace sqlite_orm;

template <typename... Args>
auto make_credits_storage() {
    return make_storage("database.sqlite",
        make_table("person_credit", make_column("person_id", &PersonCreditDbRow::person_id, sqlite_orm::unique()),
            make_column("total_months", &PersonCreditDbRow::total_months), make_column("amount", &PersonCreditDbRow::amount),
            make_column("interest", &PersonCreditDbRow::interest), make_column("date", &PersonCreditDbRow::date)));
}

typedef struct CreditsStorage {
    decltype(make_credits_storage()) storage;
};

class PaymentsController : public Controller {
public:
    PaymentsController(Application *app);
    virtual void init();
    virtual void run();
    void view_credits();

private:
    void create_credit();
    void load_data();

    Menu menu_;
    std::map<std::string, PersonCredit> credits_;
    CreditsStorage credits_storage_;
};
