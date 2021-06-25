#pragma once
#include "application.h"

class Application;

class Controller {
public:
    Controller(Application *app);
    virtual void init() = 0;
    virtual void run() = 0;
    Application *app();

private:
    Application *app_;
};
