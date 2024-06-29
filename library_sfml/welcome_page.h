#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include "Materials.h"

using namespace std;
using namespace sf;

class welcome_page
{
public:
    buttons sign_up_button, log_in_button;
    bool visible = true;
    texts libraryName;
    welcome_page();
    void draw_starting_page(RenderWindow& window);
};

