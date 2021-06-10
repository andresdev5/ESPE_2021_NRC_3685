cmake_minimum_required(VERSION 3.0.0)
project(matrix VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 14)

include(CTest)
enable_testing()

include_directories("${PROJECT_SOURCE_DIR}/include")

set(PROJECT_FILES
    "include/utils.h"
    "include/matrix.h"
    "include/matrix_utils.h"
)

add_executable(matrix src/main.cpp ${PROJECT_FILES})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
