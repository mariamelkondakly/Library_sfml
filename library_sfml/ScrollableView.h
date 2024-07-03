#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

class Scrollable {
public:
    static sf::View view;
    static sf::RenderWindow* window;
    static float upperBound;
    static float lowerBound;

    static void handleScroll(sf::Event event);
    static void init(sf::RenderWindow* win, float upper);
    static void resetView();
    static void setLowerBound(float lower);
};

static void setLowerBound(float lower);
