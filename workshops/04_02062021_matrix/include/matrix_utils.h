#pragma once
#include "matrix.h"
#include <stdexcept>
#include <random>
#include <chrono>

class MatrixUtils {
public:
    template <typename T>
    static Matrix<T> multiply(Matrix<T> matrixA, Matrix<T> matrixB);

    template <typename T>
    static Matrix<T> pow(Matrix<T> matrix, int exponent);

    template <typename T>
    static void interactive_input(Matrix<T> &matrix);

    template <typename T>
    static void fill_random(Matrix<T> &matrix, int min, int max);
};

template <typename T>
Matrix<T> MatrixUtils::multiply(Matrix<T> matrixA, Matrix<T> matrixB) {
    if (matrixA.get_size() != matrixB.get_size()) {
        throw std::runtime_error("cannot multiply matrixA and matrixB, they have different size.");
    }

    int size = matrixA.get_size();
    Matrix<T> result(matrixA.get_size());

    for (int i = 0; i < matrixA.get_size(); i++) {
        for (int j = 0; j < matrixA.get_size(); i++) {
            int sum = 0;

            for (int k = 0; k < size; k++) {
                sum += matrixA.at(i, k) * matrixB.at(k, j);
            }

            result.set_element(i, j, sum);
        }
    }
    
    return result;
}

template <typename T>
Matrix<T> MatrixUtils::pow(Matrix<T> matrix, int exponent) {
    Matrix<T> result = matrix;

    for (int i = 0; i < exponent; i++) {
        result = MatrixUtils::multiply<T>(result, matrix);
    }

    return result;
}

template <typename T>
void MatrixUtils::fill_random(Matrix<T> &matrix, int min, int max) {
    std::random_device rd;
    std::uniform_int_distribution<> dist(min, max);
    static std::mt19937_64 random_generator(std::chrono::system_clock::now().time_since_epoch().count());
    
    int size = matrix.get_size();

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matrix.set_element(i, j, dist(random_generator));
        }
    }
}

template <typename T>
void MatrixUtils::interactive_input(Matrix<T> &matrix) {

}
