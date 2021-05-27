#include "application.h"
#include <iostream>
#include <math.h>
#include <cstdlib>
#include <limits>
#include "Taylor.h"


Application &Application::get_instance() {
    static auto &&instance = Application();
    return instance;
}

void Application::run() {
    int opcion;

    do {
        system("cls");
        std::cout << "Funciones Matematicas" << std::endl << std::endl;
        std::cout << "1: Seno" << std::endl;
        std::cout << "2: Coseno" << std::endl;
        std::cout << "3: Tangente" << std::endl;
        std::cout << "4: Cotangente" << std::endl;
        std::cout << "5: " << std::endl;
        std::cout << "6: salir" << std::endl;
        std::cout << std::endl;

        do {
            std::cout << "ingresa una opcion: ";
            std::cin >> opcion;

            if (opcion < 1 || opcion > 6) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        } while (opcion < 1 || opcion > 6);

        switch (opcion) {
            case 1: {
                //funcion sin
                double pi = M_PI;
                double resultado = Taylor::calcular_sin(3.14,4);
                std::cout << resultado << std::endl;
            }
            break;
            case 2: {
                
            }
            break;
            case 3: {

            }
            break;
            case 4: {

            }
            case 5: {
                
            }
        }

        if (opcion != 6) {
            std::cout << std::endl << std::endl;
            system("pause");
        }
    } while (opcion != 6);
}
