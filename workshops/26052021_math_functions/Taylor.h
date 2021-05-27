#pragma once

class Taylor
{
public:
/**
 * @brief funcion que calcula la funcion de seno de un numero x con aproximacion por serie de taylor centrada en cero
 * 
 * @param x 
 * @param grado 
 * @return double 
 */
    static double calcular_sin(double x, int grado);

/**
 * @brief funcion que calcula la funcion factorial de un numero n
 * 
 * @param n 
 * @return double 
 */
    static double calcular_factorial(double n); 

/**
 * @brief funcion que devuelve 1 o -1 si n es par o impar
 * 
 * @param n 
 * @return double 
 */
    static double calcular_signo(double n);
};

