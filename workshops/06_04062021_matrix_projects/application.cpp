#include "application.h"
#include <iostream>
#include <limits>
#include <cstdlib>
#include "sudoku/sudoku.h"
#include "pascal_triangle/operation.h"
#include "latin_square/matrix.h"
#include "latin_square/matrix_utils.h"
#include "latin_square/utils.h"

Application &Application::get_instance() {
    static auto &&instance = Application();
    return instance;
}

void Application::run() {
    int opcion;

    do {
        system("cls");
        std::cout << "1: Sudoku" << std::endl;
        std::cout << "2: Triangulo de pascal" << std::endl;
        std::cout << "3: -" << std::endl;
        std::cout << "4: Cuadrado Latino" << std::endl;
        std::cout << "5: -" << std::endl;
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
                Sudoku sudoku;
                sudoku.generate();
                sudoku.print();
            }
            break;
            case 2: {
                Operation operation;
                operation.final_score();
                std::cout << std::endl;
            }
            break;
            case 3: {
                
            }
            break;
            case 4: {
                std::cout << "Ingrese el numero de la dimension del cuadrado latino " << std::endl;
                int size;
                std::cin >> size;
                std::cout << "falta arreglar una referencia " << std::endl;
                // Matrix<long long> mat(size);
                // MatrixUtils::generate_latin_square_origin(mat);
                // MatrixUtils::print_matrix(mat);
                
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
