#include "BookPreview.h"
 float Books_page:: posy;
BookPreview::BookPreview(Book& book , string photoPath , float posx , float posy) {
	
	BookButton = buttons(posx, posy+50, book.title , true);
	image = photos(photoPath,posx, posy,0.5,0.5);

}

BookPreview::BookPreview()
{

}

void Books_page::booksSetUp( vector<Book> genre , string genreName)
{
	BookPreview book;
	float posx;
	string path;
	int counter=1;
	for (int i = 0; i < genre.size(); i++) {
		posy = 300;
		for (int j = 0 ; j < 4 ; j++) {

			posx=200;
			path = genreName + "/";
			path += counter;
			if (genreName == "mystery") {
				path += ".jpg";
			}
			else {
				path += ".png";
			}
			book = BookPreview(genre[counter-1],path,posx,posy);
			BookPreviewVector.push_back(book);
			posx += 200;
			counter++;
		}
		posy += 600;
	}
}

void Books_page::enableScrolling()
{
	Scrollable::setLowerBound(posy + 500);
}

void Books_page::drawBooksPage(RenderWindow& window)
{
	BookPreviewVector.clear();
	navbar::readerNavDraw(window, false);
	if (!boughtItems.empty()) {

		for (int i = 0; i < History_page::boughtItems.size(); i++) {
			book_cart_display::booksDraw(window, boughtItems[i]);
		}
	}
	else {
		window.draw(warning.text);
	}
	window.draw(title.text);
}
