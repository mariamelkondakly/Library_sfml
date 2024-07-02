#include "navbar.h"
buttons navbar::logout(1400, 10, "Logout", true);
buttons navbar::history(1100, 10, "History", true);
buttons navbar::cart(990, 10, "Cart", true);
buttons navbar::home(970, 10, "Home", true);
buttons navbar::orders(990, 10, "Orders", true);
photos navbar::nav("welcome_navbar.jpeg", 500, 10, 0.5, 0.5);
photos navbar::nav2("navbar2.jpeg", 500, 10, 0.5, 0.5);
texts navbar::welcome(510, 5, welcomenote, 'w', colors::background);
RectangleShape navbar::navrec;
string navbar::welcomenote = "Welcome, " + file_management::selectedUser.username;

void navbar::initialize() {
	navrec.setSize(Vector2f(1800, 900));
	navrec.setPosition(0, 0);
	navrec.setFillColor(Color(245, 245, 220));
}

void navbar::readerNavDraw(RenderWindow& window, bool isHome)
{
	initialize();
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
	logout.buttonDraw(window);
	home.buttonDraw(window);
	orders.buttonDraw(window);
	if (isHome) {
		window.draw(nav.pic);
		window.draw(welcome.text);
	}
	else {
		window.draw(nav2.pic);

	}
}
