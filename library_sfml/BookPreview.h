
#pragma once
#include "Materials.h"
#include "Book.h"
#include "ScrollableView.h"
class BookPreview
{
	public:
		photos image;
		buttons BookButton;
	


		BookPreview(Book& book, string photoPath, float posx, float posy);
		BookPreview();

};
class Books_page
{
	public:
		static string title;
		static vector<BookPreview> BookPreviewVector;
		static float posy;
		static void enableScrolling();
		static void booksSetUp(vector<Book> genre, string genreName);
		static void drawBooksPage(RenderWindow& window);

};

