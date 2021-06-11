#include "menu_option.h"

MenuOption::MenuOption(std::string label, MenuOptionCallback callback) {
    this->label = label;
    this->callback = callback;
}

MenuOption::MenuOption(std::string label, MenuOptionCallback callback, bool wait_after_exec) {
    this->label = label;
    this->callback = callback;
    this->wait_after_exec = wait_after_exec;
}

std::string MenuOption::get_label() {
    return label;
}

void MenuOption::execute() {
    callback();
}

bool MenuOption::should_wait() {
    return wait_after_exec;
}