#define NOMINMAX 1

#include <iostream>
#include <limits>
#include "menu.h"
#include "menu_option.h"
#include "linked_list.h"

int main(int argc, char **argv) {
    Menu menu("Listas - menu");
    LinkedList<int> list;

    menu.add_option(MenuOption("Agregar elemento al final", [&](MenuOptionArguments args) {
        int value;

        do {
            std::cout << "ingrese un valor: ";
            std::cin >> value;

            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }

            break;
        } while (true);

        list.push_back(value);
        std::cout << "[elemento agregado]" << std::endl;
    }));

    menu.add_option(MenuOption("Agregar elemento al inicio", [&](MenuOptionArguments args) {
        int value;

        do {
            std::cout << "ingrese un valor: ";
            std::cin >> value;

            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }

            break;
        } while (true);

        list.push_front(value);
        std::cout << "[elemento agregado]" << std::endl;
    }));

    menu.add_option(MenuOption("Eliminar elemento", [&](MenuOptionArguments args) {
        if (list.empty()) {
            std::cout << "[lista vacia]" << std::endl << std::endl;
            system("pause");
            return;
        }

        Menu items_menu("Seleccione el elemento a eliminar: ");

        list.for_each([&](int element, int index) {
            MenuOptionArguments arguments;
            arguments.add("index", index);

            MenuOption option(std::to_string(index) + ": " + std::to_string(element), [&](MenuOptionArguments args) {
                list.remove_at(args.get<int>("index"));
                items_menu.stop();

                std::cout << "[elemento eliminado]" << std::endl;
            }, arguments);

            items_menu.add_option(option);
        });

        items_menu.add_option(MenuOption("regresar", [&](MenuOptionArguments args) {
            items_menu.stop();
        }, false));

        items_menu.display();
    }, false));

    menu.add_option(MenuOption("Buscar elemento", [&](MenuOptionArguments args) {
        int value;

        if (list.empty()) {
            std::cout << "[lista vacia]" << std::endl << std::endl;
            return;
        }

        do {
            std::cout << "ingrese un valor: ";
            std::cin >> value;

            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }

            break;
        } while (true);

        int found_index;
        Node<int> *found = list.find([&](int element, int index) {
            found_index = index;
            return value == element;
        });

        if (found == nullptr) {
            std::cout << "elemento no encontrado" << std::endl;
        } else {
            std::cout << "elemento encontrado en la posicion " << found_index << std::endl;
        }
    }));

    menu.add_option(MenuOption("Imprimir lista", [&](MenuOptionArguments args) {
        if (list.empty()) {
            std::cout << "[lista vacia]" << std::endl << std::endl;
            return;
        }

        list.for_each([](int element) {
            std::cout << element << " -> ";
        });

        std::cout << "NULL";
    }));

    menu.add_option(MenuOption("salir", [&](MenuOptionArguments args) {
        std::cout << "bye bye" << std::endl;
        menu.stop();
    }, false));

    menu.display(); 
}

