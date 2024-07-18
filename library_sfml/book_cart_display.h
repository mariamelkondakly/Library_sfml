#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <vector>
#include <string>
#include "Book.h"
#include "Materials.h"
#include "Cart_page.h"
#include "History_page.h"

class book_cart_display
{

public:

	texts bookname, cost, quantity;
	buttons showDetails, deleteFromCart;
	book_cart_display(float posy, readersbooks book);
	book_cart_display();
	static void booksDraw(RenderWindow& window, book_cart_display);
	static void buttonClickedDetection(Vector2f pos, RenderWindow& window);


};

