#include "application.h"
#include <iostream>
#include <limits>
#include <cstdlib>
#include "sudoku/sudoku.h"
#include "pascal_triangle/operation.h"
<<<<<<< HEAD
#include "latin_square/matrix.h"
#include "latin_square/matrix_utils.h"
#include "latin_square/utils.h"
=======
#include "magic_square/CuadradoMagico.h"
#include "identity_matrix/matrix.h"
#include "identity_matrix/identity_matrix.h"
#include "latin_square/latin_square.h"
>>>>>>> 4d9124bb40aa3f3314e8aede14bf9e21864a4f2c

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
<<<<<<< HEAD
        std::cout << "3: -" << std::endl;
        std::cout << "4: Cuadrado Latino" << std::endl;
        std::cout << "5: -" << std::endl;
=======
        std::cout << "3: Cuadrado magico" << std::endl;
        std::cout << "4: Matriz identidad" << std::endl;
        std::cout << "5: Cuadrado latino" << std::endl;
>>>>>>> 4d9124bb40aa3f3314e8aede14bf9e21864a4f2c
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
                CuadradoMagico cuadrado;
                for (int i = 3; i <= 10; i++) {
                    cuadrado.crearCuadrado(i);
                    std::cout << std::endl << std::endl;
		            cuadrado.imprimir();
                }
            }
            break;
            case 4: {
<<<<<<< HEAD
                std::cout << "Ingrese el numero de la dimension del cuadrado latino " << std::endl;
                int size;
                std::cin >> size;
                std::cout << "falta arreglar una referencia " << std::endl;
                // Matrix<long long> mat(size);
                // MatrixUtils::generate_latin_square_origin(mat);
                // MatrixUtils::print_matrix(mat);
                
=======
                int n;

                std::cout << "ingrese la dimension de la matriz: ";
                std::cin >> n;

                IdentityMatrix matrix(n);
                matrix.print();

                std::cout << std::endl << std::endl;
                matrix.calculate();
                matrix.print();
>>>>>>> 4d9124bb40aa3f3314e8aede14bf9e21864a4f2c
            }
            case 5: {
                int size;

                std::cout << "Ingrese la dimension: " << std::endl;
                std::cin >> size;

                LatinSquare latin_square(size);
                latin_square.generate();
                latin_square.print();
            }
        }

        if (opcion != 6) {
            std::cout << std::endl << std::endl;
            system("pause");
        }
    } while (opcion != 6);
 }
