#include "Operation.h"
#include "Matrix.h"

#include <iomanip>
#include <iostream>


Matrix matrix;

int** Operation::segmentar() {
    int **matriz, j;
    matriz = (int**)malloc(matrix.get_dimension() * sizeof(int*));
    for (j = 0; j < matrix.get_dimension(); j++)
        *(matriz + j) = (int*)malloc(matrix.get_dimension() * sizeof(int));
    return matriz;
}

void Operation::encerar(int** matriz) {
    int i, j;
    for (i = 0; i < matrix.get_dimension(); i++)
        for (j = 0; j < matrix.get_dimension(); j++)
        *(*(matriz + i) + j) = 0;
}

void Operation::generate_pascal_triangle(int** matriz) {
    int i, j, coeficiente = 1;
    for (i = 0; i < matrix.get_dimension(); i++) {
        for (j = 0; j <= i; j++) {
            if (j == 0 || i == 0)
                coeficiente = 1;
            else
                coeficiente = coeficiente * (i - j + 1) / j;
                *(*(matriz + i) + j) = *(*(matriz + i) + j) + coeficiente;
        }
    }
}

void Operation::toString(int** matriz) {
    int i, j, space;

    for (i = 0; i < matrix.get_dimension(); i++) {
        for (space = 1; space <= matrix.get_dimension() - i; space++){
            std::cout << "  ";
        }

        for (j = 0; j < matrix.get_dimension(); j++) {
            if (*(*(matriz + i) + j) != 0){
                std::cout << std::setw(4) << *(*(matriz + i) + j);
            }
        }
        std::cout << std::endl;
    }
}

void Operation::final_score() {
    int** _matrix;
    int dimension;

    std::cout << std::endl << "Ingrese la dimension de la matriz: ";
    std::cin >> dimension;

    matrix.set_dimension(dimension);
    _matrix = segmentar();
    encerar(_matrix);
    generate_pascal_triangle(_matrix);
    toString(_matrix);
}