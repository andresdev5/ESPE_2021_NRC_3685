cmake_minimum_required(VERSION 3.0.0)
project(date_management VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 14)

include(CTest)
enable_testing()

include_directories("${PROJECT_SOURCE_DIR}/include")
include_directories("${PROJECT_SOURCE_DIR}/external/date/include")

add_definitions(-DUSE_SHELL_API=1)

set(PROJECT_FILES
    "external/date/include/date/date.h"

    "include/date.h"
    "src/date.cpp"
    "include/person.h"
    "src/person.cpp"
    "include/application.h"
    "src/application.cpp"
)

add_executable(date_management src/main.cpp ${PROJECT_FILES})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
