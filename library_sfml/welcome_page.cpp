#include "welcome_page.h"


welcome_page::welcome_page() :
    libraryName(400, 50, "A very well welcome to", 't', colors::title),
    sign_up_button(600, 700, "Sign Up",false),
    log_in_button(1000, 700, "Log In",false),
    logo("logo.jpeg", 650, 170, 0.45, 0.45)
{
    visible = true;
}


void welcome_page::draw_starting_page(RenderWindow& window) {
 window.draw(welcome_page::libraryName.text);
 welcome_page::sign_up_button.buttonDraw(window);
 welcome_page::log_in_button.buttonDraw(window);
 window.draw(welcome_page::logo.pic);
}