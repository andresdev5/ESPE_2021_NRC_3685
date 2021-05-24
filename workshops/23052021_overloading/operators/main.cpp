#include <iostream>
#include "application.h"

int main(int argc, char **argv) {
    Application::get_instance().run();
    return 0;
}
