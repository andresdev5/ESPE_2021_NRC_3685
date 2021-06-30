#include <gtest/gtest.h>
#include <string>
#include "../include/utils.h"

TEST(InputTest, CheckPersonId) {
    std::string id = "1726744293";

    EXPECT_TRUE(is_person_id_valid(id));
}

TEST(InputText, CheckIsNumeric) {
    std::string numeric = "1501";

    EXPECT_TRUE(is_numeric(numeric));
}
