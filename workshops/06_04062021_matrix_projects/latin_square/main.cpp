#include <iostream>
#include <limits>
#include "matrix.h"
#include "matrix_utils.h"

int main(int argc, char **argv) {
    
    std::cout << "Programa para crear un cuadrado latino de dimensión n" << std::endl;
    int size ;
    std::cin >> size; 
    
    Matrix<long long> mat(size);
    MatrixUtils::generate_latin_square_origin(mat);
    MatrixUtils::print_matrix(mat);
    return 0;
}
