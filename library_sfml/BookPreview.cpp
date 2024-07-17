#include "BookPreview.h"

texts Books_page::title(200, 100, "The books you experienced", 't', colors::title);
 float Books_page:: posy;
 bool Books_page::isBookspageVisible=false;
 vector<BookPreview>Books_page::BookPreviewVector;

BookPreview::BookPreview(){
	path = "";
	bookName = "";
}

void Books_page::enableScrolling()
{
	Scrollable::setLowerBound(posy + 500);
}

void BookPreview::booksDraw(RenderWindow& window, BookPreview book)
{
	window.draw(book.image.pic);	
}

void Books_page::drawBooksPage(RenderWindow& window , vector<Book> genre, string genreName)
{

	BookPreviewVector.clear();
	float posx;
	int counter = 1;
	posy = 200;
	BookPreview book;
	for (int i = 0; i < genre.size(); i++) {
		posx = 200;
		for (int j = 0; j < 4 && counter <= 2; j++) {
			book = BookPreview();
			book.path = genreName + "/";
			book.path += to_string(counter);
			if (genreName == "mystery") {
				book.path += ".jpg";
			}
			else {
				book.path += ".png";

			}
			book.image = photos(book.path, posx, posy, 0.5, 0.5);
			book.bookName = genre[counter-1].title;
			BookPreviewVector.push_back(book);
			posx += 200;
			counter++;
		}
		posy += 600;
	}

	window.draw(title.text);
	if (file_management::selectedUser.usertype == "Admin") {
		navbar::adminNavDraw(window, false);
	}
	else {
		navbar::readerNavDraw(window, false);
	}
	for (int i = 0; i < BookPreviewVector.size(); i++) {

		BookPreview::booksDraw(window, BookPreviewVector[i]);
	}
}
