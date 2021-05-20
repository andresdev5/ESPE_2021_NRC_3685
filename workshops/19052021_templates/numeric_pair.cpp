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
#include "numeric_pair.h"

template <typename T, typename U>
NumericPair<T, U>::NumericPair(T first, T second) {
    this->first = first;
    this->second = second;
}

template <typename T, typename U>
T NumericPair<T, U>::get_first() {
    return first;
}

template <typename T, typename U>
void NumericPair<T, U>::set_first(T first) {
    this->first = first;
}

template <typename T, typename U>
T NumericPair<T, U>::get_second() {
    return second;
}

template <typename T, typename U>
void NumericPair<T, U>::set_second(T second) {
    this->second = second;
}

template <typename T, typename U>
std::string NumericPair<T, U>::to_string() {
    return "{ first: " + std::to_string(first) 
        + ", second: " + std::to_string(second) + "}";
}
