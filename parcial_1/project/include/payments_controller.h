#pragma once
#include "controller.h"
#include "menu.h"

class PaymentsController : public Controller {
public:
    PaymentsController(Application *app);
    virtual void init();
    virtual void run();

private:
    void create_credit();

    Menu menu_;
};
