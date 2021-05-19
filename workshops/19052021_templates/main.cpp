/**      
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
 * Departamento de ciencias de la computación
 * Estructura de datos
 * Docente: Ing. Fernando Solis
 * Tema: Plantillas y genericos
 * 
 * @since 19/05/2021
 * @author Andres Jacome
 * @author Gabriel Aguirre
 * @author Dalton Arevalo
 * @author Diego Jimenez
 * @author Lizzette Zapata
 */
#include <iostream>
#include "math_utils.h"

int main(int argc, char **argv) {
    int addend1 = 3;
    int addend2 = 2;
    int add_result = MathUtils<int>::add(addend1, addend2);

    std::cout << addend1 << " + " << addend2 << " = " << add_result << std::endl;
    
    float minuend = 5.5;
    float subtrahend = 1.5;
    float subtract_result = MathUtils<float>::subtract(minuend, subtrahend);

    std::cout << minuend << " - " << subtrahend << " = " << subtract_result << std::endl;

    double multiplicand = 2.444444449;
    double multiplier = 2.2;
    double multiply_result = MathUtils<double>::multiply(multiplicand, multiplier);

    std::cout << multiplicand << " * " << multiplier << " = " << multiply_result << std::endl;

    float divisor = 10;
    float dividend = 2;
    float divide_result = MathUtils<float>::divide(divisor, dividend);

    std::cout << divisor << " / " << dividend << " = " << divide_result << std::endl;

    return 0;
}
