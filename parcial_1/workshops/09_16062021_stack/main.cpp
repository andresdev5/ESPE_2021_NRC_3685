#include <iostream>
#include "menu.h"
#include "stack.h"

int main() {
    Stack<int> stack;
    Menu menu("Pila - Stack");

    menu.add_option(MenuOption("Agregar elemento (push)", [] (MenuOptionArguments args) {

    }));

    menu.add_option(MenuOption("Remover elemento (pop)", [] (MenuOptionArguments args) {
        
    }));

    menu.add_option(MenuOption("Obtener elemento (peek/top)", [] (MenuOptionArguments args) {
        
    }));

    menu.add_option(MenuOption("Imprimir pila (print)", [] (MenuOptionArguments args) {
        
    }));

    menu.add_option(MenuOption("Salir", [&menu] (MenuOptionArguments args) {
        menu.stop();
    }, false));

    menu.display();

    return 0;
}
