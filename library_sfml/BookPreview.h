
#pragma once
#include "Materials.h"
#include "Book.h"
#include "ScrollableView.h"
#include "navbar.h"
#include <string>
class BookPreview
{
	public:
		photos image;
		string bookName,path;
		BookPreview();
		static void booksDraw(RenderWindow& window, BookPreview book);


};
class Books_page
{
	public:
		static texts title;
		static bool isBookspageVisible;
		static vector<BookPreview> BookPreviewVector;
		static float posy;
		static void enableScrolling();
		static void drawBooksPage(RenderWindow& window, vector<Book> genre, string genreName);


};

