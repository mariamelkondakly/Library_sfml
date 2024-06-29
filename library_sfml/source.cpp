#include <SFML/Graphics.hpp>
#include "welcome_page.h"
#include "file_management.h"

int main() {
    file_management::file_to_sizes();
    file_management::files_to_vectors();
    // Create the main window
    RenderWindow window(VideoMode(1800, 900), "Library", Style::Default);
    Texture backgroundTexture;
    backgroundTexture.loadFromFile("BackGround.png");
    Sprite background(backgroundTexture);

    // Create the welcome page
    welcome_page start_page;

    // Start the game loop
    while (window.isOpen()) {
        // Process events
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
        }

        // Clear the screen
        window.clear();

        // Draw the welcome page
        window.draw(background);
        start_page.draw_starting_page(window);

        // Update the window
        window.display();
    }

    return 0;
}
