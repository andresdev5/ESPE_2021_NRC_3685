cmake_minimum_required(VERSION 3.0.0)
project(TowersOfHanoi VERSION 0.1.0)

include(FetchContent)

set(CMAKE_CXX_STANDARD 14)
set(SFML_STATIC 1)
set(SFML_DIR "${PROJECT_SOURCE_DIR}/external/SFML")

add_compile_definitions(SFML_STATIC)

include_directories(${SFML_DIR}/include)

include(CTest)
enable_testing()

add_executable(TowersOfHanoi main.cpp)

target_link_directories(TowersOfHanoi PUBLIC "${SFML_DIR}/lib")
target_link_libraries(TowersOfHanoi
    PUBLIC
        sfml-window-s
        sfml-system-s
        sfml-graphics-s
        opengl32
        winmm
        gdi32
)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
