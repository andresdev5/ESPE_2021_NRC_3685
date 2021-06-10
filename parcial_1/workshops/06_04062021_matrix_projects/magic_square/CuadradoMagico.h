/***********************************************************************
 * Module:  CuadradoMagico.h
 * Author:  lizzette zapata
 * Modified: lunes, 7 de junio de 2021 21:45:22
 * Purpose: Declaration of the class CuadradoMagico
 ***********************************************************************/

#if !defined(__Class_Diagram_1_CuadradoMagico_h)
#define __Class_Diagram_1_CuadradoMagico_h

class CuadradoMagico {

public:
	
	CuadradoMagico();

	void crearCuadrado(int size);
	void imprimir();

private:

	int *cuadrado;
	int size;

	void fillSinglyEven();
	void fillDoubleEven();
	void fillOdd();
	void siamese(int from, int to);


};
#endif