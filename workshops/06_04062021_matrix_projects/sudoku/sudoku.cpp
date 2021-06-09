#include "sudoku.h"
#include <algorithm>
#include <random>
#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <conio.h>

int genRandNum(int maxLimit) {
    return rand() % maxLimit;
}

Sudoku::Sudoku() {
    grid = std::vector<std::vector<int>>(9, std::vector<int>(9));
    solved_grid = std::vector<std::vector<int>>(9, std::vector<int>(9));
    positions = std::vector<int>(81, 0);
    guess = std::vector<int>(9, 0);
    initialize();
}

void Sudoku::initialize() {
    for (int i = 0; i < 81; i++) {
        positions[i] = i;
    }
    
    std::shuffle(positions.begin(), positions.end(), get_rng());

    for(int i = 0; i < 9; i++) {
        guess[i] = i + 1;
    }
    
    std::shuffle(guess.begin(), guess.end(), get_rng());

    for(int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            grid[i][j] = 0;
        }
    }
}

bool Sudoku::solve() {
    int row, col;

    if (!find_unassigned(row, col))
       return true;

    for (int num = 0; num < 9; num++) {
        if (check_safe(row, col, guess[num])) {
            this->grid[row][col] = guess[num];

            if (solve()) return true;

            this->grid[row][col] = 0;
        }
    }

    return false;
}

void Sudoku::generate() {
    solve();

    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            solved_grid[i][j] = grid[i][j];
        }
    }

    for (int i = 0; i < 81; i++) {
        int x = (positions[i]) / 9;
        int y = (positions[i]) % 9;
        int temp = grid[x][y];
        grid[x][y] = 0;

        int check = 0;
        count_solutions(check);

        if (check != 1) {
            grid[x][y] = temp;
        }
    }
}

void Sudoku::print() {
    bool show_solved = false;

    do {
        system("cls");

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (!show_solved) {
                    std::cout << grid[i][j] << " ";
                } else {
                    std::cout << solved_grid[i][j] << " ";
                }

                if (j != 8) {
                    std::cout << ", ";
                }
            }

            std::cout << std::endl;
        }

        std::cout << std::endl;
        std::cout << "presione espacio para ver u ocultar la solucion o escape para salir";

        int key = getch();

        if (key == 32) {
            show_solved = !show_solved;
        } else if (key == 27) {
            break;
        }
    } while (true);
}

bool Sudoku::find_unassigned(int &row, int &column) {
    for (row = 0; row < 9; row++) {
        for (column = 0; column < 9; column++) {
            if (grid[row][column] == 0)
                return true;
        }
    }

    return false;
}

void Sudoku::count_solutions(int &number) {
    int row, col;

    if (!find_unassigned(row, col)) {
        number++;
        return;
    }


    for (int i=0; i < 9 && number < 2; i++) {
        if (check_safe(row, col, guess[i])) {
            grid[row][col] = guess[i];
            count_solutions(number);
        }

        grid[row][col] = 0;
    }
}

bool Sudoku::exists_in_row(int row, int number) {
    for (int column = 0; column < 9; column++) {
        if (grid[row][column] == number)
            return true;
    }

    return false;
}

bool Sudoku::exists_in_column(int column, int number) {
    for (int row = 0; row < 9; row++) {
        if (grid[row][column] == number)
            return true;
    }

    return false;
}

bool Sudoku::exists_in_box(int start_row, int start_column, int number) {
    for (int row = 0; row < 3; row++) {
        for (int column = 0; column < 3; column++) {
            if (grid[row + start_row][column + start_column] == number) return true;
        }
    }

    return false;
}

bool Sudoku::check_safe(int row, int column, int number) {
    return !exists_in_row(row, number) 
        && !exists_in_column(column, number)
        && !exists_in_box(row - row % 3 , column - column % 3, number);
}

std::default_random_engine Sudoku::get_rng() {
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine rng(seed);
    return rng;
}
