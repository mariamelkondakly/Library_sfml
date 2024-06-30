#include "navbar.h"

navbar::navbar() :
	logout(1400, 10, "Logout", true),
	history(1100,10,"History",true),
	cart(990,10,"Cart",true),
	home(970,10,"Home",true),
	nav("navbar.jpeg",500,10,0.5,0.5),
	nav2("navbar2.jepg",500,10,0.5,0.5),

	welcome(510, 5, welcomenote, 'w', colors::background) {
	navrec.setSize(Vector2f(1800, 900));
	navrec.setPosition(0, 0);
	navrec.setFillColor(Color(245, 245, 220));
	welcomenote = "Welcome, " + file_management::selectedUser->username;

}

void navbar::readerNavDraw(RenderWindow& window, bool isHome)
{
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
