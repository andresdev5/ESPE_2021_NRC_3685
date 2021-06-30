#pragma once
#include "linked_list.h"
#include "person.h"
#include "controller.h"
#include <map>
#include <type_traits>

class Controller;

class Application {
public:
    Application();

    /**
     * @brief inicializa la aplicacion
     */
    void run();

    /**
     * @brief obtiene una instancia de un controlador
     * @tparam T la clase del controlador a obtener
     * @param key el nombre con el que se registro el controlador
     * @return instancia del controlador registrado
     */
    template <typename T, typename std::enable_if<std::is_base_of<Controller, T>::value>::type* = nullptr>
    T *get_controller(std::string key) {
        if (controllers_.find(key) == controllers_.end()) {
            throw std::runtime_error(std::string("cannot find controller registered with key ") + key);
        }

        return static_cast<T*>(controllers_[key]);
    }

private:
    /**
     * @brief Registra los servicios del contenedor
     */
    void register_dependencies();

    /**
     * @brief coleccion para los controladores, la clave es un alias y el valor una instancia
     */
    std::map<std::string, Controller *> controllers_;
    //std::map<std::string, Service> services_;
};
