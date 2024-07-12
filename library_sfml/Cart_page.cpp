#include "Cart_page.h"
float Cart_page::lastbook;
texts Cart_page::title(200, 50, "Happy Purchase", 't', colors::title);
texts Cart_page::warning(600, 400, "Cart is empty, choos your favourite books to fill it", 'w', colors::warning);
texts Cart_page::totalprice(200,lastBook,;
buttons Cart_page::checkout;

void Cart_page::enableScrolling()
{
	Scrollable::setLowerBound(checkout.button.getPosition().y + checkout.button.getSize().y + 500);
}

void Cart_page::drawCart(RenderWindow& window)
{

}

void book_cart_display::booksDraw(RenderWindow& window, float posy)
{
}
