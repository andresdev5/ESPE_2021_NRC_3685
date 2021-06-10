/**      
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
 * Departamento de ciencias de la computacion
 * Estructura de datos
 * Docente: Ing. Fernando Solis
 * Tema: Plantillas y genericos
 * 
 * @date 19/05/2021
 * @author Andres Jacome
 * @author Gabriel Aguirre
 * @author Dalton Arevalo
 * @author Diego Jimenez
 * @author Lizzette Zapata
 */
#pragma once
#include <type_traits>
#include <string>
#include <iostream>
#include <sstream>

template<typename T, typename = typename std::enable_if<std::is_arithmetic<T>::value, T>::type>
class NumericPair {
    public:
        NumericPair() = default;
        NumericPair(T first, T second);

        void set_first(const T first);
        T get_first();

        void set_second(const T second);
        T get_second();

        std::string to_string();

    private:
        T first = 0;
        T second = 0;
};

#include "numeric_pair.cpp"
