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
#include "math_utils.h"
#include <random>
#include <chrono>

template <typename T, typename U>
T MathUtils<T, U>::add(NumericPair<T> numbers) {
    return numbers.get_first() + numbers.get_second();
}

template <typename T, typename U>
T MathUtils<T, U>::subtract(NumericPair<T> numbers) {
    return numbers.get_first() - numbers.get_second();
}

template <typename T, typename U>
T MathUtils<T, U>::multiply(NumericPair<T> numbers) {
    return numbers.get_first() * numbers.get_second();
}

template <typename T, typename U>
T MathUtils<T, U>::divide(NumericPair<T> numbers) {
    if (numbers.get_second() == 0) {
        throw std::invalid_argument("dividend cannot be zero");
    }

    return numbers.get_first() / numbers.get_second();
}

template <typename T, typename U>
NumericPair<T> MathUtils<T, U>::random_pair(T min, T max) {
    NumericPair<T> pair;

    std::random_device rd;
    std::mt19937_64 mt(std::chrono::system_clock::now().time_since_epoch().count());

    if (std::is_integral<T>::value) {
        std::uniform_int_distribution<> dist(min, max);
        pair.set_first(dist(mt));
        pair.set_second(dist(mt));
    } else if (std::is_floating_point<T>::value) {
        std::uniform_real_distribution<> dist(min, max);
        pair.set_first(dist(mt));
        pair.set_second(dist(mt));
    }

    return pair;
}
