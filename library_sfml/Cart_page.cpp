#include "Cart_page.h"
texts Cart_page::title(200, 100, "Happy Purchase", 't', colors::title);
texts Cart_page::warning(200, 450, "Cart is empty, choose your favourite books to fill it", 'w', colors::warning);
texts Cart_page::totalprice;
std::vector<book_cart_display> Cart_page::items;
buttons Cart_page::checkout;
bool Cart_page::isCartVisible = false;

void Cart_page::enableScrolling()
{
	Scrollable::setLowerBound(checkout.button.getPosition().y + checkout.button.getSize().y + 500);
}

float Cart_page::booksSetUp()
{
	book_cart_display book;
	float pos = 300;
	for (int i = 0; i < file_management::selectedUser.cart_vector.size(); i++) {
		book = book_cart_display(pos, file_management::selectedUser.cart_vector[i]);
		items.push_back(book);
		pos += 200;
	}
	readersbooks dummy = readersbooks("Serpant & Dove", "20$", "2");

	book_cart_display dummyBook = book_cart_display(pos, dummy);

	items.push_back(dummyBook);


	return pos;
}

void Cart_page::drawCart(RenderWindow& window)
{
	string prices = to_string(file_management::selectedUser.calculateTotalPrice()) + " $";
	float pos=booksSetUp()+200;
	totalprice = texts(200, pos,prices, 't', colors::title);
	checkout = buttons(600, pos, "Check out", false);
	navbar::readerNavDraw(window, false);
	if (!items.empty()) {

		for (int i = 0; i < items.size(); i++) {
			book_cart_display::booksDraw(window, items[i]);
		}
	}
	else {
		window.draw(warning.text);
	}
	window.draw(totalprice.text);
	checkout.buttonDraw(window);
	window.draw(title.text);
}



Cart_page::Cart_page(){}

book_cart_display::book_cart_display(float posy, readersbooks book)
{
	bookname = texts(200, posy, book.title, 'n', colors::ntexts);
	cost = texts(650, posy, book.price, 'n', colors::warning);
	showDetails = buttons(1100, posy, "Show details", true);
	deleteFromCart = buttons(1400, posy, "Remove", true);
	quantity = texts(900, posy, book.quantity, 'n', colors::success);

}

book_cart_display::book_cart_display(){}

void book_cart_display::booksDraw(RenderWindow& window, book_cart_display book)
{
	window.draw(book.bookname.text);
	window.draw(book.cost.text);
	window.draw(book.quantity.text);
	book.showDetails.buttonDraw(window);
	book.deleteFromCart.buttonDraw(window);
}

void Cart_page::oncheckoutHover(Vector2f pos)
{
	if (checkout.button.getGlobalBounds().contains(pos)) {
		checkout.onHover();
	}
	else {
		checkout.onUnHover();
	}
}
