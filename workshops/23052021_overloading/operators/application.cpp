#include "application.h"
#include <iostream>
#include <limits>
#include <cstdlib>
#include "matrix.h"
#include "user.h"

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
        std::cout << "2: usuarios (==, !=, <, >)" << std::endl;
        std::cout << "3: salir" << std::endl;
        std::cout << std::endl;

        do {
            std::cout << "ingresa una opcion: ";
            std::cin >> opcion;

            if (opcion < 1 || opcion > 3) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        } while (opcion < 1 || opcion > 3);

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
            }
            break;
            case 2: {
                std::string identify_card;
                std::string name;
                int age;

                User user_1;
                User user_2;

                std::cout << "(usuario 1) ingrese la cedula: ";
                std::cin >> identify_card;

                std::cout << "(usuario 1) ingrese el nombre: ";
                std::cin >> name;

                std::cout << "(usuario 1) ingrese la edad: ";
                std::cin >> age;

                user_1.set_identify_card(identify_card);
                user_1.set_name(name);
                user_1.set_age(age);

                std::cout << "(usuario 2) ingrese la cedula: ";
                std::cin >> identify_card;

                std::cout << "(usuario 2) ingrese el nombre: ";
                std::cin >> name;

                std::cout << "(usuario 2) ingrese la edad: ";
                std::cin >> age;

                user_2.set_identify_card(identify_card);
                user_2.set_name(name);
                user_2.set_age(age);

                std::cout << std::endl << std::endl;

                if (user_1 != user_2) {
                    std::cout << "los usuarios ingresados son diferentes" << std::endl;
                }
                
                if (user_1 == user_2) {
                    std::cout << "los usuarios ingresados son iguales" << std::endl;
                }

                if (user_1 > user_2) {
                    std::cout << "el usuario 1 es mayor al usuario 2" << std::endl;
                } else if (user_1 < user_2) {
                    std::cout << "el usuario 1 es menor al usuario 2" << std::endl;
                } else {
                    std::cout << "los 2 usuarios tienen la misma edad" << std::endl;
                }
            }
            break;
        }


        if (opcion != 3) {
            std::cout << std::endl << std::endl;
            system("pause");
        }
    } while (opcion != 3);
}
