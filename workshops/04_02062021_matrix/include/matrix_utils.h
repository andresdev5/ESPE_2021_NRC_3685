#pragma once
#include "matrix.h"

class MatrixUtils {
public:
    template <typename T>
    static Matrix<T> multiply(Matrix<T> matrixA, Matrix<T> matrixB);

    template <typename T>
    static Matrix<T> pow(Matrix<T> matrix, int exponent);
};

#include "../src/matrix_utils.cpp"
