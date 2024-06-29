#include "welcome_page.h"


welcome_page::welcome_page() :
    libraryName(300, 300, "The Autumn Attic", 't'),
    sign_up_button(300, 600, "Sign Up"),
    log_in_button(600, 600, "Log In") {}


void welcome_page::draw_starting_page(RenderWindow& window) {
 window.draw(welcome_page::libraryName.text);
 welcome_page::sign_up_button.buttonDraw(window);
 welcome_page::log_in_button.buttonDraw(window);
}