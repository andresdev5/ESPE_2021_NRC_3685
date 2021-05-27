#include "Taylor.h"
#include <iostream>
#include <math.h>
#include <cstdlib>
#include <limits>

int main(int, char**) {
    int opcion;

    do {
        system("cls");
        std::cout << "1: raiz cuadrada ()" << std::endl;
        std::cout << "2: sin ()" << std::endl;
        std::cout << "3: cos ()" << std::endl;
        std::cout << "4: tan ()" << std::endl;
        std::cout << "5: pi" << std::endl;
        std::cout << "6: salir" << std::endl;
        std::cout << std::endl;

        do {
            std::cout << "ingresa una opcion: ";
            std::cin >> opcion;
            if (std::cin.fail()) {
                std::cin.clear();
            }
        } while (opcion < 1 || opcion >6);

        switch (opcion){
            case 1: {
            
            }
            break;
            case 2: {
                //funcion sin
                double pi = M_PI;
                double resultado = Taylor::calcular_sin(3.14,4);
                std::cout << resultado << std::endl;
            }
            break;
        }
        if (opcion != 6) {
            system("pause");
        }
    } while (opcion != 6);
    
}
