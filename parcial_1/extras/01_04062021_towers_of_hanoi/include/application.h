#pragma once
#include "disk.h"
#include "rod.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <functional>
#include <vector>
#include <tuple>
#include <sstream>

class Application {
public:
    Application();
    void run();
    void reset();
    void hanoi_solver(int n, Rod *from_rod, Rod *to_rod, Rod *aux_rod);

private:
    sf::ContextSettings settings;
    sf::RenderWindow *window;
    sf::Clock deltaClock;
    Rod *rod_a = new Rod("Torre A");
    Rod *rod_b = new Rod("Torre B");
    Rod *rod_c = new Rod("Torre C");
    int total_disks = 8;
    std::vector<std::tuple<Rod *, Rod *>> hanoi_steps;
    std::string hanoi_logger;
    std::stringstream hanoi_logger_stream;
};
