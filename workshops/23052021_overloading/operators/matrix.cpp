#include "matrix.h"
#include <iostream>

Matrix::Matrix(int size) : size(size) {
    data = std::vector<std::vector<int>>(size, std::vector<int>(size));
}

void Matrix::print() {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            std::cout << data[i][j];

            if (j != size - 1) {
                std::cout << ", ";
            }
        }

        std::cout << std::endl;
    }
}

Matrix Matrix::operator +(Matrix &matrix) {
    if (size != matrix.get_size()) {
        throw std::runtime_error("matrices must have the same size");
    }

    Matrix result(size);

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            int left = data.at(i).at(j);
            int right = matrix[i][j];

            result[i][j] = left + right;
        }
    }
    
    return result;
}

std::vector<int> Matrix::operator [](int index) const {
    return data[index];
}

std::vector<int> & Matrix::operator [](int index) {
    return data.at(index);
}

Matrix Matrix::operator~() {
    Matrix result(size);

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result[i][j] = data[j][i];
        }
    }

    return result;
}

int Matrix::get_size() {
    return size;
}