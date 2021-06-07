#define SFML_STATIC 1
#include "application.h"
#include "utils.h"
#include "imgui.h"
#include "imgui_stdlib.h"
#include "imgui-SFML.h"
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>
#include <iostream>
#include <string>

Application::Application() {
    settings.antialiasingLevel = 2;

    this->window = new sf::RenderWindow(
        sf::VideoMode(1024, 580), "Torres de Hanoi", (sf::Style::Titlebar | sf::Style::Close), settings);

    window->setVerticalSyncEnabled(true);

    for (int size = total_disks; size >= 1; size--) {
        utils::Rgb rgb = utils::random_color();

        sf::Color color(rgb.red, rgb.green, rgb.blue);
        // x = (base del pilar - 20) / total de discos
        // y = (alto del pilar) / total de discos
        sf::Vector2f disk_size(((310 - 20) / total_disks) * size, 270 / 8);

        Disk *disk = new Disk(disk_size);
        disk->set_color(color);

        rod_a->add_disk(disk);
    }
}

void Application::run() {
    hanoi_solver(total_disks, rod_a, rod_c, rod_b);

    ImGui::SFML::Init(*window);
    sf::Clock deltaClock;

    std::string total_disks_str;
    bool open = true;

    sf::Vector2f rod_size = rod_a->get_size();

    rod_a->set_position(sf::Vector2f(25, 190));
    rod_b->set_position(sf::Vector2f(25 + rod_size.x + 25, 190));
    rod_c->set_position(sf::Vector2f(25 + (rod_size.x * 2) + (25 * 2), 190));

    int ui_total_disks = total_disks;

    sf::Time dt;
    sf::Time elapsed_time;
    sf::Clock clock;
    bool resolving = false;
    float speed = 50.f;

    while (window->isOpen()) {
        sf::Event event;

        elapsed_time += clock.getElapsedTime();
        dt = clock.getElapsedTime();
        clock.restart();

        while (window->pollEvent(event)) {
            ImGui::SFML::ProcessEvent(event);

            if (event.type == sf::Event::Closed) {
                window->close();
            }
        }

        ImGui::SFML::Update(*window, deltaClock.restart());
        ImGui::SetNextWindowPos(ImVec2(20, 20));
        ImGui::SetNextWindowBgAlpha(0.5f);
        // ImGui::SetNextWindowSize(ImVec2(390, 120));
        ImGui::Begin("Opciones", &open,
            ImGuiWindowFlags_NoResize | ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoCollapse);
        ImGui::PushItemWidth(100);

        if (ImGui::InputInt("  Numero de discos", &ui_total_disks, 1, 100)) {
            ui_total_disks = (ui_total_disks > 8 ? 8 : (ui_total_disks < 2 ? 2 : ui_total_disks));

            if (ui_total_disks != total_disks) {
                total_disks = ui_total_disks;
                reset();
            }
        }

        ImGui::SliderFloat("Velocidad", &speed, 50.f, 700.f);

        if (ImGui::Button("iniciar/pausar", ImVec2(110, 24))) {
            resolving = !resolving;
        }

        if (resolving && !hanoi_steps.empty() && elapsed_time.asMilliseconds() > (750 - speed)) {
            auto step = hanoi_steps.front();
            Rod *from = std::get<0>(step);
            Rod *to = std::get<1>(step);

            Disk *disk = from->remove_disk();
            to->add_disk(disk);
            hanoi_steps.erase(hanoi_steps.begin());

            if (hanoi_steps.empty()) {
                resolving = false;
            }

            elapsed_time = sf::milliseconds(0);
        }

        ImGui::End();

        ImGui::SetNextWindowPos(ImVec2(580, 20));
        ImGui::SetNextWindowBgAlpha(0.5f);
        ImGui::Begin("Historial", &open,
            ImGuiWindowFlags_NoResize | ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoCollapse);
        ImGui::InputTextMultiline("Registro", &hanoi_logger, ImVec2(400, 70));
        ImGui::End();

        window->clear(sf::Color(200, 214, 229));

        rod_a->draw(window);
        rod_b->draw(window);
        rod_c->draw(window);

        ImGui::SFML::Render(*window);
        window->display();
    }
}

void Application::reset() {
    rod_a->clear();
    rod_b->clear();
    rod_c->clear();
    hanoi_steps.clear();

    for (int size = total_disks; size >= 1; size--) {
        utils::Rgb rgb = utils::random_color();

        sf::Color color(rgb.red, rgb.green, rgb.blue);
        // 36.25 = (base del pilar - 20) / total de discos
        // 32.5 = (alto del pilar) / total de discos
        sf::Vector2f disk_size(((310 - 20) / total_disks) * size, 270 / 8);

        Disk *disk = new Disk(disk_size);
        disk->set_color(color);
        rod_a->add_disk(disk);
    }

    hanoi_solver(total_disks, rod_a, rod_c, rod_b);
}

void Application::hanoi_solver(int n, Rod *from_rod, Rod *to_rod, Rod *aux_rod) {
    if (n == 1) {
        std::cout << "Se ha movido el disco 1 desde " << from_rod->get_name() << " hasta " << to_rod->get_name() << std::endl;
        hanoi_steps.push_back(std::make_tuple(from_rod, to_rod));

        return;
    }

    hanoi_solver(n - 1, from_rod, aux_rod, to_rod);

    std::cout << "Se ha movido el disco " << n << " desde " << from_rod->get_name() << " hasta " << to_rod->get_name() << std::endl;
    hanoi_steps.push_back(std::make_tuple(from_rod, to_rod));

    /*hanoi_steps.push_back([&]() {
        Disk *disk = from_rod->remove_disk();
        to_rod->add_disk(disk);
    });*/

    hanoi_solver(n - 1, aux_rod, to_rod, from_rod);
}

