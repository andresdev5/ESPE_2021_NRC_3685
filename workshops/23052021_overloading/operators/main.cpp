#include <iostream>
#include "matrix.h"

int suma(int a, int b);
int suma(int a, int b, int c);

int main(int argc, char **argv) {
    Matrix matrix_a(2);
    Matrix matrix_b(2);

    matrix_a.interactive_input();
    matrix_b.interactive_input();

    std::cout << "matriz A:" << std::endl;
    matrix_a.print();

    std::cout << std::endl << "matriz B:" << std::endl;
    matrix_b.print();
    
    std::cout << std::endl << "matriz A + B:" << std::endl;
    Matrix result = matrix_a + matrix_b;
    result.print();

    std::cout << std::endl << "matriz A + B (transpuesta):" << std::endl;
    Matrix transpose = ~result;
    transpose.print();
}
