#pragma once
#include "application.h"

class Application;

class Controller {
public:
    Controller(Application *app);
    Application *get_app();
    virtual void init() = 0;
    virtual void run() = 0;

private:
    Application *app_;
};
