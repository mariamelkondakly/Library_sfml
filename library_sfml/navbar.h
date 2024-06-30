#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include "file_management.h"
#include "Materials.h"

class navbar
{
public:
	
	texts welcome;
	RectangleShape navrec;
	buttons cart;
	buttons home;
	buttons logout;
	buttons history;
	photos nav;
	photos nav2;
	string welcomenote;
	navbar();
	void readerNavDraw(RenderWindow& window, bool isHome);
};

