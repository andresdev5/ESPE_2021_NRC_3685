cmake_minimum_required(VERSION 3.0.0)
project(amortization_app VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 14)

# agregamos la librer�a GoogleTest C++
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

#include(CTest)
enable_testing()

add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")

file(GLOB_RECURSE PROJECT_SOURCES "include/*.h" "src/*.cpp")

include_directories("${PROJECT_SOURCE_DIR}/include")
include_directories("${PROJECT_SOURCE_DIR}/external/date/include")
include_directories("${PROJECT_SOURCE_DIR}/external/decimal/include")
include_directories("${PROJECT_SOURCE_DIR}/external/sqlite3/include")
include_directories("${PROJECT_SOURCE_DIR}/external/sqlite_orm/include")
link_directories("${PROJECT_SOURCE_DIR}/external/sqlite3/lib")

find_package(fmt PATHS "${PROJECT_SOURCE_DIR}/external/fmt/lib/cmake/fmt")
include_directories("${PROJECT_SOURCE_DIR}/external/fmt/include")

add_executable(amortization_app main.cpp ${SQLITE3_SOURCES} ${PROJECT_SOURCES})

target_link_libraries(amortization_app fmt::fmt-header-only sqlite3)

target_precompile_headers(amortization_app
    PUBLIC
        "${PROJECT_SOURCE_DIR}/include/pch.hpp"
)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

if(NOT EXISTS "${CMAKE_CURRENT_BINARY_DIR}/database.sqlite")
    add_custom_command(
        TARGET amortization_app POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
                "${PROJECT_SOURCE_DIR}/database.sqlite"
                "${CMAKE_CURRENT_BINARY_DIR}/database.sqlite")
endif()

if(NOT EXISTS "${CMAKE_CURRENT_BINARY_DIR}/wkhtmltopdf.exe")
    add_custom_command(
        TARGET amortization_app POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
                "${PROJECT_SOURCE_DIR}/bin/wkhtmltopdf.exe"
                "${CMAKE_CURRENT_BINARY_DIR}/wkhtmltopdf.exe")
endif()

if(NOT EXISTS "${CMAKE_CURRENT_BINARY_DIR}/wkhtmltopdf.exe")
    add_custom_command(
        TARGET amortization_app POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
                "${PROJECT_SOURCE_DIR}/bin/wkhtmltox.dll"
                "${CMAKE_CURRENT_BINARY_DIR}/wkhtmltox.dll")
endif()

#add_subdirectory("${PROJECT_SOURCE_DIR}/tests")
set(APP_TEST_NAME ${CMAKE_PROJECT_NAME}_test)

#file(GLOB_RECURSE TEST_SOURCES LIST_DIRECTORIES false *.h *.cpp)
set(TEST_SOURCES
    tests/person_test.cpp
    tests/date_test.cpp
    tests/input_test.cpp
)

set(SOURCES ${TEST_SOURCES})

enable_testing()

add_executable(
  ${APP_TEST_NAME} 
  ${TEST_SOURCES}
)
target_link_libraries(
  ${APP_TEST_NAME} 
  gtest_main
)

include(GoogleTest)
gtest_discover_tests(${APP_TEST_NAME})

find_package(Doxygen)

if (DOXYGEN_FOUND)
    set(DOXYGEN_PROJECT_NAME "Amortization App")
    set(DOXYGEN_RECURSIVE TRUE)
    set(DOXYGEN_IN ${PROJECT_SOURCE_DIR}/Doxyfile)
    set(DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile.doxygen)
    set(DOXYGEN_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/docs/doxygen")

    doxygen_add_docs(doxygen
        "\"${PROJECT_SOURCE_DIR}/include\" \"${PROJECT_SOURCE_DIR}/src\""
        WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/docs)
    
    #configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)

    add_custom_target(doc_doxygen ALL
        COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
        COMMENT "Generating API documentation with Doxygen"
        VERBATIM )
endif()