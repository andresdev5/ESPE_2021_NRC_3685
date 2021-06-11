#include "menu.h"
#include <conio.h>

Menu::Menu() {
    console = GetStdHandle(STD_OUTPUT_HANDLE);
}

Menu::Menu(std::string title) {
    this->title = title;
    console = GetStdHandle(STD_OUTPUT_HANDLE);
}

void Menu::add_option(MenuOption option) {
    options.push_back(option);
}

void Menu::display() {
    int selected = 1;

    if (options.empty()) {
        return;
    }

    CONSOLE_SCREEN_BUFFER_INFO csbi;
    WORD csbi_defaults;

    GetConsoleScreenBufferInfo(console, &csbi);
    csbi_defaults = csbi.wAttributes;

    running = true;

    while (running) {
        int position = 1;
        
        system("cls");

        std::cout << title << std::endl << std::endl;

        for (MenuOption option : options) {
            if (position++ == selected) {
                SetConsoleTextAttribute (console, BACKGROUND_BLUE);
            }

            std::cout << option.get_label() << std::endl;
            SetConsoleTextAttribute (console, csbi_defaults);
        }

        int key;

        do {
            key = getch();

            if (key == 0) {
                key = getch();
            }
        } while (key != KEY_UP && key != KEY_DOWN && key != KEY_ENTER);
        
        switch (key) {
            case KEY_UP: {
                selected--;

                if (selected < 1) {
                    selected = options.size() - 1;
                }
            }
            break;
            case KEY_DOWN: {
                selected++;

                if (selected > options.size()) {
                    selected = 1;
                }
            }
            break;
            case KEY_ENTER: {
                MenuOption option = options.at(selected - 1);
                std::cout << std::endl << std::endl;
                option.execute();

                if (option.should_wait()) {
                    std::cout << std::endl << std::endl;
                    system("pause");
                }
            }
        }
    }
}

void Menu::stop() {
    running = false;
}

bool Menu::is_running() {
    return running;
}