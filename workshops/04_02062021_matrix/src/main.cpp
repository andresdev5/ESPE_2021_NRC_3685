#include <iostream>
#include "matrix.h"
#include "matrix_utils.h"

int main(int argc, char **argv) {
    int size = 10;

    Matrix<int> matrixA(size);
    Matrix<int> matrixB(size);

    MatrixUtils::fill_random(matrixA, 0, 9);
    MatrixUtils::fill_random(matrixB, 0, 9);

    return 0;
}
