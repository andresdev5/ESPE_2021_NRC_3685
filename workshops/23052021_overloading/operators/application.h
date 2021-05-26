/**      
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
 * Departamento de ciencias de la computacion
 * Estructura de datos
 * Docente: Ing. Fernando Solis
 * Tema: Plantillas y genericos
 * 
 * @date 19/05/2021
 * @author Andres Jacome
 * @author Gabriel Aguirre
 * @author Dalton Arevalo
 * @author Diego Jimenez
 * @author Lizzette Zapata
 */
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
