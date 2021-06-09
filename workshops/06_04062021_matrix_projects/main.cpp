#include <iostream>
#include <cstdlib>
#include "application.h"

int main(int argc, char **argv) {
    Application::get_instance().run();
}
