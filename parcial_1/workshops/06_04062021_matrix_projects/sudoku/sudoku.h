#pragma once
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

using matrix_t = std::vector<std::vector<int>>;

class Sudoku {
public:
	Sudoku();
	void generate();
	void print();

private:
	void initialize();
	bool solve();
	void count_solutions(int &number);
	bool find_unassigned(int &row, int &column);
	bool check_safe(int row, int column, int num);
	bool exists_in_row(int row, int number);
	bool exists_in_column(int column, int number);
	bool exists_in_box(int start_row, int start_column, int number);
	std::default_random_engine get_rng();

	matrix_t grid;
	matrix_t solved_grid;
	std::vector<int> guess;
	std::vector<int> positions;
    std::default_random_engine rng;
};
