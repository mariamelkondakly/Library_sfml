#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>

using namespace std;
using namespace sf;

class buttons
{
public:
	RectangleShape button;
	Text buttonText;
	buttons(int posx, int posy, string buttonName);
	void buttonDraw(RenderWindow& window);
};

class essentials {
public:
	static Font title, normal, subtitle;
	essentials();
};

class texts {
public:
	Text text;
	texts(int posx, int posy, string textContent, char isTitle);
};



