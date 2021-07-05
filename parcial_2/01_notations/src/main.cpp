#include "notation_parser.h"
#include "stack.h"
#include "menu.h"

using namespace std;

int main() {
    Menu menu("Notaciones");

    menu.add_option(MenuOption("Ingresar expresion", [](MenuOptionArguments args) {
        std::string input;
        cout << "ingrese una expresion: ";
        cin >> input;

        try {
            Expression expression(input, ExpressionType::Infix);
            NotationParser parser(expression);

            std::string postfix = parser.parse(ExpressionType::Postfix);
            std::string prefix = parser.parse(ExpressionType::Prefix);
            std::string infix = parser.parse(ExpressionType::Infix);

            cout << "infix: " << expression.content() << endl;
            cout << "postfix: " << postfix << endl;
            cout << "prefix: " << prefix << endl;
        } catch (std::exception exception) {
            cerr << "expresion invalida";
        }
    }));

    menu.add_option(MenuOption("Salir", [&](MenuOptionArguments args) {
        menu.stop();
    }, false));

    menu.display();
    
    return 0;
}
