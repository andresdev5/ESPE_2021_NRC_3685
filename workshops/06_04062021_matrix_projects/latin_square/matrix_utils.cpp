#include "matrix_utils.h"

template < typename T>
    static Matrix<T> generate_identity_random(Matrix<T> &sol){
        double zero = 0;
        double one = 1;
        int size = sol.get_size();
        Matrix<T>::fill(sol,zero);
        for (int i = 0; i < size; i++)
        {
            for(int j = 0; j < size; j++)
            {
                if(i==j){
                    sol.set_element(i,j,one);
                }                
            }
        }
        std::random_device rd;
        std::uniform_int_distribution<> dist(0, size-1);
        static std::mt19937_64 random_generator(std::chrono::system_clock::now().time_since_epoch().count());
        for (int i = 0; i < 20; i++)
        {
            int a = dist(random_generator);
            int b = dist(random_generator);
            if(a != b){
                interchange(sol,a,b);
            }
        }
        return sol;
    }

    static int* recorrer(int* vector, int size){
        int aux = *vector;
        for (int i = 0; i < size-1; i++)
            *(vector + i) = *(vector + i + 1); 
        *(vector + size - 1) = aux;
        return vector;
    }

    template<typename T>
    static Matrix<T> generate_kernel(Matrix<T> &kernel){
        int size = kernel.get_size();
        int *base;
        int  desfase = 0;
        for (int i = 0; i < size; i++)
        {
            *(base + i)= i;
        }
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                kernel.set_element(i,j,*(base + j) );
            }
            base = recorrer(base,size);    
        }
        return kernel;
    }

    template <typename T>
    static void interchange(Matrix<T> mat, int a, int b){
        int size = mat.get_size();
        T* aux;
        for (int i = 0; i < size; i++)
        {
            *(aux + i) = mat.get_element(a,i);
        }
        for (int i = 0; i < size; i++)
        {
            mat.set_element(a,i,mat.get_element(b,i));
            mat.set_element(b,i,*(aux + i));
        }
    }

    template <typename T>
    static Matrix<T> generate_latin_square_origin(Matrix<T> &sol){
        int siz3 = sol.get_size;
        Matrix<T> idr(siz3);
        Matrix<T> kernel(siz3);
        generate_identity_random(idr);
        generate_kernel(kernel);
        sol = MatrixUtils::multiply(kernel,idr);
        return sol;
    }

template <typename T>
Matrix<T> MatrixUtils::multiply(Matrix<T> matrixA, Matrix<T> matrixB) {
    if (matrixA.get_size() != matrixB.get_size()) {
        throw std::runtime_error("cannot multiply matrixA and matrixB, they have different size.");
    }

    int size = matrixA.get_size();
    Matrix<T> result(matrixA.get_size());

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            for (int k = 0; k < size; k++) {
                T product = matrixA.get_element(i, k) * matrixB.get_element(k, j);
                T current = result.get_element(i, j);

                result.set_element(i, j, current + product);
            }

        }
    }

    return result;
}

template <typename T>
Matrix<T> MatrixUtils::pow(Matrix<T> matrix, int exponent) {
    Matrix<T> result = matrix;

    for (int i = 0; i < exponent - 1; i++) {
        result = MatrixUtils::multiply<T>(result, matrix);
    }

    return result;
}

template <typename T>
void MatrixUtils::fill_random(Matrix<T> &matrix, int min, int max) {
    std::random_device rd;
    std::uniform_int_distribution<> dist(min, max);
    static std::mt19937_64 random_generator(std::chrono::system_clock::now().time_since_epoch().count());

    int size = matrix.get_size();

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matrix.set_element(i, j, dist(random_generator));
        }
    }
}



template <typename T>
void MatrixUtils::fill(Matrix<T> &matrix, T value) {
    int size = matrix.get_size();

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matrix.set_element(i, j, value);
        }
    }
}

template <typename T>
void MatrixUtils::interactive_input(Matrix<T> &matrix) {
    bool requesting = true;
    int size = matrix.get_size();

    while (true) {
        system("cls");
        print_matrix(matrix);

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

            if (x < 0 || y < 0 || y > size - 1 || x > size - 1) {
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

        matrix.set_element(y, x, value);
    }

    system("cls");
}

template <typename T>
void MatrixUtils::print_matrix(Matrix<T> matrix) {
    int m = matrix.get_size();
    int n = matrix.get_size();

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
    T **data = matrix.get_data();

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
