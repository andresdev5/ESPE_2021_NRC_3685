#pragma once
#include "application.h"

class Application;

class Controller {
public:
    Controller(Application *app);

    /**
     * @brief hook que inicializa el controlador
     */
    virtual void init() = 0;

    /**
     * @brief ejecutar un controlador
     */
    virtual void run() = 0;

    /**
     * @brief instancia de la aplicacion
     * @return 
     */
    Application *app();

private:
    Application *app_;
};
