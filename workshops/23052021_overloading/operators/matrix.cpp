#include "matrix.h"
#include <iostream>
#include <limits>
#include <cstdlib>
#include <regex>
#include "utils.h"

Matrix::Matrix(int size) : size(size) {
    data = std::vector<std::vector<int>>(size, std::vector<int>(size));
}

void Matrix::print() {
    if (data.empty()) {
        return;
    }

    int m = data.size();
    int n = data.at(0).size();

    /*
    // these ASCII characters may not work with some fonts
    char tiles[] = {
        '┌', // 0: top left corner
        '┐', // 1: top right corner
        '└', // 2: bottom left corner
        '┘', // 3: bottom right corner
        '─', // 4: horizontal line
        '│', // 5: vertical line
        '┬', // 6: top separator
        '┴', // 7: bottom separator
        '├', // 8: middle left vertical line
        '┼', // 9: middle center vertical line
        '┤' // 10: middle right vertical line
    };
    */
    
    // fallback for the previous extended ASCII characters
    char tiles[] = {
        '+', // 0: top left corner
        '+', // 1: top right corner
        '+', // 2: bottom left corner
        '+', // 3: bottom right corner
        '-', // 4: horizontal line
        '|', // 5: vertical line
        '+', // 6: top separator
        '+', // 7: bottom separator
        '+', // 8: middle left vertical line
        '+', // 9: middle center vertical line
        '+' // 10: middle right vertical line
    };

    std::vector<int> columns_width(n);

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int value = data[i][j];

            if (value < 0) value *= -1;
            else if (value == 0) value = 1;

            int digitLength = std::to_string(value).length();

            if (columns_width[j] < digitLength) {
                columns_width[j] = digitLength;
            }
        }
    }

    for (int i = 0; i < m; i++) {
        if (i == 0) {
            // top left corner
            std::cout << tiles[0];
            
            for (int k = 0; k < n; k++) {
                for (int l = 0; l < (2 + columns_width[k]); l++) {
                    std::cout << tiles[4];
                }
                
                if (k != n - 1) {
                    std::cout << tiles[0];
                }
            }
            
            // top right corner
            std::cout << tiles[1];
        }
        
        std::cout << std::endl;
        
        for (int j = 0; j < n; j++) {
            int digitLength = std::to_string(data[i][j]).length();
            
            std::cout << tiles[5] << " ";
            std::cout << data[i][j];
            
            for (int l = 0; l < columns_width[j] - digitLength + 1; l++) {
                std::cout << " ";
            }
            
            if (j == (n - 1)) {
                std::cout << tiles[5];
            }
        }
        
        std::cout << std::endl;
        
        if (i == (m - 1)) {
            // bottom left corner
            std::cout << tiles[2];
            
            for (int k = 0; k < n; k++) {
                for (int l = 0; l < (2 + columns_width[k]); l++) {
                    std::cout << tiles[4];
                }
                    
                if (k != n - 1) {
                    std::cout << tiles[7];
                }
            }
            
            // bottom right corner
            std::cout << tiles[3];
        } else {
            // middle left vertical line
            std::cout << tiles[8];
            
            for (int k = 0; k < n; k++) {
                for (int l = 0; l < (2 + columns_width[k]); l++) {
                    std::cout << tiles[4];
                }
                    
                if (k != n - 1) {
                    std::cout << tiles[9];
                }
            }
            
            // middle right vertical line
            std::cout << tiles[10];
        }
    }
        
    std::cout << std::endl;
}

void Matrix::interactive_input() {
    bool requesting = true;

    while (true) {
        system("cls");
        print();
        
        int x, y;
        
        std::cout << std::endl << std::endl;

        do {
            std::string input;
            std::smatch matches;
            std::regex pattern("\\(?\\s*([0-9]+)\\s*,\\s*([0-9]+)\\s*\\)?");
            
            std::cout << "ingresa una coordenada (#,#) o 'c' para salir:";
            std::cin >> input;
            
            trim(input);
            tolowercase(input);

            if (input == "c") {
                requesting = false;
                break;
            }

            if (!std::regex_match(input, matches, pattern)) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }
            
            x = std::stoi(matches[1]);
            y = std::stoi(matches[2]);

            if (x < 0 || y < 0 || y > data.capacity() - 1 || x > data.at(0).capacity() - 1) {
                std::cout << std::endl << "[la coordenada seleccionada esta fuera de los limites de la matriz]";
                std::cout << std::endl << std::endl;
                continue;
            }

            break;
        } while (true);

        if (!requesting) {
            break;
        }
        
        int value;

        do {
            std::cout << "ingresa un valor para esa coordenada: ";
            std::cin >> value;

            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }

            break;
        } while (true);

        data[y][x] = value;
    }

    system("cls");
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

Matrix Matrix::operator -(Matrix &matrix) {
    if (size != matrix.get_size()) {
        throw std::runtime_error("matrices must have the same size");
    }

    Matrix result(size);

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            int left = data.at(i).at(j);
            int right = matrix[i][j];

            result[i][j] = left - right;
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