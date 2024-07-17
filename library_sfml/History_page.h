#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include "book_cart_display.h"
#include <stack>
#include<string>
#include "Book.h"
#include "file_management.h"
#include "navbar.h"
#include "Materials.h"
#include "ScrollableView.h"
class book_cart_display;
class History_page
{
public:
	static vector<book_cart_display> boughtItems;
	static texts title,warning;
	static float booksSetUp();
	static void drawHistory(RenderWindow& window);
	static void enableScrolling();
	static bool isHistoryVisible;


};

