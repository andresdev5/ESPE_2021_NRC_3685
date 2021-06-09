cmake_minimum_required(VERSION 3.0.0)
project(matrix_projects VERSION 0.1.0)

include(CTest)
enable_testing()

set(PROJECT_FILES
    "sudoku/sudoku.h"
    "sudoku/sudoku.cpp"
    "pascal_triangle/operation.h"
    "pascal_triangle/operation.cpp"
    "magic_square/CuadradoMagico.h"
    "magic_square/CuadradoMagico.cpp"
    "identity_matrix/matrix.h"
    "identity_matrix/matrix_utils.h"
    "identity_matrix/identity_matrix.h"
    "identity_matrix/identity_matrix.cpp"

    "application.h"
    "application.cpp"
)

add_executable(matrix_projects main.cpp ${PROJECT_FILES})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
