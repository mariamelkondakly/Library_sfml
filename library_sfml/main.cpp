#include <SFML/Graphics.hpp>
#include "welcome_page.h"
#include "file_management.h"
#include "signup_page.h"
#include "navbar.h"
#include "home_page.h"
#include "pages.h"

int main() {
    file_management::file_to_sizes();
    file_management::files_to_vectors();
    file_management::file_to_users();


    RenderWindow window(VideoMode(1800, 900), "Library", Style::Default);


    welcome_page start_page;
    User newuser;




    // Start the game loop
    while (window.isOpen()) {
        // Process events
        Event event;
        while (window.pollEvent(event)) {
            Vector2f StartingmousePosition = window.mapPixelToCoords(Vector2i(event.mouseButton.x, event.mouseButton.y));
            Vector2f MovingmousePosition = window.mapPixelToCoords(Vector2i(event.mouseMove.x, event.mouseMove.y));


            switch (event.type) {
            case Event::Closed:
                window.close();       break;

            case Event::MouseMoved:
                if (start_page.log_in_button.button.getGlobalBounds().contains(MovingmousePosition)) {
                    start_page.log_in_button.onHover();
                    start_page.sign_up_button.onUnHover();
                }
                else if (start_page.sign_up_button.button.getGlobalBounds().contains(MovingmousePosition)) {
                    start_page.sign_up_button.onHover();
                    start_page.log_in_button.onUnHover();
                }
                else if (signup_page::isLoginVisible && signup_page::login_submit.button.getGlobalBounds().contains(MovingmousePosition)) {
                    signup_page::login_submit.onHover();
                }
                else if (signup_page::isSignupVisible && signup_page::signup_submit.button.getGlobalBounds().contains(MovingmousePosition)) {
                    signup_page::signup_submit.onHover();
                }
                else if (home_page::isHomepageVisible) {
                    home_page::genreTouched(MovingmousePosition);
                }
                else {
                    start_page.sign_up_button.onUnHover();
                    start_page.log_in_button.onUnHover();
                    signup_page::login_submit.onUnHover();
                    signup_page::signup_submit.onUnHover();

                }
                break;


            case Event::MouseButtonPressed:

                if (event.mouseButton.button == Mouse::Left) {

                    if (start_page.log_in_button.button_float.contains(StartingmousePosition) && start_page.visible) {
                        start_page.visible = false;
                        signup_page::isLoginVisible = true;
                    }
                    else if (start_page.sign_up_button.button_float.contains(StartingmousePosition) && start_page.visible) {
                        start_page.visible = false;
                        signup_page::isSignupVisible = true;
                    }

                    else if (signup_page::isSignupVisible && signup_page::admin_check.CheckFloat.contains(StartingmousePosition)) {
                        newuser.isAdmin = true;
                        signup_page::admin_check.onCheck();
                        signup_page::reader_check.onUncheck();
                    }
                    else if (signup_page::isSignupVisible && signup_page::reader_check.CheckFloat.contains(StartingmousePosition)) {
                        newuser.isAdmin = false;
                        signup_page::reader_check.onCheck();
                        signup_page::admin_check.onUncheck();
                    }
                    else if (signup_page::isSignupVisible && signup_page::signup_field_username.fieldFloat.contains(StartingmousePosition)) {
                        signup_page::signup_field_username.inputEntered = true;
                        signup_page::signup_field_username.onselect();
                        signup_page::signup_field_password.inputEntered = false;
                        signup_page::signup_field_password.onunselect();
                    }
                    else if (signup_page::isSignupVisible && signup_page::signup_field_password.fieldFloat.contains(StartingmousePosition)) {
                        signup_page::signup_field_username.inputEntered = false;
                        signup_page::signup_field_username.onunselect();
                        signup_page::signup_field_password.inputEntered = true;
                        signup_page::signup_field_password.onselect();
                    }
                    else if (signup_page::isLoginVisible && signup_page::login_field_username.fieldFloat.contains(StartingmousePosition)) {
                        signup_page::login_field_username.inputEntered = true;
                        signup_page::login_field_username.onselect();
                        signup_page::login_field_password.inputEntered = false;
                        signup_page::login_field_password.onunselect();
                    }
                    else if (signup_page::isLoginVisible && signup_page::login_field_password.fieldFloat.contains(StartingmousePosition)) {
                        signup_page::login_field_username.inputEntered = false;
                        signup_page::login_field_username.onunselect();
                        signup_page::login_field_password.inputEntered = true;
                        signup_page::login_field_password.onselect();
                    }
                    else if (signup_page::isSignupVisible && signup_page::signup_submit.button_float.contains(StartingmousePosition)) {
                        if (signup_page::onSignUpSubmit(newuser, signup_page::signup_field_username.data, signup_page::signup_field_password.data, signup_page::warning)) {
                            signup_page::isSignupVisible = false;
                            signup_page::isLoginVisible = true;
                            signup_page::resetInputFlags();
                            signup_page::isWarning = false;

                        }
                        else {
                            signup_page::isWarning = true;
                        }
                    }
                    else if (signup_page::isLoginVisible && signup_page::login_submit.button_float.contains(StartingmousePosition)) {
                        if (signup_page::onLoginSubmit(newuser, signup_page::login_field_username.data, signup_page::login_field_password.data, signup_page::warning)) {
                            signup_page::isLoginVisible = false;
                            signup_page::isWarning = false;
                            home_page::isHomepageVisible = true;
                        }
                        else {
                            signup_page::isWarning = true;
                        }
                    }
                }
            case Event::TextEntered:
                if (signup_page::signup_field_username.inputEntered) {
                    TextField::inputHandelling(event, false, signup_page::signup_field_username);
                }
                else if (signup_page::signup_field_password.inputEntered) {
                    TextField::inputHandelling(event, true, signup_page::signup_field_password);
                }
                else if (signup_page::login_field_username.inputEntered) {
                    TextField::inputHandelling(event, false, signup_page::login_field_username);
                }
                else if (signup_page::login_field_password.inputEntered) {
                    TextField::inputHandelling(event, true, signup_page::login_field_password);
                }


            }


        }

        // Clear the screen
        window.clear(sf::Color{ 245, 245, 220 });


        //window.draw(background);
        if (start_page.visible)
            start_page.draw_starting_page(window);
        else if (signup_page::isLoginVisible) {
            signup_page::draw_login_page(window);
            signup_page::isSignupVisible = false;
        }
        else if (signup_page::isSignupVisible) {
            signup_page::draw_signup_page(window);
            signup_page::isLoginVisible = false;
        }
        else if (home_page::isHomepageVisible) {
            home_page::drawHomepage(window);
        }
        if (signup_page::isWarning) {
            window.draw(signup_page::warning.text);
        }

        window.display();
    }
    file_management::sizes_to_file();
    file_management::vectors_to_files();
    file_management::users_to_file();
    return 0;
}
