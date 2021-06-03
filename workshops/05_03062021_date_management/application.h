/***********************************************************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
 * Departamento de Ciencias de la Computacion
 * Estructura de Datos
 * Docente: Ing. Fernando Solis
 * Tema: Manejo de Fechas
 * Module: application.h
 * Modified: jueves, 3 de junio de 2021 12:44:18
 * Purpose: Declaration of the class application
 * Author
 * @date 03/06/2021
 * @author Andres Jacome
 * @author Gabriel Aguirre
 * @author Dalton Arevalo
 * @author Diego Jimenez
 * @author Lizzette Zapata
 ***********************************************************************/
#pragma once

class Application {
    public:
        static Application &get_instance();
        void run();
    
    private:
        Application() = default;
        Application(const Application &) = default;
        void operator=(const Application &) = delete;
        Application(Application &&) noexcept = default;
        Application &operator=(Application &&) noexcept = default;

        static Application *instance;
};
