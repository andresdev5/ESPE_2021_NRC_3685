#include "application.h"
#include <iostream>
#include <limits>
#include <cstdlib>
#include "date.h"
#include "person.h"

Application &Application::get_instance() {
    static auto &&instance = Application();
    return instance;
}

void Application::run() {
    int opcion;

    //do {
        system("cls");
        std::cout<< "Realizar proyecto";

        /*if (opcion != 6) {
            std::cout << std::endl << std::endl;
            system("pause");
        }*/
    //} while (/*opcion != 6*/);
}
