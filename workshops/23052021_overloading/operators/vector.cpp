#include "vector.h"

Vector::Vector(double x1, double x2, double x3){
    this->x1 = x1;
    this->x2 = x2;
    this->x3 = x3;
}

double Vector::getX1(){
    return x1;
}

double Vector::getX2(){
    return x2;
}

double Vector::getX3(){
    return x3;
}
void Vector:: setX1(double x1){
    this->x1 = x1;
}

void Vector:: setX2(double x2){
    this->x2 = x2;
}

void Vector:: setX3(double x3){
    this->x3 = x3;
}

//operador producto punto
double Vector::operator %=(Vector &v){
    return this->x1 * v.getX1() + this->x2 * v.getX2() + this->x3 * v.getX3();
}

//operador producto cruz
Vector Vector::operator *=(Vector &v) {
    Vector aux;

    aux.setX1(this->getX2() * v.getX3() - this->getX3() * v.getX2());
    aux.setX2(this->getX1() * v.getX3() - this->getX3() * v.getX1());
    aux.setX3(this->getX1() * v.getX2() - this->getX2() * v.getX1());
    
    return aux;
}

//operador unario que devuelve falso si esta vacio
bool Vector::operator ()() {
    if(this->getX1() == 0 && this->getX2() ==0 && this->getX3() == 0 ) {
        return false;
    } else {
        return true;
    }
}
