cmake_minimum_required(VERSION 3.0.0)
project(math_functions VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 14)

include(CTest)
enable_testing()

add_executable(math_functions main.cpp math_utils.h math_utils.cpp application.cpp application.h)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
