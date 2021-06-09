/* ********************************************************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
 * Departamento de Ciencias de la Computación
 * Estructura de Datos
 * Docente: Ing. Fernando Solis
 * Tema: Triangulo de Pascal
 * Módulo: operation.h
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
class Operation
{
public:
	/**
	* @brief segmentar
	*
	* @param 
	*
	* @return matriz
	*/
	int** segmentar();

	/**
	* @brief encerar
	*
	* @param int** matriz
	*
	* @return 
	*/
	void encerar(int** matriz);

	/**
	* @brief pascal_triangle 
	*
	* @param int** matriz
	*
	* @return 
	*/
	void generate_pascal_triangle(int** matriz);

	/**
	* @brief toString 
	*
	* @param int** matriz
	*
	* @return 
	*/
	void toString(int** matriz);

	/**
	* @brief final_score 
	*
	* @param 
	*
	* @return 
	*/
	void final_score();
};

