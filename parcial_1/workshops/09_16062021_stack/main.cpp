#include <iostream>
#include "menu.h"
#include "stack.h"

int main() {
    Stack<int> stack;
    Menu menu("Pila - Stack");

    menu.add_option(MenuOption("Agregar elemento (push)", [&stack] (MenuOptionArguments args) {
        
    }));

    menu.add_option(MenuOption("Remover elemento (pop)", [&stack] (MenuOptionArguments args) {
        if (stack.empty()) {
            std::cout << "la pila esta vacia" << std::endl;
            return;
        }

        stack.pop();
        std::cout << "se ha removido un elemento" << std::endl;
    }));

    menu.add_option(MenuOption("Obtener elemento (peek/top)", [&stack] (MenuOptionArguments args) {
        try {
            int element = stack.peek();
            std::cout << "se ha obtenido el elemento " << element << std::endl;
        } catch (std::exception exception) {
            std::cerr << "Error: no se puede obtener un elemento de una pila vacia" << std::endl;
        }
    }));

    menu.add_option(MenuOption("Imprimir pila (print)", [&stack] (MenuOptionArguments args) {
        
    }));

    menu.add_option(MenuOption("Salir", [&menu] (MenuOptionArguments args) {
        menu.stop();
    }, false));

    menu.display();

    return 0;
}
