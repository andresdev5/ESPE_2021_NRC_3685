#pragma once
#include "controller.h"
#include "menu.h"

class PersonsController : public Controller {
public:
    PersonsController(Application *app);
    virtual void init();
    virtual void run();
    void register_person();
    void view_persons();
    LinkedList<Person> const &get_persons();

private:
    LinkedList<Person> persons_;
    Menu menu_;
};
