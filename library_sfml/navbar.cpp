#include "navbar.h"
buttons navbar::logout(1600, 10, "Logout", true);
buttons navbar::history(1480, 10, "History", true);
buttons navbar::cart(1380, 10, "Cart", true);
buttons navbar::home;
buttons navbar::orders(1480, 10, "Orders", true);
photos navbar::nav("assets/welcome_navbar.jpeg", 500, -5, 0.75, 0.75);
photos navbar::nav2("assets/navbar2.jpeg", 650, -5, 0.5, 0.5);
string navbar::welcomenote = "WELCOME BACK";
texts navbar::welcome(780, 30, welcomenote, 'w', colors::ntexts);
bool navbar::isNavVisible = false;
RectangleShape navbar::navrec;

void navbar::initialize() {
	navrec.setSize(Vector2f(1800, 900));
	navrec.setPosition(0, 0);
	navrec.setFillColor(Color(245, 245, 220));
}

void navbar::readerNavDraw(RenderWindow& window, bool isHome)
{
	initialize();
	home=buttons(1280, 10, "Home", true);
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

void navbar::onNavHover(Vector2f pos)
{
	if (logout.button.getGlobalBounds().contains(pos)) {
		logout.buttonText.setFillColor(Color(210, 105, 30));
		home.buttonText.setFillColor(Color(210, 105, 30, 128));
		if (file_management::selectedUser.usertype=="Admin") {
			orders.buttonText.setFillColor(Color(210, 105, 30, 128));
		}
		else {
			cart.buttonText.setFillColor(Color(210, 105, 30, 128));
			history.buttonText.setFillColor(Color(210, 105, 30, 128));
		}

	}
	else if (home.button.getGlobalBounds().contains(pos)) {
		logout.buttonText.setFillColor(Color(210, 105, 30, 128));
		home.buttonText.setFillColor(Color(210, 105, 30));
		if (file_management::selectedUser.usertype=="Admin") {
			orders.buttonText.setFillColor(Color(210, 105, 30, 128));
		}
		else {
			cart.buttonText.setFillColor(Color(210, 105, 30, 128));
			history.buttonText.setFillColor(Color(210, 105, 30, 128));
		}

	}
	else if (file_management::selectedUser.usertype=="Admin" && orders.button.getGlobalBounds().contains(pos)) {
		logout.buttonText.setFillColor(Color(210, 105, 30, 128));
		orders.buttonText.setFillColor(Color(210, 105, 30));
		home.buttonText.setFillColor(Color(210, 105, 30,128));  
	}
	else if (file_management::selectedUser.usertype == "Reader" && cart.button.getGlobalBounds().contains(pos)) {

		logout.buttonText.setFillColor(Color(210, 105, 30, 128));
		cart.buttonText.setFillColor(Color(210, 105, 30));
		home.buttonText.setFillColor(Color(210, 105, 30, 128));
		history.buttonText.setFillColor(Color(210, 105, 30, 128));
	}
	else if (file_management::selectedUser.usertype == "Reader" && history.button.getGlobalBounds().contains(pos)) {
		logout.buttonText.setFillColor(Color(210, 105, 30, 128));
		cart.buttonText.setFillColor(Color(210, 105, 30, 128));
		home.buttonText.setFillColor(Color(210, 105, 30, 128));
		history.buttonText.setFillColor(Color(210, 105, 30));
	}
	else {
		home.buttonText.setFillColor(Color(210, 105, 30, 128));
		logout.buttonText.setFillColor(Color(210, 105, 30, 128));
		if (file_management::selectedUser.usertype=="Admin") {
			orders.buttonText.setFillColor(Color(210, 105, 30, 128));
		}
		else {
			cart.buttonText.setFillColor(Color(210, 105, 30, 128));
			history.buttonText.setFillColor(Color(210, 105, 30, 128));
		}

	}
}

void navbar::onNavClicked(Vector2f pos, bool& sourcePage)
{
	if (logout.button.getGlobalBounds().contains(pos)) {
		sourcePage = false;
		welcome_page::visible = true;
	}
	else if (home.button.getGlobalBounds().contains(pos)) {
		sourcePage = false;
		home_page::isHomepageVisible = true;
	}
	else if (cart.button.getGlobalBounds().contains(pos)) {
		sourcePage = false;
		Cart_page::isCartVisible=true;
	}
	else if (history.button.getGlobalBounds().contains(pos)) {
		sourcePage = false;
		History_page::isHistoryVisible = true;
	}
	
}


