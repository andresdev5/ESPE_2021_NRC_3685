#include <gtest/gtest.h>
#include "../include/date.h"
#include "../src/date.cpp"

TEST(DateTest, HolidayCheck) {
    Date date(25, 12, 2021);

    EXPECT_TRUE(date.is_holiday());
}

TEST(DateTest, AddDaysCheck) {
    Date date(15, 01, 1993);
    date.add_days(3);

    EXPECT_EQ(date.get_day(), 18);
}
