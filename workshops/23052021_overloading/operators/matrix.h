#pragma once
#include <vector>
#include <stdexcept>

class Matrix {
    public:
        Matrix(int size);

        /**
         * @brief imprime la matriz
         * 
         */
        void print();

        /**
         * @brief solicita datos por consola de manera interactiva 
         * para ingresarlos a la matriz
         * 
         */
        void interactive_input();

        /**
         * @brief sobrecarga del operador "+" para la suma de 2 matrices
         * 
         * @param matrix matriz a sumarse
         * @return Matrix matriz resultante
         */
        Matrix operator +(Matrix &matrix);

        /**
         * @brief sobrecarga del operador "-" para la resta de 2 matrices
         * 
         * @param matrix matriz a sumarse
         * @return Matrix matriz resultante
         */
        Matrix operator -(Matrix &matrix);

        /**
         * @brief sobrecarga del operador "[]" para el acceso 
         * a elementos de la matriz
         * 
         * @param matrix matriz a sumarse
         * @return Matrix matriz resultante
         */
        std::vector<int> operator [](int index) const;
    
        /**
         * @brief sobrecarga del operador "[]" para acceso por referencia 
         * a elementos de la matriz
         * 
         * @param matrix matriz a sumarse
         * @return Matrix matriz resultante
         */
        std::vector<int> & operator [](int index);

        Matrix operator ~();
        
        int get_size();

    private:
        std::vector<std::vector<int>> data;
        int size;
};
