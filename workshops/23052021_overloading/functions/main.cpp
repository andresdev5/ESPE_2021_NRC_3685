#include <iostream>
#include <cstdlib>
#include <limits>
#include "operation.h"

int main(int, char**) {
    int opcion;

    do {
        system("cls");
        std::cout << "1: suma" << std::endl;
        std::cout << "2: resta" << std::endl;
        std::cout << "3: multiplicacion" << std::endl;
        std::cout << "4: division" << std::endl;
        std::cout << "5: promedio" << std::endl;
        std::cout << "6: salir" << std::endl;
        std::cout << std::endl;

        do {
            std::cout << "ingresa una opcion: ";
            std::cin >> opcion;

            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        } while (opcion < 1 || opcion > 6);

        switch (opcion) {
            case 1: {
                int entero_1;
                int entero_2;
                int entero_3;
                float flotante_1;
                float flotante_2;

                std::cout << "ingresa un entero: ";
                std::cin >> entero_1;

                std::cout << "ingresa otro entero: ";
                std::cin >> entero_2;

                std::cout << "ingresa otro entero: ";
                std::cin >> entero_3;

                std::cout << "ingresa un decimal: ";
                std::cin >> flotante_1;

                std::cout << "ingresa otro decimal: ";
                std::cin >> flotante_2;

                int resultado_1 = Operation::suma(entero_1, entero_2);
                int resultado_2 = Operation::suma(entero_1, entero_2, entero_3);
                float resultado_3 = Operation::suma(flotante_1, flotante_2);

                std::cout << std::endl;

                std::cout << "Operation::suma(" << entero_1 << ", " << entero_2 << ") = " 
                    << resultado_1 << std::endl;
                    
                std::cout << "Operation::suma(" << entero_1 << ", " << entero_2 << ", " << entero_3 << ") = " 
                    << resultado_2 << std::endl;
                
                std::cout << "Operation::suma(" << flotante_1 << ", " << flotante_2 << ") = " 
                    << resultado_3 << std::endl;
            }
            break;
            case 2: {
                // resta
            }
            break;
            case 3: {
                int entero_1;
                int entero_2;
                float flotante_1;
                float flotante_2;
                float flotante_3;
                double doble_1;
                double doble_2;
                double doble_3;

                std::cout << "ingresa un entero: ";
                std::cin >> entero_1;

                std::cout << "ingresa otro entero: ";
                std::cin >> entero_2;

                std::cout << "(float) ingresa un decimal: ";
                std::cin >> flotante_1;

                std::cout << "(float) ingresa otro decimal: ";
                std::cin >> flotante_2;

                std::cout << "(float) ingresa otro decimal: ";
                std::cin >> flotante_3;

                std::cout << "(double) ingrese un decimal: ";
                std::cin >> doble_1;

                std::cout << "(double) ingrese un decimal: ";
                std::cin >> doble_2;

                std::cout << "(double) ingrese un decimal: ";
                std::cin >> doble_3;

                int resultado_1 = Operation::multiplicacion(entero_1, entero_2);
                float resultado_2 = Operation::multiplicacion(flotante_1, flotante_2, flotante_3);
                double resultado_3 = Operation::multiplicacion(doble_1, doble_2, doble_3);

                std::cout << std::endl;

                std::cout << "Operation::multiplicacion(" << entero_1 << ", " << entero_2 << ") = " 
                    << resultado_1 << std::endl;
                    
                std::cout << "Operation::multiplicacion(" << flotante_1 << ", " << flotante_2 << ", " << flotante_3 << ") = " 
                    << resultado_2 << std::endl;
                
                std::cout << "Operation::multiplicacion(" << doble_1 << ", " << doble_2 << ", " << doble_3 << ") = " 
                    << resultado_3 << std::endl;
            }
            break;
            case 4: {
                // division
            }
            break;
            case 5: {
                double decimal_1;
                double decimal_2;
                double decimal_3;
                float flotante_1;
                float flotante_2;
                float flotante_3;
                float flotante_4;

                std::cout << "ingresa el primer numero decimal: ";
                std::cin >> decimal_1;

                std::cout << "ingresa el segundo numero decimal: ";
                std::cin >> decimal_2;

                std::cout << "ingresa el tercer  numero decimal: ";
                std::cin >> decimal_3;

                std::cout << "ingresa el primer numero flotante: ";
                std::cin >> flotante_1;

                std::cout << "ingresa el segundo numero flotante: ";
                std::cin >> flotante_2;

                std::cout << "ingresa el tercer numero flotante: ";
                std::cin >> flotante_3;

                std::cout << "ingresa el cuarto numero flotante: ";
                std::cin >> flotante_4;

                float resultado_1 = Operation::promedio(flotante_1, flotante_2);
                double resultado_2 = Operation::promedio(decimal_1, decimal_2, decimal_3);
                float resultado_3 = Operation::promedio(flotante_1, flotante_2, flotante_3, flotante_4);

                std::cout << std::endl;

                std::cout << "Operation::promedio(" << flotante_1 << ", " << flotante_2 << ") = " 
                    << resultado_1 << std::endl;
                    
                std::cout << "Operation::promedio(" << decimal_1 << ", " << decimal_2 << ", " << decimal_3 << ") = " 
                    << resultado_2 << std::endl;
                
                std::cout << "Operation::promedio(" << flotante_1 << ", " << flotante_2 << ", " << flotante_3 << ", " << flotante_4 << ") = " 
                    << resultado_3 << std::endl;
            }
            break;
        }

        if (opcion != 6) {
            system("pause");
        }
    } while (opcion != 6);
}
