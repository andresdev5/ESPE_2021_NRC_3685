#pragma once

class MathUtils {
    public:

        /**
         * @brief Calcula el seno de un angulo
         * 
         * @param angle angulo
         * @param precision total de terminos a iterarse en la serie de Taylor
         * @return double seno calculado
         */
        static double sin(double angle, int precision = 16);

        /**
         * @brief Calcula el coseno de un angulo
         * 
         * @param angle angulo
         * @param precision total de terminos a iterarse en la serie de Taylor
         * @return double coseno calculado
         */
        static double cos(double angle, int precision = 16);

        /**
         * @brief Calcula la tangente de un angulo
         * 
         * @param angle angulo
         * @param precision total de terminos a iterarse en la serie de Taylor
         * @return double tangente calculado
         */
        static double tan(double angle, int precision = 16);

        /**
         * @brief Calcula la cotangente de un angulo
         * 
         * @param angle angulo
         * @param precision total de terminos a iterarse en la serie de Taylor
         * @return double cotangente calculado
         */
        static double ctg(double angle);

        /**
         * @brief Calcula el factorial de un numero
         * 
         * @param n el numero a ser calculado
         * @return long long factorial calculado
         */
        static long long factorial(int n);

        /**
         * @brief Calcula la potencia dada una base y un exponente
         * 
         * @param base la base
         * @param exponent el exponente, puede ser negativo o positivo
         * @return double 
         */
        static double pow(double base, int exponent);

        /**
         * @brief Calcular PI con la serie de Taylor
         * 
         * @param terms cantidad de terminos a iterarse en la serie de Taylor
         * @return double 
         */
        static double pi(int terms = 99999);

        /**
         * @brief transforma un angulo en grados a radianes
         * 
         * @param angle el angulo
         * @return double los radianes transformados
         */
        static double to_radians(double angle);

        /**
         * @brief compara dos valores y regresa el mayor valor
         * 
         * @param a valor uno
         * @param b valor dos
         * @return T 
         */
        template<typename T>
        static T max(T a, T b);

        /**
         * @brief compara dos valores y regresa el menor valor
         * 
         * @param a valor uno
         * @param b valor dos
         */
        template<typename T>
        static T min(T a, T b);
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<typename T>
T MathUtils::max(T a, T b) {
    return (a > b ? a : b);
}

template<typename T>
T MathUtils::min(T a, T b) {
    return (a < b ? a : b);
}
