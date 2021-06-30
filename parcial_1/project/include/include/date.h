#pragma once
#include <chrono>
#include <string>

enum class Day { Monday = 1, Thuesday = 2, Wednesday = 3, Thursday = 4, Friday = 5, Saturday = 6, Sunday = 7 };

class Date {
public:
    Date();
    Date(int day, int month, int year);

    /**
     * @brief obtiene la fecha actual
     * @return 
     */
    static Date current();

    /**
     * @brief obtiene la fecha actual del sistema
     * @return 
     */
    static std::chrono::system_clock::time_point system_now();

    /**
     * @brief lee una fecha
     * @param label prompt para mostrar al usuario
     * @return fecha leida formateada
     */
    static Date read(std::string label);

    /**
     * @brief verifica si una fecha es valida
     * @param day dia
     * @param month mes
     * @param year año
     * @return true si es valida, false si es invalida
     */
    static bool is_valid(int day, int month, int year);

    /**
     * @brief transforma la fecha a una estructura time_point
     * @return 
    */
    std::chrono::system_clock::time_point to_time_point();

    /**
     * @brief actualiza la fecha con otro valor
     */
    void update(std::chrono::system_clock::time_point time_point);

    /**
     * @brief agrega dias a la fecha
     */
    void add_days(int days);

    /**
     * @brief obtiene el ultimo dia del mes
     */
    int last_month_day();

    /**
     * @brief verifica si es laborable
     */
    bool is_holiday();

    /**
     * @brief obtiene el dia de la semana
     */
    Day get_weekday();

    /**
     * @brief obtiene el dia
     */
    int get_day();

    /**
     * @brief obtiene el mes
     */
    int get_month();

    /**
     * @brief obtiene el año
     */
    int get_year();

private:
    int day;
    int month;
    int year;
};
