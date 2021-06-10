#include "disk.h"

Disk::Disk(sf::Vector2f size) : size(size) {
    // 36.25 = (base del pilar - 20) / total de discos
    // 32.5 = (alto del pilar) / total de discos
    shape.setSize(size);
    shape.setFillColor(sf::Color::Red);
    shape.setOutlineColor(sf::Color(200, 214, 229));
    shape.setOutlineThickness(3);
}

void Disk::draw(sf::RenderWindow *window) {
    window->draw(shape);
}

void Disk::set_position(sf::Vector2f position) {
    this->position = position;
    shape.setPosition(position);
}

sf::Vector2f Disk::get_position() {
    return position;
}

sf::Vector2f Disk::get_size() {
    return size;
}

void Disk::set_color(sf::Color color) {
    this->color = color;
    shape.setFillColor(color);
}
