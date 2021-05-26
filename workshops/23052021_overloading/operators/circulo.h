#pragma once
#include <iostream>
#include <math.h>   
#define PI 3.141592

using namespace std;

class  Circulo  {
	private:
      double radio;      
      double diametro;      

	public:
      double getArea(void);
      double getRadio(void);
      void setRadio( double rad);
      double getDiametro(void);
      void setDiametro( double diam );
      
      Circulo operator * (const Circulo& c);
      Circulo operator / (const Circulo& c);
      Circulo operator += (const Circulo& c);
};
