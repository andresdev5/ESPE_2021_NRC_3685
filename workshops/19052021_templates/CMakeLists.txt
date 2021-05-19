cmake_minimum_required(VERSION 3.0.0)
project(math_template VERSION 0.1.0)

set(CXX_STANDARD 14)
set(CXX_STANDARD_REQUIRED 14)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(CTest)
enable_testing()
ADD_SUBDIRECTORY(tests)

add_executable(math_template main.cpp math_utils.h math_utils.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
