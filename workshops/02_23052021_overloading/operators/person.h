#pragma once
#include <iostream>
#include <string>

class Person{
    public:
        Person() = default;
        Person(std::string name, std::string last_name_1, std::string last_name_2);

        /**
         * @brief operador para mostrar primer apellido
         * 
         * @param person
         * @return el primer apellido
         */
        std::string operator &(Person &person);

        /**
         * @brief operador para mostrar segundo apellido
         * 
         * @param person
         * @return el segundo apellido
         */
        std::string operator &&(Person &person);

        /**
         * @brief operador para mostrar los 2 apellidos
         * 
         * @param person
         * @return primer apellido y segundo apellido
         */
        std::string operator &=(Person &person);

        void set_name(std::string name);
        std::string get_name();

        void set_last_name_1(std::string last_name_1);
        std::string get_last_name_1();

        void set_last_name_2(std::string last_name_2);
        std::string get_last_name_2();

    private:
        std::string name;
        std::string last_name_one = "";
        std::string last_name_two = "";
};
