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
	static texts bookTitle, description, rating, authorName, type, amountAvailable, cost;
	static buttons AddToCart, GoBack;
	static bool isBookDetailsVisible;
	static string details;
	static Book setBookDetails_page(vector<Book> genre);
	static void drawBookDetailspage(RenderWindow& window);
	static void enableScrolling();
};

