#pragma once
#include <SFML/Graphics.hpp>

class Disk {
public:
    Disk(sf::Vector2f size);
    void draw(sf::RenderWindow *window);
    void set_color(sf::Color color);
    void set_position(sf::Vector2f position);
    sf::Vector2f get_position();
    sf::Vector2f get_size();

private:
    sf::RectangleShape shape;
    sf::Color color;
    sf::Vector2f position = sf::Vector2f(0, 0);
    sf::Vector2f size;
};
