#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include "file_management.h"
#include "navbar.h"
#include "Materials.h"
#include "ScrollableView.h"
class Cart_page
{
public:
	static texts title, warning, totalprice;
	static buttons checkout;
	static void enableScrolling();
	static void drawCart(RenderWindow& window);
	static float lastbook;
	Cart_page();


};
class book_cart_display {
public:
	texts bookname, cost;
	buttons showDetails, deleteFromCart;
	void booksDraw(RenderWindow& window, float posy);
};

