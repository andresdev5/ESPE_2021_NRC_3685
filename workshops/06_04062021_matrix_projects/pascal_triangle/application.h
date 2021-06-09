/* ********************************************************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
 * Departamento de Ciencias de la Computación
 * Estructura de Datos
 * Docente: Ing. Fernando Solis
 * Tema: Triangulo de Pascal
 * Módulo: application.h
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
