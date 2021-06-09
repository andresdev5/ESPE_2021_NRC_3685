#pragma once
#include <cstdlib>
#include <exception>
#include <iostream>

template <typename T>
class Matrix {
public:
    Matrix() = default;
    Matrix(int size);

    /**
     * @brief definir un elemento de una matriz dada una posicion
     *
     * @param row indice de la fila
     * @param column indice de la columna
     * @param value nuevo valor a definir en la posicion dada
     */
    void set_element(int row, int column, T value);

    /**
     * @brief obtener el elemento de una matriz dada una posicion
     *
     * @param row
     * @param column
     * @return int
     */
    T get_element(int row, int column);

    /**
     * @brief definir todos los valores de la matriz
     *
     * @param data arreglo bidimensional conteniendo todos los valores nuevos
     */
    void set_data(T **data);

    /**
     * @brief obtener los valores de la matriz. Regresa una referencia al arreglo bidimensional interno
     *
     * @return int**
     */
    T **get_data();

    /**
     * @brief obtener el tamaño de la matriz
     *
     * @return int
     */
    int get_size();

    /**
     * @brief limpia la memoria alojada
     *
     */
    void free();

    /**
     * @brief sobrecarga del operador "[]" para el acceso 
     * a elementos de la matriz
     * 
     * @param matrix matriz a sumarse
     * @return Matrix matriz resultante
     */
    T *operator [](int index) const;

    /**
     * @brief sobrecarga del operador "[]" para acceso por referencia 
     * a elementos de la matriz
     * 
     * @param matrix matriz a sumarse
     * @return Matrix matriz resultante
     */
    T *&operator [](int index);

private:
    /**
     * @brief arreglo bidimensional
     *
     */
    T **data = nullptr;

    /**
     * @brief tamaño de la matriz cuadrada
     *
     */
    int size = 0;
};

////////////////////////////////////////////////////////////////////////////////////////////////////
<<<<<<< HEAD:workshops/06_04062021_matrix_projects/latin_square/matrix.h
=======

template <typename T>
Matrix<T>::Matrix(int size) : size(size) {
    if (size < 2) {
        throw std::runtime_error("matrix must be at least 2 for size.");
    }

    // allocate memory
    data = (T **)calloc(size, sizeof(T *));

    for (int i = 0; i < size; i++) {
        data[i] = (T *)calloc(size, sizeof(T));
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
void Matrix<T>::free() {
    for (int i = 0; i < size; i++) {
        std::cout << i << std::endl;
        free(data[i]);
    }

    free(data);
}

template <typename T>
T * Matrix<T>::operator [](int index) const {
    return data[index];
}

template <typename T>
T *& Matrix<T>::operator [](int index) {
    return data[index];
}
>>>>>>> 4d9124bb40aa3f3314e8aede14bf9e21864a4f2c:workshops/06_04062021_matrix_projects/identity_matrix/matrix.h
