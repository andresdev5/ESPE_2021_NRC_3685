#include <iostream>
#include "matrix.h"

int suma(int a, int b);
int suma(int a, int b, int c);

int main(int argc, char **argv) {
    Matrix matrix_a(2);
    Matrix matrix_b(2);

    matrix_a[0][0] = 1;
    matrix_a[0][1] = 1;
    matrix_a[1][0] = 1;
    matrix_a[1][1] = 1;

    matrix_b[0][0] = 1;
    matrix_b[0][1] = 1;
    matrix_b[1][0] = 1;
    matrix_b[1][1] = 1;

    Matrix result = matrix_a + matrix_b;
    result.print();

    std::cout << std::endl;

    Matrix transpose = ~result;
    transpose.print();
}
