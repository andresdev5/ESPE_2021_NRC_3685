cmake_minimum_required(VERSION 3.0.0)
project(linkedlist VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 14)

include(CTest)
enable_testing()

add_executable(linkedlist node.h linked_list.h double_linked_list.h menu_option.h menu_option.cpp menu.h menu.cpp main.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
