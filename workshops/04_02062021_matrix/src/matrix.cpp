#pragma once
#include "matrix.h"
#include <cstdlib>
#include <exception>

template <typename T>
Matrix<T>::Matrix(int size) : size(size) {
    if (size < 2) {
        throw std::runtime_error("matrix must be at least 2 for size.");
    }

    // allocate memory
    data = (int **)calloc(size, sizeof(int *));

    for (int i = 0; i < size; i++) {
        data[i] = (int *)calloc(size, sizeof(int));
    }
}

template <typename T>
T Matrix<T>::get_element(int row, int column) {
    return data[row][column];
}

template <typename T>
void Matrix<T>::set_element(int row, int column, T value) {
    data[row][column] = value;
}

template <typename T>
T **Matrix<T>::get_data() {
    return data;
}

template <typename T>
void Matrix<T>::set_data(T **data) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            this->data[i][j] = data[i][j];
        }
    }
}

template <typename T>
int Matrix<T>::get_size() {
    return size;
}

template <typename T>
Matrix<T>::~Matrix() {
    for (int i = 0; i < size; i++) {
        free(data[i]);
    }

    free(data);
}
