#include "circulo.h"

double Circulo::getArea(void) {
    return PI * pow ( radio, 2 );
}

double Circulo::getRadio(void) {
    return radio;
}

void Circulo::setRadio( double rad) {
    radio  = rad;
    
}
double Circulo::getDiametro(void) {
    return diametro;
}

void Circulo::setDiametro( double diam ) {
    diametro = diam;
}

Circulo Circulo::operator * (const Circulo& c) {
    Circulo circulo;
    circulo.diametro = this->diametro * c.diametro;
    circulo.radio = this->radio * c.radio;
    return circulo;
}

Circulo Circulo::operator / (const Circulo& c) {
    Circulo circulo;
    circulo.diametro = this->diametro / c.diametro;
    circulo.radio = this->radio / c.radio;
    return circulo;
}

Circulo Circulo::operator += (const Circulo& c) {
    Circulo circulo;
    circulo.diametro = this->diametro += c.diametro;
    circulo.radio = this->diametro += c.diametro;
    return circulo;
}