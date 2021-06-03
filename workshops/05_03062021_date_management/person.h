/***********************************************************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
 * Departamento de Ciencias de la Computacion
 * Estructura de Datos
 * Docente: Ing. Fernando Solis
 * Tema: Manejo de Fechas
 * Module:  person.h
 * Modified: jueves, 3 de junio de 2021 12:44:18
 * Purpose: Declaration of the class person
 * Author
 * @date 03/06/2021
 * @author Andres Jacome
 * @author Gabriel Aguirre
 * @author Dalton Arevalo
 * @author Diego Jimenez
 * @author Lizzette Zapata
 ***********************************************************************/

#pragma once
#include "date.h"
#include <string>

class Person
{
public:
   std::string getName(void);
   void setName(std::string newName);
   std::string getId(void);
   void setId(std::string newId);
   Date getDate(void);
   void setDate(Date newDate);
   Person(std::string _name, std::string _id, Date _date);
   ~Person();

protected:
private:
   std::string name;
   std::string id;
   Date date;
};
