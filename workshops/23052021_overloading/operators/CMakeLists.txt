cmake_minimum_required(VERSION 3.0.0)
project(overloading VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 14)

include(CTest)
enable_testing()

set(PROJECT_FILES
    main.cpp
    utils.h
    application.h
    application.cpp
    matrix.h
    matrix.cpp
    user.h
    user.cpp
    person.h
    person.cpp
)

add_executable(overloading ${PROJECT_FILES})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
