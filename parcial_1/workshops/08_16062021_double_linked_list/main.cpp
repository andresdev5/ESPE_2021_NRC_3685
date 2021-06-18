#include <iostream>
#include "doubly_linked_list.h"
#include "utils.h"
#include <limits>
#include <windows.h>

int main(int argc, char **argv) {
    DoublyLinkedList<int> list;

    do {
        int number = read_int("ingrese un numero o c para cancelar: ");

        if (number == INT_MAX) {
            break;
        }

        list.push_back(number);
    } while (true);

    std::cout << "lista: " << std::endl  << std::endl;

    list.for_each([] (int value) {
        std::cout << value << std::endl;
    });
}
