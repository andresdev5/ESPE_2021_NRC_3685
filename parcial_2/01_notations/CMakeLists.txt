# CMakeList.txt : CMake project for NotationExpression, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("NotationExpression")

set(PROJECT_SOURCES
    "include/pch.h"
    "src/main.cpp"
    "include/utils.h"
    "include/menu_option.h"
    "src/menu_option.cpp"
    "include/menu.h"
    "src/menu.cpp"
    "include/node.h"
    "include/doubly_linked_list.h"
    "include/stack.h"
    "include/notation_parser.h"
    "src/notation_parser.cpp"
    "include/expression.h"
    "src/expression.cpp"

)

include_directories("${PROJECT_SOURCE_DIR}/include")

# Add source to this project's executable.
add_executable (NotationExpression ${PROJECT_SOURCES})

target_precompile_headers(NotationExpression PUBLIC "include/pch.h")

# TODO: Add tests and install targets if needed.
