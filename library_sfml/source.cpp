#include <SFML/Graphics.hpp>
#include "welcome_page.h"
#include "file_management.h"
#include "signup_page.h"

int main() {
    file_management::file_to_sizes();
    file_management::files_to_vectors();

    RenderWindow window(VideoMode(1800, 900), "Library", Style::Default);

    //Texture backgroundTexture;
    //backgroundTexture.loadFromFile("BackGround.png");
    //Sprite background(backgroundTexture);

    // Create the welcome page
    welcome_page start_page;
    signup_page signup;
    

    // Start the game loop
    while (window.isOpen()) {
        // Process events
        Event event;
        while (window.pollEvent(event)) {
            switch (event.type) {
            case Event::Closed:
                window.close();       break;
                case Event::MouseButtonPressed:

                    if (event.mouseButton.button == Mouse::Left) {
                        Vector2f StartingmousePosition = window.mapPixelToCoords(Vector2i(event.mouseButton.x, event.mouseButton.y));
                        if (start_page.log_in_button.button_float.contains(StartingmousePosition)) {
                            start_page.visible = false;
                            signup.isLoginVisible = true;
                        }
                        else if (start_page.sign_up_button.button_float.contains(StartingmousePosition)) {
                            start_page.visible = false;
                            signup.isSignupVisible = true;
                        }
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

        window.display();
    }
    file_management::sizes_to_file();
    file_management::vectors_to_files();
    return 0;
}
