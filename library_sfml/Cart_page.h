#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <vector>
#include<string>
#include "Book.h"
#include "file_management.h"
#include "navbar.h"
#include "Materials.h"
#include "ScrollableView.h"

class book_cart_display {
public:
	texts bookname, cost, quantity;
	buttons showDetails, deleteFromCart;
	book_cart_display(float posy, readersbooks book);
	book_cart_display();
	static void booksDraw(RenderWindow& window, book_cart_display);
};

class Cart_page
{
public:
	static texts title, warning, totalprice;
	static buttons checkout;
	static vector<book_cart_display> items;
	static string selectedBook;
	static bool isCartVisible;
	static float booksSetUp();
	static void enableScrolling();
	static void drawCart(RenderWindow& window);
	static void oncheckoutHover(Vector2f pos);
	static void buttonClickedDetection(Vector2f pos, RenderWindow& window);


	Cart_page();


};

