#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include "file_management.h"
#include "navbar.h"
#include "Materials.h"
class home_page
{
public:


	static void drawHomepage(RenderWindow& window);
	static void genreTouched(Vector2f pos);
	static bool isHomepageVisible;
	static photos fantasy, mystery, romance,sci_fi,nonfiction;
	static texts fantasyDescription,mysteryDescription,romanceDescription,scifiDescription,nonficDescription;
	static buttons fantasyButton, mysteryButton, romanceButton, scifiButton, nonficButton;
	static string fdesc, mdesc, rdesc, sdesc, ndesc;
};

