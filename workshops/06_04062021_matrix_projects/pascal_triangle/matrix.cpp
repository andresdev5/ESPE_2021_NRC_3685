/***********************************************************************
 * Module:  matrix.cpp
 * Author:  DALTON AREVALO
 * Modified: domingo, 6 de junio de 2021 14:47:18
 * Purpose: Implementation of the class matrix
 ***********************************************************************/

#include "Matrix.h"

////////////////////////////////////////////////////////////////////////
// Name:       Matrix::Matrix()
// Purpose:    Implementation of Matrix::Matrix()
// Return:     
////////////////////////////////////////////////////////////////////////

Matrix::Matrix(){

}

////////////////////////////////////////////////////////////////////////
// Name:       Matrix::~Matrix()
// Purpose:    Implementation of Matrix::~Matrix()
// Return:     
////////////////////////////////////////////////////////////////////////

Matrix::~Matrix() {
	// TODO : implement
}

////////////////////////////////////////////////////////////////////////
// Name:       Matrix::set_dimension(int newDimension)
// Purpose:    Implementation of Matrix::set_dimension()
// Parameters:
// - newDimension
// Return:     void
////////////////////////////////////////////////////////////////////////

void Matrix::set_dimension(int _dimension){
	this->dimension = _dimension;
}

////////////////////////////////////////////////////////////////////////
// Name:       Matrix::get_dimension()
// Purpose:    Implementation of Matrix::get_dimension()
// Return:     dimension
////////////////////////////////////////////////////////////////////////

int  Matrix::get_dimension(){
	return dimension;
}





