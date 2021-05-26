#pragma once

class Operation {
    public:
        /**
         * @brief suma de 2 enteros
         * 
         * @param a 
         * @param b 
         * @return int 
         */
        static int suma(int a, int b);

        /**
         * @brief suma de 3 enteros
         * 
         * @param a 
         * @param b 
         * @param c 
         * @return int 
         */
        static int suma(int a, int b, int c);

        /**
         * @brief suma de 2 flotantes
         * 
         * @param a 
         * @param b 
         * @return float 
         */
        static float suma(float a, float b);

        /**
         * @brief resta de 2 enteros
         * 
         * @param a 
         * @param b 
         * @return int 
         */
        static int resta (int a, int b);

        /**
         * @brief resta de 2 flotantes
         * 
         * @param a 
         * @param b 
         * @param c 
         * @return float 
         */
        static float resta (float a, float b);

        /**
         * @brief resta de 3 dobles
         * 
         * @param a 
         * @param b 
         * @return double 
         */
        static double resta (double a, double b, double c);

        /**
         * @brief multiplicacion de 2 enteros
         * 
         * @param a 
         * @param b 
         * @return int 
         */
        static int multiplicacion(int a, int b);

        /**
         * @brief multiplicacion de 3 flotantes
         * 
         * @param a 
         * @param b 
         * @param c 
         * @return float 
         */
        static float multiplicacion(float a, float b, float c);

        /**
         * @brief multiplicacion de 3 doubles
         * 
         * @param a 
         * @param b 
         * @param c
         * @return double 
         */
        static double multiplicacion(double a, double b, double c);

        /**
         * @brief division entre 2 enteros
         * 
         * @param a 
         * @param b 
         * @return int 
         */
        static int division (int a, int b);

        /**
         * @brief division entre 2 double
         * 
         * @param a 
         * @param b 
         * @return double 
         */
        static double division (double a, double b);

        /**
         * @brief division entre 3 double
         * 
         * @param a 
         * @param b 
         * @param c 
         * @return double 
         */
        static double division (double a, double b, double c);

        /**
         * @brief promedio de 2 enteros
         * 
         * @param a 
         * @param b 
         * @return float valor con decimal
         */
        static float promedio(float a, float b);

        /**
         * @brief promero de 3 decimal
         * 
         * @param a 
         * @param b 
         * @param c 
         * @return double valor con decimal
         */
        static double promedio(double a, double b, double c);
    
        /**
         * @brief promedio de 4 flotantes
         * 
         * @param a 
         * @param b 
         * @param c 
         * @param d 
         * @return float valor con decimal
         */
        static float promedio(float a, float b, float c , float d);
    
};
