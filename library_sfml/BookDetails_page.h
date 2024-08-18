#pragma once
#include "Book.h"
#include "Materials.h"
#include "file_management.h"
#include "navbar.h"
#include "ScrollableView.h"

class BookDetails_page
{
public:
	BookDetails_page();
	static photos* bookCover;
	static texts bookTitle, description, rating, authorName, type, amountAvailable, cost, warning;
	static buttons AddToCart, GoBack;
	static bool isBookDetailsVisible, isWarningVisible;
	static string details;
	static Book setBookDetails_page(map<string,Book>);
	static void drawBookDetailspage(RenderWindow& window);
	static void enableScrolling();
	static void onAddToCartClicked(Vector2f pos,map<string, Book> genre);
	static void onGoBackClicked(Vector2f pos, map<string, Book> genre);

};

