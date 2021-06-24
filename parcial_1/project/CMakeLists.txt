cmake_minimum_required(VERSION 3.0.0)
project(amortization_app VERSION 0.1.0)

include(CTest)
enable_testing()

file(GLOB_RECURSE PROJECT_SOURCES "include/*.h" "src/*.cpp")

include_directories("${PROJECT_SOURCE_DIR}/include")
include_directories("${PROJECT_SOURCE_DIR}/external/date/include")
include_directories("${PROJECT_SOURCE_DIR}/external/decimal/include")

add_executable(amortization_app main.cpp ${PROJECT_SOURCES})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
