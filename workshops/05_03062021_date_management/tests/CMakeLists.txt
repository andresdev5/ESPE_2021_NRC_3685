set(PROJECT_FILES
    "../external/date/include/date/date.h"

    "../include/date.h"
    "../src/date.cpp"
    "../include/person.h"
    "../src/person.cpp"
    "../include/application.h"
    "../src/application.cpp"
)

add_executable(test_date_management ${PROJECT_FILES} check_date_test.cpp)
add_test(date_management test_date_management)
