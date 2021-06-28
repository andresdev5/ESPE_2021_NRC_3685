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
    void run();

    /**
     * obtiene una instancia de un controlador
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
     * Registra los servicios del contenedor
     */
    void register_dependencies();
    std::map<std::string, Controller *> controllers_;
    //std::map<std::string, Service> services_;
};
