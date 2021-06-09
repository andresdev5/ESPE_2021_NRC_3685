#pragma once
#include <cstdlib>
#include <exception>

template <typename T>
class Matrix {
public:
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
    int size;
};

////////////////////////////////////////////////////////////////////////////////////////////////////
