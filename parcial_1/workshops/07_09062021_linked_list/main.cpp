#include <iostream>
#include "menu.h"
#include "menu_option.h"
#include "linked_list.h"

int main(int, char**) {
    Menu menu("Listas - menu");
    LinkedList<int> list;

    list.push_back(5);
    list.push_back(10);
    list.push_back(15);

    menu.add_option(MenuOption("Eliminar elemento", [&](MenuOptionArguments args) {
        if (list.empty()) {
            std::cout << "lista vacia" << std::endl << std::endl;
            system("pause");
            return;
        }

        Menu items_menu("Seleccione el elemento a eliminar: ");

        list.for_each([&](int element, int index) {
            MenuOptionArguments arguments;
            arguments.add("index", index);

            MenuOption option(std::to_string(index) + " " + std::to_string(element), [&](MenuOptionArguments args) {
                list.remove_at(args.get<int>("index"));
                items_menu.stop();

                std::cout << "elemento eliminado" << std::endl;
            }, arguments);

            items_menu.add_option(option);
        });

        items_menu.add_option(MenuOption("regresar", [&](MenuOptionArguments args) {
            items_menu.stop();
        }, false));

        items_menu.display();
    }, false));

    menu.add_option(MenuOption("Agregar elemento", [](MenuOptionArguments args) {
        std::cout << "[no implementado aun]" << std::endl;
    }));

    menu.add_option(MenuOption("Agregar elemento por cola", [](MenuOptionArguments args) {
        std::cout << "[no implementado aun]" << std::endl;
    }));

    menu.add_option(MenuOption("Buscar elemento", [](MenuOptionArguments args) {
        std::cout << "[no implementado aun]" << std::endl;
    }));

    menu.add_option(MenuOption("Imprimir lista", [](MenuOptionArguments args) {
        std::cout << "[no implementado aun]" << std::endl;
    }));

    menu.add_option(MenuOption("salir", [&](MenuOptionArguments args) {
        std::cout << "bye bye" << std::endl;
        menu.stop();
    }, false));

    menu.display(); 
}
