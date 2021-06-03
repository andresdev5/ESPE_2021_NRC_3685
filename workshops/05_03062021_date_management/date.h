/***********************************************************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
 * Departamento de Ciencias de la Computacion
 * Estructura de Datos
 * Docente: Ing. Fernando Solis
 * Tema: Manejo de Fechas
 * Module:  date.h
 * Modified: jueves, 3 de junio de 2021 12:44:18
 * Purpose: Declaration of the class date
 * Author
 * @date 03/06/2021
 * @author Andres Jacome
 * @author Gabriel Aguirre
 * @author Dalton Arevalo
 * @author Diego Jimenez
 * @author Lizzette Zapata
 ***********************************************************************/

#if !defined(__Class_Diagram_1_Fecha_h)
#define __Class_Diagram_1_Fecha_h

class Date
{
public:
   int getDay(void);
   void setDay(int newDay);
   int getMonth(void);
   void setMonth(int newMonth);
   int getYear(void);
   void setYear(int newYear);
   Date(int _day, int _month, int _year);
   ~Date();

protected:
private:
   int day;
   int month;
   int year;


};

#endif