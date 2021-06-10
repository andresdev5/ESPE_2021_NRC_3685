#pragma once
#include <chrono>
#include <string>

enum class Day { Monday = 1, Thuesday = 2, Wednesday = 3, Thursday = 4, Friday = 5, Saturday = 6, Sunday = 7 };

class Date {
public:
    Date();
    Date(int day, int month, int year);
    static Date current();
    static std::chrono::system_clock::time_point system_now();
    static Date read(std::string label);
    static bool is_valid(int day, int month, int year);

    std::chrono::system_clock::time_point to_time_point();
    void update(std::chrono::system_clock::time_point time_point);
    void add_days(int days);
    int last_month_day();
    bool is_holiday();
    Day get_weekday();
    int get_day();
    int get_month();
    int get_year();

private:
    int day;
    int month;
    int year;
};
