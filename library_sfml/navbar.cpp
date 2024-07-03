#include "navbar.h"
buttons navbar::logout(1600, 10, "Logout", true);
buttons navbar::history(1480, 10, "History", true);
buttons navbar::cart(1260, 10, "Cart", true);
buttons navbar::home;
buttons navbar::orders(1480, 10, "Orders", true);
photos navbar::nav("welcome_navbar.jpeg", 500, -5, 0.75, 0.75);
photos navbar::nav2("navbar2.jpeg", 650, -5, 0.5, 0.5);
string navbar::welcomenote = "WELCOME BACK";
texts navbar::welcome(780, 30, welcomenote, 'w', colors::ntexts);
RectangleShape navbar::navrec;

void navbar::initialize() {
	navrec.setSize(Vector2f(1800, 900));
	navrec.setPosition(0, 0);
	navrec.setFillColor(Color(245, 245, 220));
}

void navbar::readerNavDraw(RenderWindow& window, bool isHome)
{
	initialize();
	home=buttons(1040, 10, "Home", true);
	window.draw(navrec);
	logout.buttonDraw(window);
	home.buttonDraw(window);
	cart.buttonDraw(window);
	history.buttonDraw(window);
	if (isHome) {
		window.draw(nav.pic);
		window.draw(welcome.text);
	}
	else {
		window.draw(nav2.pic);

	}
}
void navbar::adminNavDraw(RenderWindow& window, bool isHome)
{
	window.draw(navrec);
	if (isHome) {
		window.draw(nav.pic);
		window.draw(welcome.text);

	}
	else {
		window.draw(nav2.pic);

	}
	home=buttons(1360, 10, "Home", true);
	logout.buttonDraw(window);
	home.buttonDraw(window);
	orders.buttonDraw(window);

}
