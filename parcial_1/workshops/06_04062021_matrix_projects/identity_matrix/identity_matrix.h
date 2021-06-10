#pragma once
#include "matrix.h"

class IdentityMatrix {
public:
    IdentityMatrix(int size);
    void calculate();
    void print();

private:
    Matrix<float> matrix;
    int size;
};
