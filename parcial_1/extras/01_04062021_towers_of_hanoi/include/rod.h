#pragma once
#include "disk.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

class Rod {
public:
    Rod(std::string name);

    void add_disk(Disk *disk);
    Disk *remove_disk();
    void clear();
    void draw(sf::RenderWindow *window);

    void set_position(sf::Vector2f position);
    sf::Vector2f get_size();
    std::string get_name();

    friend std::ostream &operator<<(std::ostream &os, const Rod &rod);

private:
    std::string name;
    std::vector<Disk *> disks;
    sf::RectangleShape base;
    sf::RectangleShape pillar;
    sf::Vector2f position = sf::Vector2f(0, 0);
};
