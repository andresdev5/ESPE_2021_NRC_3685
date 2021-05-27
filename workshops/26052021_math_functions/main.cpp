#include <iostream>
#include "application.h"

int main(int, char**) {
    Application::get_instance().run();
    return 0;
}
