#pragma once
#include <iostream>
#include "../identity_matrix/matrix.h"
#include "../identity_matrix/matrix_utils.h"

class LatinSquare {
public:
    LatinSquare(int size);
    void generate();
    void print();

private:
    Matrix<int> matrix;
    int size;
};
