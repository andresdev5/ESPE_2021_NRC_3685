/**      
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
 * Departamento de ciencias de la computacion
 * Estructura de datos
 * Docente: Ing. Fernando Solis
 * Tema: Plantillas y genericos
 * 
 * @date 19/05/2021
 * @author Andres Jacome
 * @author Gabriel Aguirre
 * @author Dalton Arevalo
 * @author Diego Jimenez
 * @author Lizzette Zapata
 */
#include "application.h"
#include "math_utils.h"
#include <iostream>
#include <tuple>

Application &Application::get_instance() {
    static auto &&instance = Application();
    return instance;
}

void Application::run() {
    std::cout << std::endl;

    // run operations
    for (int i = 1; i <= 4; i++) {
        NumericPair<int> int_pair = MathUtils<int>::random_pair(0, 100);
        NumericPair<float> float_pair = MathUtils<float>::random_pair(200.0, 300.0);
        NumericPair<double> double_pair = MathUtils<double>::random_pair(10.0, 50.0);
        int int_result;
        float float_result;
        float double_result;
        std::tuple<std::string, std::string> operation_info;

        switch (i) {
            case 1:
                int_result = MathUtils<int>::add(int_pair);
                float_result = MathUtils<float>::add(float_pair);
                double_result = MathUtils<double>::add(double_pair);
                operation_info = std::make_tuple("add", "+");
            break;
            case 2:
                int_result = MathUtils<int>::subtract(int_pair);
                float_result = MathUtils<float>::subtract(float_pair);
                double_result = MathUtils<double>::subtract(double_pair);
                operation_info = std::make_tuple("subtract", "-");
            break;
            case 3:
                int_result = MathUtils<int>::multiply(int_pair);
                float_result = MathUtils<float>::multiply(float_pair);
                double_result = MathUtils<double>::multiply(double_pair);
                operation_info = std::make_tuple("multiply", "*");
            break;
            case 4:
                int_result = MathUtils<int>::divide(int_pair);
                float_result = MathUtils<float>::divide(float_pair);
                double_result = MathUtils<double>::divide(double_pair);
                operation_info = std::make_tuple("divide", "/");
            break;
        }

        std::cout << "int " << std::get<0>(operation_info) << " operation: " << std::endl;
        std::cout << int_pair.to_string() << std::endl;
        std::cout << int_pair.get_first() << " " + std::get<1>(operation_info) + " "
            << int_pair.get_second() 
            << " = " << int_result << std::endl << std::endl;

        std::cout << "float " << std::get<0>(operation_info)  << " operation: " << std::endl;
        std::cout << float_pair.to_string() << std::endl;
        std::cout << float_pair.get_first() << " " + std::get<1>(operation_info) + " "
            << float_pair.get_second() 
            << " = " << float_result << std::endl << std::endl;

        std::cout << "double " << std::get<0>(operation_info)  << " operation: " << std::endl;
        std::cout << double_pair.to_string() << std::endl;
        std::cout << double_pair.get_first() << " " + std::get<1>(operation_info) + " "
            << double_pair.get_second() 
            << " = " << double_result << std::endl << std::endl;

        std::cout << "-----------------------------------------------" << std::endl << std::endl;
    }
}
