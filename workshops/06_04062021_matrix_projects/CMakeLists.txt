cmake_minimum_required(VERSION 3.0.0)
project(matrix_projects VERSION 0.1.0)

include(CTest)
enable_testing()

set(SUDOKU_FILES
    "sudoku/sudoku.h"
    "sudoku/sudoku.cpp"
    "pascal_triangle/operation.h"
    "pascal_triangle/operation.cpp"
    "pascal_triangle/matrix.h"
    "pascal_triangle/matrix.cpp"
    "application.h"
    "application.cpp"
    "magic_square/CuadradoMagico.h"
    "magic_square/CuadradoMagico.cpp"
)

add_executable(matrix_projects main.cpp ${SUDOKU_FILES})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
