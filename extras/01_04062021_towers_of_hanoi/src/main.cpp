#define SFML_STATIC 1

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

int main() {
    sf::ContextSettings settings;
    settings.antialiasingLevel = 10;

    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!", (sf::Style::Titlebar | sf::Style::Close), settings);

    sf::RectangleShape shape(sf::Vector2f(100, 100));
    shape.setFillColor(sf::Color(52, 152, 219));
    shape.setPosition(sf::Vector2f(20, 20));

    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                shape.move(sf::Vector2f(2.0, 0));
            }
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}
