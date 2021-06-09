#include "latin_square.h"

LatinSquare::LatinSquare(int size) : size(size) {
    matrix = Matrix<int>(size);
}

void LatinSquare::generate() {
    int k = size + 1;
    int row = 0;
    int column = 0;
 
    for (int i = 1; i <= size; i++) {
        int temp = k;

        while (temp <= size) {
            matrix[row][column] = temp;
            temp++;
            column++;
        }
 
        for (int j = 1; j < k; j++) {
            matrix[row][column] = j;
            column++;
        }
 
        k--;
        row++;
        column = 0;
    }
}

void LatinSquare::print() {
    MatrixUtils::print(matrix);
}