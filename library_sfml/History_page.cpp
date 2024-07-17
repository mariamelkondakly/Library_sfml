#include "History_page.h"
vector<book_cart_display> History_page::boughtItems;
texts History_page::title(200, 100, "The books you experienced", 't', colors::title);
texts History_page::warning(200, 260, "You haven't bought any books yet. It's never too late though!", 'w', colors::warning);
bool History_page::isHistoryVisible=false;


void History_page::enableScrolling()
{
	Scrollable::setLowerBound(booksSetUp() + 500);
}

float History_page::booksSetUp()
{
	book_cart_display book;
	float pos = 300;
	for (int i = 0; i < file_management::selectedUser.boughtBooks.size(); i++) {
		book = book_cart_display(pos, file_management::selectedUser.boughtBooks[i]);
		boughtItems.push_back(book);
		pos += 200;
	}

	return pos;
}
void History_page::drawHistory(RenderWindow& window)
{
	boughtItems.clear();
	float pos = booksSetUp() + 50;
	navbar::readerNavDraw(window, false);
	if (!boughtItems.empty()) {

		for(int i=0;i<History_page::boughtItems.size();i++) {
			book_cart_display::booksDraw(window, boughtItems[i]);
		}
	}
	else {
		window.draw(warning.text);
	}
	window.draw(title.text);
}
