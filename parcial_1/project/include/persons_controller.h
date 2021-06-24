#pragma once
#include "controller.h"

class PersonsController : public Controller {
public:
    PersonsController(Application *app);
    virtual void init();
    void register_person();
    LinkedList<Person> const &get_persons();

private:
    LinkedList<Person> persons_;
};
