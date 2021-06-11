#include <iostream>
#include "menu.h"
#include "menu_option.h"
#include "linked_list.h"

int main(int, char**) {
    Menu menu("Listas - menu");
    
    menu.add_option(MenuOption("Agregar elemento", []() {
        std::cout << "[no implementado aun]" << std::endl;
    }));

    menu.add_option(MenuOption("Agregar elemento por cola", []() {
        std::cout << "[no implementado aun]" << std::endl;
    }));

    menu.add_option(MenuOption("Eliminar elemento", []() {
        std::cout << "[no implementado aun]" << std::endl;
    }));

    menu.add_option(MenuOption("Buscar elemento", []() {
        std::cout << "[no implementado aun]" << std::endl;
    }));

    menu.add_option(MenuOption("Imprimir lista", []() {
        std::cout << "[no implementado aun]" << std::endl;
    }));

    menu.add_option(MenuOption("salir", [&]() {
        std::cout << "bye bye" << std::endl;
        menu.stop();
    }, false));

    menu.display(); 
}
