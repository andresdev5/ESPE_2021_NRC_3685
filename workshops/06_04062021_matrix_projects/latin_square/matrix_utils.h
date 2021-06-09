#pragma once
#include "matrix.h"
#include "utils.h"
#include <iostream>
#include <stdexcept>
#include <random>
#include <chrono>
#include <vector>
#include <regex>

class MatrixUtils {
public:
    /**
     * @brief multiplica 2 matrices y regresa la matriz resultante
     *
     * @tparam T tipo de dato que contendra la matriz
     * @param matrixA matriz A
     * @param matrixB matriz B
     * @return Matrix<T> matriz resultante
     */
    template <typename T>
    static Matrix<T> multiply(Matrix<T> matrixA, Matrix<T> matrixB);

    /**
     * @brief multiplica una matriz n veces y retorna esa nueva matriz
     *
     * @tparam T tipo de dato que contendra la matriz
     * @param matrix matriz a ser multiplicada
     * @param exponent cantidad de veces que se multiplicara
     * @return Matrix<T> matriz resultante
     */
    template <typename T>
    static Matrix<T> pow(Matrix<T> matrix, int exponent);

    /**
     * @brief solicita por consola los valores de una matriz, para posteriormente actualizar la matriz con
     * dichos valores
     *
     * @tparam T tipo de dato de la matriz
     * @param matrix matriz a ser editada
     */
    template <typename T>
    static void interactive_input(Matrix<T> &matrix);

    /**
     * @brief llena una matriz con un valor dado
     *
     * @tparam T tipo de dato de la matriz
     * @param matrix matriz a ser llenada
     * @param value valor con el que se llenara la matriz
     */
    template <typename T>
    static void fill(Matrix<T> &matrix, T value);

    /**
     * @brief llena una matriz de valores aleatorios generados entre un minimo y maximo
     *
     * @tparam T tipo de dato de la matriz
     * @param matrix matriz a ser llenada
     * @param min valor minimo a ser generado
     * @param max valor maximo a ser generado
     */
    template <typename T>
    static void fill_random(Matrix<T> &matrix, int min, int max);

    /**
     * @brief imprime una matriz
     *
     * @tparam T tipo de dato de la matriz
     * @param matrix matriz a ser mostrada
     */
    template <typename T>
    static void print_matrix(Matrix<T> matrix);

    /**
     * @brief genera un cuadrado latino con un tamaño n dado
     * 
     * @tparam T 
     * @param siz3 
     * @return Matrix<T> 
     */
    template <typename T>
    static Matrix<T> generate_latin_square_origin(Matrix<T> &sol);

    /**
     * @brief genera una matriz identidad de tamaño n
     * 
     * @tparam T 
     * @param size 
     * @return Matrix<T> 
     */
    template <typename T>
    static Matrix<T> generate_identity_random(Matrix<T> &sol);

    /**
     * @brief genera una matriz latina base
     * 
     * @tparam T 
     * @param kernel 
     * @return Matrix<T> 
     */
    template<typename T>
    static Matrix<T> generate_kernel(Matrix<T> &kernel);

    /**
     * @brief devuelve un vector donde el primer elemento se pone al final y todos los demas se recorren
     * 
     * @param vector 
     * @return p* 
     */
    static int* recorrer(int* &vector, int size);

    /**
     * @brief intercambia las filas de una matriz
     * 
     * @tparam T 
     */
    template <typename T>
    static void interchange(Matrix<T> mat, int a, int b);
};

////////////////////////////////////////////////////////////////////////////////////////////////////

    