#include <SFML/Graphics.hpp>
#include "welcome_page.h"
#include "file_management.h"
#include "signup_page.h"
#include "navbar.h"

int main() {
    file_management::file_to_sizes();
    file_management::files_to_vectors();
    file_management::file_to_users();
    

    RenderWindow window(VideoMode(1800, 900), "Library", Style::Default);

    

    welcome_page start_page;
    signup_page signup;
    User newuser;
    navbar readernav;
    
    

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
                else if (signup.isLoginVisible&&signup.login_submit.button.getGlobalBounds().contains(MovingmousePosition)) {
                    signup.login_submit.onHover();
                }
                else if (signup.isSignupVisible && signup.signup_submit.button.getGlobalBounds().contains(MovingmousePosition)) {
                    signup.signup_submit.onHover();
                }
                else {
                    start_page.sign_up_button.onUnHover();
                    start_page.log_in_button.onUnHover();
                    signup.login_submit.onUnHover();
                    signup.signup_submit.onUnHover();

                }
                break;


            case Event::MouseButtonPressed:
                    
                    if (event.mouseButton.button == Mouse::Left) {
                        
                        if (start_page.log_in_button.button_float.contains(StartingmousePosition)&&start_page.visible) {
                            start_page.visible = false;
                            signup.isLoginVisible = true;
                        }
                        else if (start_page.sign_up_button.button_float.contains(StartingmousePosition) && start_page.visible) {
                            start_page.visible = false;
                            signup.isSignupVisible = true;
                        }

                        else if (signup.isSignupVisible&&signup.admin_check.CheckFloat.contains(StartingmousePosition)) {
                            newuser.isAdmin = true;
                            signup.admin_check.onCheck();
                            signup.reader_check.onUncheck();
                        }
                        else if (signup.isSignupVisible && signup.reader_check.CheckFloat.contains(StartingmousePosition)) {
                            newuser.isAdmin = false;
                            signup.reader_check.onCheck();
                            signup.admin_check.onUncheck();
                        }
                        else if (signup.isSignupVisible && signup.signup_field_username.fieldFloat.contains(StartingmousePosition)) {
                            signup.signup_field_username.inputEntered = true;
                            signup.signup_field_username.onselect();
                            signup.signup_field_password.inputEntered = false;
                            signup.signup_field_password.onunselect();
                        }
                        else if (signup.isSignupVisible && signup.signup_field_password.fieldFloat.contains(StartingmousePosition)) {
                            signup.signup_field_username.inputEntered = false;
                            signup.signup_field_username.onunselect();
                            signup.signup_field_password.inputEntered = true;
                            signup.signup_field_password.onselect();
                        }
                        else if (signup.isLoginVisible && signup.login_field_username.fieldFloat.contains(StartingmousePosition)) {
                            signup.login_field_username.inputEntered = true;
                            signup.login_field_username.onselect();
                            signup.login_field_password.inputEntered = false;
                            signup.login_field_password.onunselect();
                        }
                        else if (signup.isLoginVisible && signup.login_field_password.fieldFloat.contains(StartingmousePosition)) {
                            signup.login_field_username.inputEntered = false;
                            signup.login_field_username.onunselect();
                            signup.login_field_password.inputEntered = true;
                            signup.login_field_password.onselect();
                        }
                        else if (signup.isSignupVisible && signup.signup_submit.button_float.contains(StartingmousePosition)) {
                            if (signup.onSignUpSubmit(newuser, signup.signup_field_username.data, signup.signup_field_password.data, signup.warning)) {
                                signup.isSignupVisible = false;
                                signup.isLoginVisible = true;
                                signup.resetInputFlags(signup);
                                signup.isWarning = false;

                            }
                            else {
                                signup.isWarning = true;
                            }
                        }
                        else if (signup.isLoginVisible && signup.login_submit.button_float.contains(StartingmousePosition)) {
                            if (signup.onLoginSubmit(newuser, signup.login_field_username.data, signup.login_field_password.data, signup.warning)) {
                                signup.isLoginVisible = false;
                                signup.isWarning = false;
                                if (file_management::selectedUser->isAdmin) {

                                }
                                else {

                                }
                            }
                            else {
                                signup.isWarning = true;
                            }
                        }
                    }
            case Event::TextEntered:   
                if (signup.signup_field_username.inputEntered) {
                    TextField::inputHandelling(event, false, signup.signup_field_username);
                }
                else if (signup.signup_field_password.inputEntered) {
                    TextField::inputHandelling(event, true, signup.signup_field_password);
                }
                else if (signup.login_field_username.inputEntered) {
                    TextField::inputHandelling(event, false, signup.login_field_username);
                }
                else if (signup.login_field_password.inputEntered) {
                    TextField::inputHandelling(event, true, signup.login_field_password);
                }


            }
            
                
        }

        // Clear the screen
        window.clear(sf::Color{245, 245, 220});


        //window.draw(background);
       if (start_page.visible)
            start_page.draw_starting_page(window);
        else if (signup.isLoginVisible) {
            signup.draw_login_page(window);
            signup.isSignupVisible = false;
        }
        else if (signup.isSignupVisible) {
            signup.draw_signup_page(window);
            signup.isLoginVisible = false;
        }
        if (signup.isWarning) {
           window.draw(signup.warning.text);
       }

        window.display();
    }
    file_management::sizes_to_file();
    file_management::vectors_to_files();
    file_management::users_to_file();
    return 0;
}
