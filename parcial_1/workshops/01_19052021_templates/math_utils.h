/**      
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
 * Departamento de ciencias de la computación
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
#include <stdexcept>
#include "numeric_pair.h"

template<typename T, typename = typename std::enable_if<std::is_arithmetic<T>::value, T>::type>
class MathUtils {
    public:
        /**
         * @brief suma dos numeros y regresa el resultado
         * 
         * @param addend1 sumando uno
         * @param addend2 sumando dos
         * @return T resultado de la suma de addend1 y addend2
         */
        static T add(NumericPair<T> numbers);

        /**
         * @brief resta dos numeros y regresa el resultado
         * 
         * @param minuend minuendo
         * @param subtrahend substraendo
         * @return T resultado de la resta de minuend y subtrahend
         */
        static T subtract(NumericPair<T> numbers);

        /**
         * @brief multiplica dos numeros y regresa el resultado
         * 
         * @param multiplicand multiplicando
         * @param multiplier multiplicador
         * @return T resultado de la multiplicacion de number1 y number2
         */
        static T multiply(NumericPair<T> numbers);

        /**
         * @brief divide dos numeros y regresa el resultado, si el segundo parametro
         * es cero arroja una excepcion.
         * 
         * @param divisor divisor
         * @param dividend dividendo
         * @return T resultado de dividir divisor con dividend
         */
        static T divide(NumericPair<T> numbers);

        /**
         * @brief obtiene un par de numeros aleatorio
         * 
         * @return T instancia de NumericPair
         */
        static NumericPair<T> random_pair(T min, T max);
};

#include "math_utils.cpp"
