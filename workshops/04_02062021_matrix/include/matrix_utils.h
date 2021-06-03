#pragma once
#include "matrix.h"
#include <stdexcept>

class MatrixUtils {
public:
    template <typename T>
    static Matrix<T> multiply(Matrix<T> matrixA, Matrix<T> matrixB);

    template <typename T>
    static Matrix<T> pow(Matrix<T> matrix, int exponent);

    template <typename T>
    static void interactive_input(Matrix<T> matrix);
};

template <typename T>
Matrix<T> MatrixUtils::multiply(Matrix<T> matrixA, Matrix<T> matrixB) {
    if (matrixA.get_size() != matrixB.get_size()) {
        throw std::runtime_error("cannot multiply matrixA and matrixB, they have different size.");
    }

    Matrix<T> result(matrixA.get_size());
    return result;
}

template <typename T>
Matrix<T> MatrixUtils::pow(Matrix<T> matrix, int exponent) {
    Matrix<T> result = matrix;

    for (int i = 0; i < exponent; i++) {
        result = MatrixUtils<T>::multiply(result, matrix);
    }

    return result;
}

template <typename T>
void MatrixUtils::interactive_input(Matrix<T> matrix) {

}
