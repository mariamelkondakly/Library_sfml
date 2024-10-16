#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include "book_cart_display.h"
#include <vector>
#include<string>
#include "Book.h"
#include "file_management.h"
#include "navbar.h"
#include "Materials.h"
#include "History_page.h"
#include "ScrollableView.h"

class book_cart_display;

class Cart_page
{
public:
	static texts title, warning, totalprice;
	static buttons checkout;
	static vector<book_cart_display> items;
	static bool isCartVisible;
	static float booksSetUp();
	static void enableScrolling();
	static void drawCart(RenderWindow& window);
	static void oncheckoutHover(Vector2f pos);
	static void onCheckoutClicked(Vector2f pos);


	Cart_page();


};

