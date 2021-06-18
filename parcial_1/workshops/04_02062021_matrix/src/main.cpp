#include <iostream>
#include <limits>
#include "matrix.h"
#include "matrix_utils.h"

int main(int argc, char **argv) {
    int size;
    int exponent;

    do {
        std::cout << "ingrese la dimension de la matriz: ";
        std::cin >> size;

        if (size < 2 || std::cin.fail()) {
            std::cout << std::endl << "[el valor debe ser superior a 2]" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    } while (size < 2);

    Matrix<long long> matrixA(size);
    Matrix<long long> matrixB(size);
    Matrix<long long> matrixC(size);
    Matrix<long long> matrixD(size);

    MatrixUtils::fill_random(matrixA, 0, 9);

    MatrixUtils::fill_random(matrixA, 0, 9);
    MatrixUtils::fill_random(matrixB, 0, 9);

    std::cout << std::endl << "Matriz A:" << std::endl;
    MatrixUtils::print_matrix(matrixA);

    std::cout << std::endl << "Matriz B:" << std::endl;
    MatrixUtils::print_matrix(matrixB);

    matrixC = MatrixUtils::multiply(matrixA, matrixB);

    std::cout << std::endl << "(A * B) :" << std::endl;
    MatrixUtils::print_matrix(matrixC);

    do {
        std::cout << "ingrese un valor: ";
        std::cin >> exponent;

        if (size < 0 || std::cin.fail()) {
            std::cout << std::endl << "[el valor debe ser un valor numerico positivo valido]" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            size = -1;
        }
    } while (size < 0);

    matrixD = MatrixUtils::pow(matrixC, exponent);

    std::cout << std::endl << "(A * B) ^ " << exponent << " :" << std::endl;
    MatrixUtils::print_matrix(matrixD);

    return 0;
}
