#include "welcome_page.h"

texts welcome_page::libraryName(400, 50, "A very well welcome to", 't', colors::title);
buttons welcome_page::sign_up_button(600, 700, "Sign Up", false);
buttons welcome_page::log_in_button(1000, 700, "Log In", false);
photos welcome_page::logo("logo.jpeg", 650, 170, 0.45, 0.45);
bool welcome_page::visible = true;

welcome_page::welcome_page() {}


void welcome_page::draw_starting_page(RenderWindow& window) {
 window.draw(welcome_page::libraryName.text);
 welcome_page::sign_up_button.buttonDraw(window);
 welcome_page::log_in_button.buttonDraw(window);
 window.draw(welcome_page::logo.pic);
}

void welcome_page::WelcomeButtonsClicked(Vector2f pos, welcome_page& welcome)
{
	if (welcome.log_in_button.button_float.contains(pos)) {
		welcome.visible = false;
		signup_page::isLoginVisible = true;
	}
	else if (welcome.sign_up_button.button_float.contains(pos)) {
		welcome.visible = false;
		signup_page::isSignupVisible = true;
	}
}

void welcome_page::onWelcomeHover(Vector2f pos, welcome_page& welcome)
{
	if (welcome.log_in_button.button.getGlobalBounds().contains(pos)) {
		welcome.log_in_button.onHover();
		welcome.sign_up_button.onUnHover();
	}
	else if (welcome.sign_up_button.button.getGlobalBounds().contains(pos)) {
		welcome.sign_up_button.onHover();
		welcome.log_in_button.onUnHover();
	}
	else {
		welcome.sign_up_button.onUnHover();
		welcome.log_in_button.onUnHover();
	}
}
