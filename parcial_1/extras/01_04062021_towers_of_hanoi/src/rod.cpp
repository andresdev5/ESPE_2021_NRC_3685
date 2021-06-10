#include "rod.h"

Rod::Rod(std::string name) : name(name) {
    base.setFillColor(sf::Color(35, 39, 41));
    pillar.setFillColor(sf::Color(35, 39, 41));

    base.setSize(sf::Vector2f(310, 25));
    pillar.setSize(sf::Vector2f(15, 325));
}

void Rod::add_disk(Disk *disk) {
    disks.push_back(disk);
}

Disk *Rod::remove_disk() {
    if (disks.empty()) {
        return nullptr;
    }

    Disk *disk = disks.at(disks.size() - 1);
    disks.pop_back();
    return disk;
}

void Rod::clear() {
    for (Disk *disk : disks) {
        delete disk;
    }

    disks.clear();
}

void Rod::set_position(sf::Vector2f position) {
    this->position = position;
}

sf::Vector2f Rod::get_size() {
    return sf::Vector2f(base.getSize().x, base.getSize().y + pillar.getSize().y);
}

std::string Rod::get_name() {
    return name;
}

void Rod::draw(sf::RenderWindow *window) {
    sf::Vector2f pillar_position(position.x + (base.getSize().x / 2 - pillar.getSize().x / 2), position.y);
    sf::Vector2f base_position(position.x, position.y + pillar.getSize().y);

    pillar.setPosition(pillar_position);
    base.setPosition(base_position);

    window->draw(pillar);
    window->draw(base);

    int i = 0;
    int total_disks = disks.size();

    if (total_disks == 0) {
        return;
    }

    float margin = ((310 - 20) / total_disks) / 2;

    for (Disk *disk : disks) {
        sf::Vector2f disk_position = disk->get_position();

        disk->set_position(sf::Vector2f(
            pillar.getPosition().x - (disk->get_size().x / 2) + (15 / 2),
            base.getPosition().y - (5 * (i + 1)) - (32.5 * (i + 1)) + 1
        ));

        disk->draw(window);
        i++;
    }
}

std::ostream &operator<<(std::ostream &os, const Rod &rod) {
    return os << rod.name;
}
