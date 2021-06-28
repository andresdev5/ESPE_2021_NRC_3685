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

    /**
     * actualiza la fecha con otro valor
     */
    void update(std::chrono::system_clock::time_point time_point);

    /**
     * agrega dias a la fecha
     */
    void add_days(int days);

    /**
     * obtiene el ultimo dia del mes
     */
    int last_month_day();

    /**
     * verifica si es laborable
     */
    bool is_holiday();

    /**
     * obtiene el dia de la semana
     */
    Day get_weekday();

    /**
     * obtiene el dia
     */
    int get_day();
    int get_month();
    int get_year();

private:
    int day;
    int month;
    int year;
};
