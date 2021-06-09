#include "application.h"
#include <iostream>
#include <math.h>
#include <cstdlib>
#include <limits>
#include "operation.h"
#include "matrix.h"

Application &Application::get_instance() {
    static auto &&instance = Application();
    return instance;
}

void Application::run() {
    int opcion;

    do {
        system("cls");
        std::cout << "Funciones Matematicas" << std::endl << std::endl;
        std::cout << "1: Cubo Magico" << std::endl;
        std::cout << "2: Sudoku" << std::endl;
        std::cout << "3: Triangulo de Pascal" << std::endl;
        std::cout << "4: Cubo Latino" << std::endl;
        std::cout << "5: Matriz Identidad" << std::endl;
        std::cout << "6: salir" << std::endl;
        std::cout << std::endl;

        do {
            std::cout << "ingresa una opcion: ";
            std::cin >> opcion;

            if (opcion < 1 || opcion > 6) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        } while (opcion < 1 || opcion >6);

        switch (opcion) {
            case 1: {
                // Cubo Magico
            }
            break;
            case 2: {
                // Sudoku
            }
            break;
            case 3: {
                Operation operation;
                operation.final_score();
                std::cout << std::endl;
            }
            break;
            case 4: {
                // Cubo Latino
            }
            break;
            case 5: {
                // Matriz Identidad
            }
            break;
        }

        if (opcion != 6) {
            std::cout << std::endl << std::endl;
            system("pause");
        }
    } while (opcion != 6);
}
