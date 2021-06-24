cmake_minimum_required(VERSION 3.0.0)
project(amortization_app VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 14)

add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")

include(CTest)
enable_testing()

file(GLOB_RECURSE PROJECT_SOURCES "include/*.h" "src/*.cpp")

include_directories("${PROJECT_SOURCE_DIR}/include")
include_directories("${PROJECT_SOURCE_DIR}/external/date/include")
include_directories("${PROJECT_SOURCE_DIR}/external/decimal/include")

find_package(fmt PATHS "${PROJECT_SOURCE_DIR}/external/fmt/lib/cmake/fmt")

include_directories("${PROJECT_SOURCE_DIR}/external/fmt/include")

add_executable(amortization_app main.cpp ${PROJECT_SOURCES})

target_link_libraries(amortization_app fmt::fmt-header-only)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
