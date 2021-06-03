#include <iostream>
#include <limits>
#include "matrix.h"
#include "matrix_utils.h"

int main(int argc, char **argv) {
    int size;

    do {
        std::cout << "ingrese la dimension de la matriz: ";
        std::cin >> size;

        if (size < 2 || std::cin.fail()) {
            std::cout << std::endl << "[el valor debe ser superior a 2]" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    } while (size < 2);

    Matrix<int> matrixA(size);
    Matrix<int> matrixB(size);

    MatrixUtils::fill_random(matrixA, 0, 9);
    MatrixUtils::fill_random(matrixB, 0, 9);

    std::cout << std::endl << "Matriz A:" << std::endl;
    MatrixUtils::print_matrix(matrixA);

    std::cout << std::endl << "Matriz B:" << std::endl;
    MatrixUtils::print_matrix(matrixB);

    return 0;
}
