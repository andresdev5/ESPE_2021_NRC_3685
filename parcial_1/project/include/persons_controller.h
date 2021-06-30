#pragma once
#include <sqlite_orm/sqlite_orm.h>
#include "controller.h"
#include "menu.h"

enum class PersonField {
    Id,
    Firstname,
    Lastname,
    Address,
    Phone,
    Email
};

using namespace sqlite_orm;

template <typename... Args>
auto make_storage_query() {
    return make_storage("database.sqlite",
        make_table("persons", make_column("id", &PersonPojo::id, sqlite_orm::unique()),
            make_column("firstname", &PersonPojo::firstname), make_column("lastname", &PersonPojo::lastname),
            make_column("address", &PersonPojo::address), make_column("phone", &PersonPojo::phone),
            make_column("email", &PersonPojo::email, sqlite_orm::unique())));
}

typedef struct PersonQuery {
    decltype(make_storage_query()) storage;
};

class PersonsController : public Controller {
public:
    PersonsController(Application *app);
    virtual void init();
    virtual void run();

    /**
     * @brief registra una nueva persona
    */
    void register_person();

    /**
     * @brief guarda una persona en la base de datos
     * @param person 
    */
    void save_person(Person person);

    /**
     * @brief vista de las personas registradas
    */
    void view_persons();

    /**
     * @brief realiza un backup de las personas
    */
    void backup_data();

    /**
     * @brief obtiene la lista de todas las personas
     * @return 
    */
    LinkedList<Person> const &get_persons();

private:
    LinkedList<Person> persons_;
    Menu menu_;
};
