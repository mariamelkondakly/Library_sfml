#include "Cart_page.h"
texts Cart_page::title(200, 100, "Happy Purchase", 't', colors::title);
texts Cart_page::warning(200, 260, "Cart is empty, choose your favourite books to fill it", 'w', colors::warning);
texts Cart_page::totalprice;
vector<book_cart_display> Cart_page::items;
buttons Cart_page::checkout;
bool Cart_page::isCartVisible = false;

void Cart_page::enableScrolling()
{
	Scrollable::setLowerBound(checkout.button.getPosition().y + checkout.button.getSize().y + 500);
}

float Cart_page::booksSetUp()
{
	items.clear();
	file_management::users[file_management::selectedUser].totalPrice = 0;
	file_management::users[file_management::selectedUser].calculateTotalPrice();
	book_cart_display book;
	float pos = 300;
	for (int i = 0; i < file_management::users[file_management::selectedUser].cart_vector.size(); i++) {
		book = book_cart_display(pos, file_management::users[file_management::selectedUser].cart_vector[i]);
		items.push_back(book);
		pos += 200;
	}




	return pos;
}

void Cart_page::drawCart(RenderWindow& window)
{
	items.clear();  
	float pos=booksSetUp()+50;
	string prices = to_string(file_management::users[file_management::selectedUser].totalPrice) + " $";
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



void Cart_page::oncheckoutHover(Vector2f pos)
{
	if (checkout.button.getGlobalBounds().contains(pos)) {
		checkout.onHover();
	}
	else {
		checkout.onUnHover();
	}
}

void Cart_page::onCheckoutClicked(Vector2f pos)
{
	if (checkout.button.getGlobalBounds().contains(pos)) {

		for (int i = 0; i < file_management::users[file_management::selectedUser].cart_vector.size(); i++) {
			cout << "Entered" << endl;
			file_management::users[file_management::selectedUser].boughtBooks.push_back(file_management::users[file_management::selectedUser].cart_vector[i]);
		}
		file_management::users[file_management::selectedUser].cart_vector.clear();
		isCartVisible = false;
		History_page::isHistoryVisible = true;
	}
}


