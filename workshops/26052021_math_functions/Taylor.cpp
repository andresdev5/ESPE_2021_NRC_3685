#include "Taylor.h"
#include <math.h>
#include <stdexcept>

double Taylor::calcular_factorial(double n){
    if (n < 2){
        return 1;
    }
    else{
        return n*calcular_factorial(n--);
    }
    
}

double Taylor::calcular_signo(double n){
    return pow(-1.0,n);
}

double Taylor::calcular_sin(double x, int grado){
    double suma = 0;
    for (int i = 0; i < grado; i++)
    {
        double factorial = Taylor::calcular_factorial(2*i + 1);
        double signo = Taylor::calcular_signo(i);
        
        suma += signo * pow(x,2*i +1) / factorial;
    }
    return suma;
}