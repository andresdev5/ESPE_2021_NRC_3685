#pragma once
#include "matrix_utils.h"
#include <stdexcept>

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
    Matrix<T> result(matrix.get_size());
    return result;
}
