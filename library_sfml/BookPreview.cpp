#include "BookPreview.h"

texts Books_page::title(200, 100, "The books you experienced", 't', colors::title);
 float Books_page:: posy;
 bool Books_page::isBookspageVisible=false;
 vector<BookPreview>Books_page::BookPreviewVector;
BookPreview::BookPreview(Book& book , string photoPath , float posx , float posy) {
	
	BookButton = buttons(posx, posy+50, book.title , true);
	image = photos(photoPath,posx, posy,0.5,0.5);

}

BookPreview::BookPreview()
{

}

void Books_page::booksSetUp( vector<Book> genre , string genreName)
{
	BookPreviewVector.reserve(20);
	BookPreview book;
	float posx;
	string path;
	int counter=1;
	posy = 300;
	for (int i = 0; i < genre.size(); i++) {
		posx = 200;
		for (int j = 0; j < 4 && counter <= genre.size(); j++) {
			path = genreName + "/";
			path += to_string(counter);
			if (genreName == "mystery") {
				path += ".jpg";
			}
			else {
				path += ".png";

			}
			cout << "photo path = " << path<<endl;
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

void BookPreview::booksDraw(RenderWindow& window, BookPreview book)
{
	book.BookButton.buttonDraw(window);
	window.draw(book.image.pic);
	
}

void Books_page::drawBooksPage(RenderWindow& window , vector<Book> genre, string genreName)
{
	BookPreviewVector.clear();
	booksSetUp(genre, genreName);
	if (file_management::selectedUser.usertype == "Admin") {
		navbar::adminNavDraw(window, false);
	}
	else {
		navbar::readerNavDraw(window, false);
	}
	for (int i = 0; i < BookPreviewVector.size(); i++) {
		BookPreview::booksDraw(window, BookPreviewVector[i]);
	}
	window.draw(title.text);
}
