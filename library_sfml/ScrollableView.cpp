#include "ScrollableView.h"
sf::View Scrollable::view;
sf::RenderWindow* Scrollable::window = nullptr;
float Scrollable::upperBound;
float Scrollable::lowerBound;

void Scrollable::resetView() {
    view = window->getDefaultView();
    window->setView(view);
}

void Scrollable::handleScroll(sf::Event event) {
    if (event.type == sf::Event::MouseWheelScrolled) {
        if (event.mouseWheelScroll.delta > 0 && view.getCenter().y - view.getSize().y / 2 > upperBound) {
            view.move(0, -50); // Scroll up
        }
        else if (event.mouseWheelScroll.delta < 0 && view.getCenter().y + view.getSize().y / 2 < lowerBound) {
            view.move(0, 50); // Scroll down
        }
        window->setView(view);
    }
}
void Scrollable::setLowerBound(float lower) {
    lowerBound = lower;
}
void Scrollable::init(sf::RenderWindow* win, float upper) {
    window = win;
    view = window->getDefaultView();
    upperBound = upper;
    lowerBound = view.getSize().y; 
}
