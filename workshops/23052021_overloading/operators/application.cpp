#include "application.h"
#include <iostream>
#include <limits>
#include <cstdlib>
#include "matrix.h"

Application &Application::get_instance() {
    static auto &&instance = Application();
    return instance;
}

void Application::run() {
    int opcion;

    // run menu
    do {
        system("cls");
        std::cout << "Sobrecarga de operadores ejemplos" << std::endl << std::endl;
        std::cout << "1: matrices (+, -, ~)" << std::endl;
        std::cout << "2: salir" << std::endl;
        std::cout << std::endl;

        do {
            std::cout << "ingresa una opcion: ";
            std::cin >> opcion;

            if (opcion < 1 || opcion > 2) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        } while (opcion < 1 || opcion > 2);

        switch (opcion) {
            case 1: {
                Matrix matrix_a(2);
                Matrix matrix_b(2);

                matrix_a.interactive_input();
                matrix_b.interactive_input();

                std::cout << "matriz A:" << std::endl;
                matrix_a.print();

                std::cout << std::endl << "matriz B:" << std::endl;
                matrix_b.print();
                
                std::cout << std::endl << "matriz A + B:" << std::endl;
                Matrix result = matrix_a + matrix_b;
                result.print();

                std::cout << std::endl << "matriz A - B:" << std::endl;
                result = matrix_a - matrix_b;
                result.print();

                std::cout << std::endl << "matriz A (transpuesta):" << std::endl;
                Matrix transpose = ~matrix_a;
                transpose.print();

                std::cout << std::endl << std::endl;
                system("pause");
            }
            break;
        }
    } while (opcion != 2);
}
