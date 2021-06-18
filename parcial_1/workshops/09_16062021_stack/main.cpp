#include <iostream>
#include "menu.h"
#include "stack.h"
#include "utils.h"

int main() {
    Stack<int> stack;
    Menu menu("Pila - Stack");

    menu.add_option(MenuOption("Agregar elementos (push)", [&stack] (MenuOptionArguments args) {
        do {
            int number = read_int("ingrese un numero o c para cancelar: ");

            if (number == INT_MAX) {
                break;
            }

            stack.push(number);
        } while (true);
    }));

    menu.add_option(MenuOption("Remover elemento (pop)", [&stack] (MenuOptionArguments args) {
        if (stack.empty()) {
            std::cout << "la pila esta vacia" << std::endl;
            return;
        }

        int top = stack.peek();
        stack.pop();
        std::cout << "se ha removido el elemento " << top << std::endl;
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
        if (stack.empty()) {
            std::cout << "la pila esta vacia" << std::endl;
            return;
        }

        stack.for_each([] (int element) {
            std::cout << element << std::endl;
        });
    }));

    menu.add_option(MenuOption("Salir", [&menu] (MenuOptionArguments args) {
        menu.stop();
    }, false));

    menu.display();

    return 0;
}
