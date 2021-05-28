#include "application.h"
#include <iostream>
#include <math.h>
#include <cstdlib>
#include <limits>
#include "math_utils.h"

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
        std::cout << "5: raiz" << std::endl;
        std::cout << "6: calcular pi" << std::endl;
        std::cout << "7: salir" << std::endl;
        std::cout << std::endl;

        do {
            std::cout << "ingresa una opcion: ";
            std::cin >> opcion;

            if (opcion < 1 || opcion > 7) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        } while (opcion < 1 || opcion > 7);

        switch (opcion) {
            case 1: {
                double angle;

                std::cout << "ingrese un angulo en grados: ";
                std::cin >> angle;

                double result = MathUtils::sin(angle);
                std::cout << "sin(" << angle << ") = " << result << std::endl;
            }
            break;
            case 2: {
                double angle;

                std::cout << "ingrese un angulo en grados: ";
                std::cin >> angle;

                double result = MathUtils::cos(angle);
                std::cout << "cos(" << angle << ") = " << result << std::endl;
            }
            break;
            case 3: {
                double angle;

                std::cout << "ingrese un angulo en grados: ";
                std::cin >> angle;

                double result = MathUtils::tan(angle);
                std::cout << "tan(" << angle << ") = " << result << std::endl;
            }
            break;
            case 4: {
                //funcion cotangente
            }
            case 5: {
                
            }
            case 6: {
                int terms;

                std::cout << "ingrese el total de terminos (sugerencia > 1000): ";
                std::cin >> terms;

                std::cout << "PI = " << MathUtils::pi(terms) << std::endl;
            }
        }

        if (opcion != 7) {
            std::cout << std::endl << std::endl;
            system("pause");
        }
    } while (opcion != 7);
}
