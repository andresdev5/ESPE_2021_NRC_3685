#include "math_utils.h"
#include <iostream>

double MathUtils::sin(double angle, int precision) {
    double radians = MathUtils::to_radians(angle);
    double suma = 0;

    for (int i = 0; i < precision; i++) {
        long long factorial = MathUtils::factorial(2 * i + 1);
        suma += (MathUtils::pow(-1, i) * pow(radians, 2 * i +1)) / factorial;
    }
    
    return suma;
}

double MathUtils::cos(double angle, int precision) {
    double radians = MathUtils::to_radians(angle);
    precision = MathUtils::max(1, precision);
    double output = 0;

    for (int i = 0; i < precision; i++) {
        double numerator = MathUtils::pow(-1, i) * MathUtils::pow(radians, 2 * i);
        double denominator = MathUtils::factorial(2 * i);
        double result = (numerator / denominator);
        output += result;
    }

    return output;
}

double MathUtils::tan(double angle, int precision) {
    double radians = MathUtils::to_radians(angle);
    
    double radians_sen = radians;
    double radians_cos = radians;

    double numerator = 0;
    double denominator = 0;

    double output;

    for (int i = 0; i < precision; i++) {
        long long factorial = MathUtils::factorial(2 * i + 1);
        numerator += (MathUtils::pow(-1, i) * pow(radians_sen, 2 * i +1)) / factorial;
    }

    for (int i = 0; i < precision; i++) {
        double numerator_for_cos = MathUtils::pow(-1, i) * MathUtils::pow(radians_cos, 2 * i);
        double denominator_for_cos = MathUtils::factorial(2 * i);
        double result = (numerator_for_cos / denominator_for_cos);
        denominator += result;
    }
    
    output = numerator / denominator;

    return output;
}

double MathUtils::ctg(double angle) {
    
}

double MathUtils::pow(double base, int exponent) {
    double temp;

    if (exponent == 0) {
        return 1;
    }

    temp = MathUtils::pow(base, exponent / 2);

    if ((exponent % 2) == 0) {
        return temp * temp;
    } else {
        if (exponent > 0) {
            return base * temp * temp;
        } else {
            return (temp * temp) / base;
        }
    }
}

double MathUtils::pi(int terms) {
    double sum = 0.0;
    int sign = 1;

    for (int i = 0; i < terms; ++i) {           
        sum += sign / (2.0 * i + 1.0);
        sign *= -1;
    }
    
    return 4.0 * sum;
}

double MathUtils::to_radians(double angle) {
    return (angle * MathUtils::pi()) / 180;
}

long long MathUtils::factorial(int n) {
    if (n <= 1) {
        return 1;
    }

    return (n * factorial(n - 1));
}
