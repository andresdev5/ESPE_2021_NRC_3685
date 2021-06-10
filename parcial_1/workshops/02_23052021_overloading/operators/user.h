#pragma once
#include <string>

class User {
    public:
        User() = default;
        User(std::string identify_card, std::string name, int age);

        /**
         * @brief operador condicional para comparar 2 usuarios
         * 
         * @param user 
         * @return true en caso de que 2 usuarios sean iguales
         * @return false en caso de que 2 usuarios sean diferentes
         */
        bool operator ==(User &user);

        /**
         * @brief operador "distinto de" para comparar 2 usuarios
         * 
         * @param user 
         * @return true en caso de que 2 usuarios sean diferentes
         * @return false en caso de que 2 usuarios sean iguales
         */
        bool operator !=(User &user);

        /**
         * @brief operador "mayor que" para comparar usuario por edad
         * 
         * @param user usuario a compararse
         * @return true en caso de que el usuario sea mayor en edad
         * @return false en caso de que el usuario sea menor en edad
         */
        bool operator >(User &user);

        /**
         * @brief operador "menor que" para comparar usuarios por edad
         * 
         * @param user 
         * @return true en caso de que el usuario sea menor en edad
         * @return false en caso de que el usuario sea mayor en edad
         */
        bool operator <(User &user);
        
        void set_identify_card(std::string identify_card);
        std::string get_identify_card();

        void set_name(std::string name);
        std::string get_name();

        void set_age(int age);
        int get_age();

    private:
        std::string identify_card = "";
        std::string name = "";
        int age = 0;
};
