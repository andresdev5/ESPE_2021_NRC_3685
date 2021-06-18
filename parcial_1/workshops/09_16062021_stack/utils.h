#pragma once
#include <string>
#include <iostream>
#include <limits>
#include <algorithm>

static inline int is_numeric(std::string str) {
    return !str.empty() && std::find_if(str.begin(), 
        str.end(), [](unsigned char c) {
            return !std::isdigit(c);
    }) == str.end();
}

static inline void tolowercase(std::string &str) {
    std::transform(str.begin(), str.end(), str.begin(), [] (unsigned char c) {
        return std::tolower(c);
    });
}

inline int read_int(std::string label, int min = INT_MIN, int max = INT_MAX) {
    std::string input;
    int output;

    do {
        std::cout << label;
        std::cin >> input;

        tolowercase(input);

        if (input == "c") {
            return INT_MAX;
        }

        if (std::cin.fail() || !is_numeric(input)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        output = std::stoi(input);

        if (output < min || output > max) {
            continue;
        }

        break;
    } while (true);

    return output;
}
