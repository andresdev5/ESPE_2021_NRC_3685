#include "application.h"
#include <iostream>
#include <limits>
#include <cstdlib>
#include "matrix.h"
#include "user.h"
#include "person.h"
#include "circulo.h"
#include "vector.h"

Application &Application::get_instance() {
    static auto &&instance = Application();
    return instance;
}

void Application::run() {
    int opcion;

    // run menu
    do {
        system("cls");
        std::cout << "Sobrecarga de operadores ejemplos" << std::endl << std::endl;
        std::cout << "1: matrices (+, -, ~)" << std::endl;
        std::cout << "2: usuarios (==, !=, <, >)" << std::endl;
        std::cout << "3: clase persona (&, &&, &=)" << std::endl;
        std::cout << "4: clase circulo (*, /, +=)" << std::endl;
        std::cout << "5: clase vector (*=, %=, ())" << std::endl;
        std::cout << "6: salir" << std::endl;
        std::cout << std::endl;

        do {
            std::cout << "ingresa una opcion: ";
            std::cin >> opcion;

            if (opcion < 1 || opcion > 6) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        } while (opcion < 1 || opcion > 6);

        switch (opcion) {
            case 1: {
                Matrix matrix_a(2);
                Matrix matrix_b(2);

                matrix_a.interactive_input();
                matrix_b.interactive_input();

                std::cout << "matriz A:" << std::endl;
                matrix_a.print();

                std::cout << std::endl << "matriz B:" << std::endl;
                matrix_b.print();
                
                std::cout << std::endl << "matriz A + B:" << std::endl;
                Matrix result = matrix_a + matrix_b;
                result.print();

                std::cout << std::endl << "matriz A - B:" << std::endl;
                result = matrix_a - matrix_b;
                result.print();

                std::cout << std::endl << "matriz A (transpuesta):" << std::endl;
                Matrix transpose = ~matrix_a;
                transpose.print();
            }
            break;
            case 2: {
                std::string identify_card;
                std::string name;
                int age;

                User user_1;
                User user_2;

                std::cout << "(usuario 1) ingrese la cedula: ";
                std::cin >> identify_card;

                std::cout << "(usuario 1) ingrese el nombre: ";
                std::cin >> name;

                std::cout << "(usuario 1) ingrese la edad: ";
                std::cin >> age;

                user_1.set_identify_card(identify_card);
                user_1.set_name(name);
                user_1.set_age(age);

                std::cout << "(usuario 2) ingrese la cedula: ";
                std::cin >> identify_card;

                std::cout << "(usuario 2) ingrese el nombre: ";
                std::cin >> name;

                std::cout << "(usuario 2) ingrese la edad: ";
                std::cin >> age;

                user_2.set_identify_card(identify_card);
                user_2.set_name(name);
                user_2.set_age(age);

                std::cout << std::endl << std::endl;

                if (user_1 != user_2) {
                    std::cout << "los usuarios ingresados son diferentes" << std::endl;
                }
                
                if (user_1 == user_2) {
                    std::cout << "los usuarios ingresados son iguales" << std::endl;
                }

                if (user_1 > user_2) {
                    std::cout << "el usuario 1 es mayor al usuario 2" << std::endl;
                } else if (user_1 < user_2) {
                    std::cout << "el usuario 1 es menor al usuario 2" << std::endl;
                } else {
                    std::cout << "los 2 usuarios tienen la misma edad" << std::endl;
                }
            }
            break;
            case 3: {
                std::string name;
                std::string last_name_1;
                std::string last_name_2;

                Person person_1;
                Person person_2;

                std::cout << "(persona 1) ingrese su nombre: ";
                std::cin >> name;

                std::cout << "(persona 1) ingrese su primer apellido: ";
                std::cin >> last_name_1;

                std::cout << "(persona 1) ingrese su segundo apellido: ";
                std::cin >> last_name_2;

                person_1.set_name(name);
                person_1.set_last_name_1(last_name_1);
                person_1.set_last_name_2(last_name_2);

                std::cout << "(persona 2) ingrese su nombre: ";
                std::cin >> name;

                std::cout << "(persona 2) ingrese su primer apellido: ";
                std::cin >> last_name_1;

                std::cout << "(persona 2) ingrese su segundo apellido: ";
                std::cin >> last_name_2;

                person_2.set_name(name);
                person_2.set_last_name_1(last_name_1);
                person_2.set_last_name_2(last_name_2);

                std::cout << "////////////////////////// Datos ///////////////////////" << std::endl;

                std::cout << "(persona 1) El Primer apellido es: " << person_1.operator&(person_1) << std::endl;
                std::cout << "(persona 1) El segundo apellido es: " << person_1.operator&&(person_1) << std::endl;
                std::cout << "(persona 1) Apellidos: " << person_1.operator&=(person_1) << std::endl;

                std::cout << "(persona 2) El Primer apellido es: " << person_2.operator&(person_2) << std::endl;
                std::cout << "(persona 2) El segundo apellido es: " << person_2.operator&&(person_2) << std::endl;
                std::cout << "(persona 2) Apellidos: " << person_2.operator&=(person_2) << std::endl;
            }
            break;
            case 4: {
                double diametro,radio;
                Circulo circulo1;                
                Circulo circulo2;  
                Circulo circulo3;                             
                double area = 0.0;    
                
                cout << "Ingrese el diametro 1: " << endl;
                cin >> diametro;
                cout << "Ingrese el radio 1: " << endl;
                cin >> radio;
                
                circulo1.setDiametro(diametro);  
                circulo1.setRadio(radio); 

                cout << "Ingrese el diametro 2: " << endl;
                cin >> diametro;
                cout << "Ingrese el radio 2: " << endl;
                cin >> radio;
                
                circulo2.setDiametro(diametro);  
                circulo2.setRadio(radio); 
                
                
                area = circulo1.getArea();
                cout << "El area del circulo 1 es : " << area <<endl;
            
                area = circulo2.getArea();
                cout << "El area del circulo 2 es : " << area <<endl;
                

                circulo3 = circulo1 * circulo2;


                area = circulo3.getArea();
                
                cout << "Area del circulo 3 Operador multiplicacion : " << area <<endl;
                
                circulo3 = circulo1 / circulo2;
                area = circulo3.getArea();
                cout << "Area del circulo 3 Operador Division : " << area <<endl;
                
                circulo3 += circulo2;
                area = circulo3.getArea();
                cout << "Area  del circulo 3 Operador (Asignacion suma) : " << area <<endl;
            }
            case 5: {
                double vector1_x1, vector1_x2, vector1_x3;
                double vector2_x1, vector2_x2, vector2_x3;

                std::cout << "ingresa el valor de x1 (vector 1): ";
                std::cin >> vector1_x1;

                std::cout << "ingresa el valor de x2 (vector 1): ";
                std::cin >> vector1_x2;

                std::cout << "ingresa el valor de x3 (vector 1): ";
                std::cin >> vector1_x3;

                std::cout << "ingresa el valor de x1 (vector 2): ";
                std::cin >> vector2_x1;

                std::cout << "ingresa el valor de x2 (vector 2): ";
                std::cin >> vector2_x2;

                std::cout << "ingresa el valor de x3 (vector 2): ";
                std::cin >> vector2_x3;

                Vector vector1(vector1_x1, vector1_x2, vector1_x3);
                Vector vector2(vector2_x1, vector2_x2, vector2_x3);

                double producto_punto = (vector1 %= vector2);
                Vector producto_cruz = (vector1 *= vector2);

                std::cout << "producto punto: " << producto_punto << std::endl;
                std::cout << "producto cruz: (" 
                    << producto_cruz.getX1() << ", " << producto_cruz.getX2()
                    << "," << producto_cruz.getX3() << ")" << std::endl;

                if (!vector1()) {
                    std::cout << "el vector 1 esta vacio" << std::endl;
                } else {
                    std::cout << "el vector 1 no esta vacio" << std::endl;
                }

                if (!vector2()) {
                    std::cout << "el vector 2 esta vacio" << std::endl;
                } else {
                    std::cout << "el vector 2 no esta vacio" << std::endl;
                }
            }
        }

        if (opcion != 6) {
            std::cout << std::endl << std::endl;
            system("pause");
        }
    } while (opcion != 6);
}
