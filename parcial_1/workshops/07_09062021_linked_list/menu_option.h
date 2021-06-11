#pragma once
#include <string>
#include <functional>
#include <map>

typedef std::function<void()> MenuOptionCallback;

class MenuOption {
public:
    MenuOption(std::string label, MenuOptionCallback callback);
    MenuOption(std::string label, MenuOptionCallback callback, bool wait_after_exec);
    std::string get_label();
    void execute();
    bool should_wait();

private:
    std::string label;
    std::function<void()> callback;
    bool wait_after_exec = true;
};
