/* ********************************************************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
 * Departamento de Ciencias de la Computación
 * Estructura de Datos
 * Docente: Ing. Fernando Solis
 * Tema: Triangulo de Pascal
 * Módulo: matrix.cpp
 * Modificado: domingo 6 de junio de 2021 14:47:18
 * Objeto: Declaración de la clase matriz.
 * Autor
 * @fecha 06/06/2021
 * @autor Dalton Arévalo
 * @autor Andrés Jácome
 * @autor Gabriel Aguirre
 * @autor Diego Jiménez
 * @autora Lizzette Zapata
********************************************************************/
#pragma once

class Matrix{
	public:
		/**
		* @brief constructor vacio
		*
		* @param 
		*
		* @return
		*/
		Matrix();
		
		/**
		* @brief destructor
		*
		* @param 
		*
		* @return
		*/
		~Matrix();

		/**
		* @brief set_dimension
		*
		* @param int _dimension
		*
		* @return 
		*/
		void set_dimension(int);

		/**
		* @brief get_dimension
		*
		* @param 
		*
		* @return dimension
		*/
		int get_dimension();

	protected:

	private: 
		int dimension;
};
