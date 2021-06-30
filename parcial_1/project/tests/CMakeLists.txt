set(APP_TEST_NAME ${CMAKE_PROJECT_NAME}_test)

#file(GLOB_RECURSE TEST_SOURCES LIST_DIRECTORIES false *.h *.cpp)
set(TEST_SOURCES
    person_test.cpp
    date_test.cpp
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

#add_test(NAME ${APP_TEST_NAME} COMMAND ${APP_TEST_NAME})

include(GoogleTest)
gtest_discover_tests(${APP_TEST_NAME})