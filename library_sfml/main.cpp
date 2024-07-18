#include <SFML/Graphics.hpp>
#include "welcome_page.h"
#include "file_management.h"
#include "signup_page.h"
#include "navbar.h"
#include "home_page.h"
#include "History_page.h"
#include "pages.h"
#include "ScrollableView.h"
#include "Cart_page.h"
#include "book_cart_display.h"
#include "BookPreview.h"
using namespace std;
int main() {
    file_management::file_to_sizes();
    file_management::files_to_vectors();
    file_management::file_to_users();




    RenderWindow window(VideoMode(1800, 900), "Library", Style::Default);


    welcome_page start_page;
    User newuser;

    float upperBound = 0.0f; // Set the upper bound
    Scrollable::init(&window, upperBound);


    // Start the game loop
    while (window.isOpen()) {

        // Process events
        Event event;
        while (window.pollEvent(event)) {
            Vector2f StartingmousePosition = window.mapPixelToCoords(Vector2i(event.mouseButton.x, event.mouseButton.y));
            Vector2f MovingmousePosition = window.mapPixelToCoords(Vector2i(event.mouseMove.x, event.mouseMove.y));

            if (home_page::isHomepageVisible) {
                home_page::enableScrolling();
            }
            else if (Cart_page::isCartVisible) {
                Cart_page::enableScrolling();
            }
            else if (History_page::isHistoryVisible) {
                History_page::enableScrolling();
            }
            else if (Books_page::isBookspageVisible) {
                Books_page::enableScrolling();
            }


            if (!welcome_page::visible && !signup_page::isLoginVisible && !signup_page::isSignupVisible) {
                navbar::isNavVisible = true;
            }

            switch (event.type) {
            case Event::Closed:
                window.close();       break;

            case Event::MouseMoved:
                if (start_page.visible) {
                    start_page.onWelcomeHover(MovingmousePosition, start_page);
                }
                else if (signup_page::isLoginVisible || signup_page::isSignupVisible) {
                    signup_page::onSignupHover(MovingmousePosition);
                }
                else if (home_page::isHomepageVisible) {
                    home_page::genreTouched(MovingmousePosition);
                }
                else if (Cart_page::isCartVisible) {
                    Cart_page::oncheckoutHover(MovingmousePosition);
                }
                if (navbar::isNavVisible) {
                    navbar::onNavHover(MovingmousePosition);
                }
                break;


            case Event::MouseButtonPressed:

                if (event.mouseButton.button == Mouse::Left) {

                    if (start_page.visible) {
                        start_page.WelcomeButtonsClicked(StartingmousePosition, start_page);
                    }
                    else if (signup_page::isLoginVisible || signup_page::isSignupVisible) {
                        signup_page::onButtonsClicked(StartingmousePosition, newuser);
                    }
                    else if (home_page::isHomepageVisible) {
                        navbar::onNavClicked(StartingmousePosition, home_page::isHomepageVisible);
                        home_page::genreClicked(StartingmousePosition);
                    }
                    else if (Cart_page::isCartVisible) {
                        navbar::onNavClicked(StartingmousePosition, Cart_page::isCartVisible);
                        book_cart_display::buttonClickedDetection(StartingmousePosition,window);
                        Cart_page::onCheckoutClicked(StartingmousePosition);
                    }
                    else if (History_page::isHistoryVisible) {
                        navbar::onNavClicked(StartingmousePosition, History_page::isHistoryVisible);
                        book_cart_display::buttonClickedDetection(StartingmousePosition, window);
                    }
                    else if (Books_page::isBookspageVisible) {
                        navbar::onNavClicked(StartingmousePosition, Books_page::isBookspageVisible);


                    }

                }
                break;

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

                break;
            }
            Scrollable::handleScroll(event);

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
        else if (Books_page::isBookspageVisible) {
            Books_page::genreSelection(window);

        }
        else if (Cart_page::isCartVisible) {
            Cart_page::drawCart(window);
        }
        else if (History_page::isHistoryVisible) {
            History_page::drawHistory(window);
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
