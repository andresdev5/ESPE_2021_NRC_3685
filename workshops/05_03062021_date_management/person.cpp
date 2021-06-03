/***********************************************************************
 * Module:  Persona.cpp
 * Author:  DALTON AREVALO
 * Modified: jueves, 3 de junio de 2021 12:44:18
 * Purpose: Implementation of the class Persona
 ***********************************************************************/

#include "person.h"
#include <string>

////////////////////////////////////////////////////////////////////////
// Name:       Persona::getNombre()
// Purpose:    Implementation of Persona::getNombre()
// Return:     std::string
////////////////////////////////////////////////////////////////////////

std::string Person::getName(void)
{
   return name;
}

////////////////////////////////////////////////////////////////////////
// Name:       Persona::setNombre(std::string newNombre)
// Purpose:    Implementation of Persona::setNombre()
// Parameters:
// - newNombre
// Return:     void
////////////////////////////////////////////////////////////////////////

void Person::setName(std::string newName)
{
   name = newName;
}

////////////////////////////////////////////////////////////////////////
// Name:       Persona::getCedula()
// Purpose:    Implementation of Persona::getCedula()
// Return:     std::string
////////////////////////////////////////////////////////////////////////

std::string Person::getId(void)
{
   return id;
}

////////////////////////////////////////////////////////////////////////
// Name:       Persona::setCedula(std::string newCedula)
// Purpose:    Implementation of Persona::setCedula()
// Parameters:
// - newCedula
// Return:     void
////////////////////////////////////////////////////////////////////////

void Person::setId(std::string newId)
{
   id = newId;
}

////////////////////////////////////////////////////////////////////////
// Name:       Persona::getFecha()
// Purpose:    Implementation of Persona::getFecha()
// Return:     Fecha
////////////////////////////////////////////////////////////////////////

Date Person::getDate(void)
{
   return date;
}

////////////////////////////////////////////////////////////////////////
// Name:       Persona::setFecha(Fecha newFecha)
// Purpose:    Implementation of Persona::setFecha()
// Parameters:
// - newFecha
// Return:     void
////////////////////////////////////////////////////////////////////////

void Person::setDate(Date newDate)
{
   date = newDate;
}

////////////////////////////////////////////////////////////////////////
// Name:       Persona::Persona(std::string _nombre, std::string _cedula, Fecha _fecha)
// Purpose:    Implementation of Persona::Persona()
// Parameters:
// - _nombre
// - _cedula
// - _fecha
// Return:     
////////////////////////////////////////////////////////////////////////

/*Person::Person(std::string _name, std::string _id, Date _date)
{
   this->name = _name;
   this->id = _id;
   this->date = _date;
}*/

////////////////////////////////////////////////////////////////////////
// Name:       Persona::~Persona()
// Purpose:    Implementation of Persona::~Persona()
// Return:     
////////////////////////////////////////////////////////////////////////

Person::~Person()
{
   // TODO : implement
}