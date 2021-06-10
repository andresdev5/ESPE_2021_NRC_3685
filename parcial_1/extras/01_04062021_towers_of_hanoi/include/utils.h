#pragma once
#include <chrono>
#include <random>
#include <iostream>

namespace utils {

struct Rgb {
    int red;
    int green;
    int blue;
};

int random_int(int min, int max) {
    std::random_device rd;
    std::uniform_int_distribution<> dist(min, max);
    static std::mt19937_64 random_generator(
        std::chrono::system_clock::now().time_since_epoch().count());

    return dist(random_generator);
}

float random_float(float min, float max) {
    std::random_device rd;
    std::uniform_real_distribution<> dist(min, max);
    static std::mt19937_64 random_generator(
        std::chrono::system_clock::now().time_since_epoch().count());

    return dist(random_generator);
}

float hue2rgb(float p, float q, float t) {
    if(t < 0) t += 1;
    if(t > 1) t -= 1;
    if(t < 1.f / 6.f) return p + (q - p) * 6 * t;
    if(t < 1.f / 2.f) return q;
    if(t < 2.f / 3.f) return p + (q - p) * (2.f / 3.f - t) * 6;
    return p;
}

Rgb hsl2rgb(float h, float s, float l) {
    float r, g, b;

    if (s == 0) {
        r = g = b = l;
    } else {
        float p, q;

        q = (l < 0.5 ? l * (1 + s) : l + s - l * s);
		p = (2 * l - q);

        r = hue2rgb(p, q, h + (1.f/3.f));
		g = hue2rgb(p, q, h);
		b = hue2rgb(p, q, h - (1.f/3.f));
    }

    Rgb value = {
        .red = (int)std::round(r * 255),
        .green = (int)std::round(g * 255),
        .blue = (int)std::round(b * 255)
    };

    return value;
}

Rgb random_color() {
    float h = random_float(0, 1);
    float s = random_float(0.25, 0.95);
    float l = random_float(0.50, 0.80);

    Rgb rgb = hsl2rgb(h, s, l);

    return rgb;
}

};
