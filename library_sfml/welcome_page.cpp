#include "welcome_page.h"


welcome_page::welcome_page() :
    libraryName(450, 300, "The Autumn Attic", 't', colors::title),
    sign_up_button(600, 600, "Sign Up"),
    log_in_button(1000, 600, "Log In") {
    visible = true;
}


void welcome_page::draw_starting_page(RenderWindow& window) {
 window.draw(welcome_page::libraryName.text);
 welcome_page::sign_up_button.buttonDraw(window);
 welcome_page::log_in_button.buttonDraw(window);
}