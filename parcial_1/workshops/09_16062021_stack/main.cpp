#include <iostream>
#include "menu.h"
#include "stack.h"

int main() {
    Stack<int> stack;
    Menu menu("Pila - Stack");

    menu.add_option(MenuOption("Agregar elemento (push)", [&stack] (MenuOptionArguments args) {

    }));

    menu.add_option(MenuOption("Remover elemento (pop)", [&stack] (MenuOptionArguments args) {
        stack.pop();
        std::cout << "se ha removido un elemento" << std::endl;
    }));

    menu.add_option(MenuOption("Obtener elemento (peek/top)", [&stack] (MenuOptionArguments args) {
        
    }));

    menu.add_option(MenuOption("Imprimir pila (print)", [&stack] (MenuOptionArguments args) {
        
    }));

    menu.add_option(MenuOption("Salir", [&menu] (MenuOptionArguments args) {
        menu.stop();
    }, false));

    menu.display();

    return 0;
}
