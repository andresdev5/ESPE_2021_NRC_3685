#include "operation.h"
#include <stdexcept>

int Operation::suma(int a, int b) {
    return a + b;
}

int Operation::suma(int a, int b, int c) {
    return a + b + c;
}

float Operation::suma(float a, float b) {
    return a + b;
}

int Operation:: resta (int a, int b) {
    return a - b;
}

float Operation :: resta (float a, float b) {
    return a - b;
}

double Operation :: resta (double a, double b, double c){
    return a - b - c;
}

int Operation::multiplicacion(int a, int b) {
    return a * b;
}

float Operation::multiplicacion(float a, float b, float c) {
    return a * b * c;
}

double Operation::multiplicacion(double a, double b, double c) {
    return a * (b * c);
}

int Operation::division(int a, int b) {
    if ( b == 0){
        throw std::invalid_argument("b no puede ser cero");
    }

    return a / b;
}

double Operation::division(double a, double b) {
    if ( b == 0) {
        throw std::invalid_argument("b no puede ser cero");
    }

    return a / b;
}

double Operation::division(double a, double b, double c) {
    if ( b == 0 || c == 0) {
        throw std::invalid_argument("ni b ni c pueden ser cero");
    }

    return (a / b) / c;
}

float Operation::promedio(float a, float b){
    return (a + b)/2;
}

double Operation::promedio(double a, double b, double c){
    return (a + b + c) / 3;
}

float Operation::promedio(float a, float b, float c , float d){
    return (a + b + c + d) / 4;
}