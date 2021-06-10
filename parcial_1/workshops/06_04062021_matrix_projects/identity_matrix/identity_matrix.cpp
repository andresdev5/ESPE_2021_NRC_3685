#include "identity_matrix.h"
#include "matrix_utils.h"
#include <iomanip>

IdentityMatrix::IdentityMatrix(int size) : size(size) {
    matrix = Matrix<float>(size);
    MatrixUtils::fill_random(matrix, 1, 9);
}

void IdentityMatrix::calculate() {
    float temp;

    for(int i = 0; i < size; i++) {
        for(int j = i + 1; j < size; j++) {
            temp = matrix[j][i] / matrix[i][i];

            for(int k = i;k < size + 1; k++) {
                matrix[j][k] -= temp * matrix[i][k];
                matrix[j][k] -= matrix[j][i] * matrix[i][k] / matrix[i][i];
            }
        }
    }

    MatrixUtils::print(matrix);
    std::cout << std::endl;

    for(int i = size - 1; i >= 0; i--) {
        for(int j = i - 1; j >= 0; j--) {
            temp = matrix[j][i] / matrix[i][i];

            for(int k = size; k >= i; k--) {
                matrix[j][k] -= temp * matrix[i][k];
            }
        }
    }

    MatrixUtils::print(matrix);
    std::cout << std::endl;

    float x[size];

    for(int i = 0; i < size; i++) x[i] = 0;

    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size + 1; j++) {
            if(x[i] == 0 && j != size) x[i] = matrix[i][j];
            if(x[i] != 0) matrix[i][j] /= x[i];
        }
    }
}

void IdentityMatrix::print() {
    Matrix<int> values(size);

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            values[i][j] = std::abs(matrix[i][j]);
        }
    }

    MatrixUtils::print(values);
}
