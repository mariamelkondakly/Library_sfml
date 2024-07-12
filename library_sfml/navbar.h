#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include "file_management.h"
#include "Materials.h"
#include"welcome_page.h"
class navbar
{
public:
	
	static texts welcome;
	static RectangleShape navrec;
	static buttons cart;
	static buttons home;
	static buttons logout;
	static buttons history;
	static buttons orders;
	static photos nav;
	static photos nav2;
	static string welcomenote;
	static void initialize();
	static void readerNavDraw(RenderWindow& window, bool isHome);
	static void adminNavDraw(RenderWindow& window, bool isHome);
	static void onNavHover(Vector2f pos);
	static void onNavClicked(Vector2f pos, bool& sourcePage);
	
};

