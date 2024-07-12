#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include "Materials.h"
#include "signup_page.h"
#include "welcome_page.h"

using namespace std;
using namespace sf;

class welcome_page
{
public:
    static buttons sign_up_button, log_in_button;
    static bool visible;
    static texts libraryName;
    welcome_page();
    static void draw_starting_page(RenderWindow& window);
    static photos logo;
    static void onWelcomeHover(Vector2f pos, welcome_page& welcome);
    static void WelcomeButtonsClicked(Vector2f pos, welcome_page& welcome);

};

