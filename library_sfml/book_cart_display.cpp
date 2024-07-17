#include "book_cart_display.h"
book_cart_display::book_cart_display(float posy, readersbooks book)
{
	bookname = texts(200, posy, book.title, 'n', colors::ntexts);
	cost = texts(650, posy, book.price, 'n', colors::warning);
	showDetails = buttons(1100, posy, "Show details", true);
	deleteFromCart = buttons(1400, posy, "Remove", true);
	quantity = texts(900, posy, book.quantity, 'n', colors::success);

}

book_cart_display::book_cart_display() {}

void book_cart_display::booksDraw(RenderWindow& window, book_cart_display book)
{
	window.draw(book.bookname.text);
	window.draw(book.cost.text);
	window.draw(book.quantity.text);
	book.showDetails.buttonDraw(window);
	if (Cart_page::isCartVisible)
		book.deleteFromCart.buttonDraw(window);
}
void book_cart_display::buttonClickedDetection(Vector2f pos, RenderWindow& window)
{
	vector<book_cart_display> books;
	if (Cart_page::isCartVisible) {
		books = Cart_page::items;
	}
	else {
		books = History_page::boughtItems;
	}
	for (int i = 0; i < books.size(); i++)
	{
		if (books[i].showDetails.button.getGlobalBounds().contains(pos)) {
			file_management::selectedBook = books[i].bookname.text.getString();
			History_page::isHistoryVisible = false;
			Cart_page::isCartVisible = false;
			cout << "selected book: " << file_management::selectedBook << endl;
			//isBookVisible = true;
			break;
			return;
		}
		else if (Cart_page::isCartVisible && books[i].deleteFromCart.button.getGlobalBounds().contains(pos)) {
			file_management::selectedBook = Cart_page::items[i].bookname.text.getString();
			cout << "deleted book: " << file_management::selectedBook << endl;
			break;
		}

	}
	for (int i = 0; i < file_management::selectedUser.cart_vector.size(); i++) {
		if (file_management::selectedUser.cart_vector[i].title == file_management::selectedBook) {
			file_management::selectedUser.cart_vector.erase(file_management::selectedUser.cart_vector.begin() + i);
		}
	}


}