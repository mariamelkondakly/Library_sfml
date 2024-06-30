#include "Materials.h"

Font essentials::title;
Font essentials::normal;
Font essentials::subtitle;

int colors::title[3] = {204, 85, 0};
int colors::warning[3] = { 139, 0, 0 };
int colors::navbackground[3] = { 139, 69, 19 };
int colors::success[3] = { 107, 142, 35 };
int colors::icon[3] = { 183, 65, 14 };
int colors::ntexts[3] = { 149, 69, 53 };



buttons::buttons(int posx,int posy, string buttonName) {
    essentials::essentials();
    button.setSize(Vector2f(200, 80));
    button.setFillColor(Color(210, 105, 30));
    button.setPosition(posx, posy);

    buttonText.setFont(essentials::normal);
    buttonText.setString(buttonName);
    buttonText.setPosition(posx+50, posy+20);
    buttonText.setFillColor(Color(245, 245, 220));
    button_float = button.getGlobalBounds();
}
void buttons::buttonDraw(RenderWindow& window) {
    window.draw(button);
    window.draw(buttonText);
}

texts::texts(int posx, int posy, string textContent,char isTitle, int colors[3]) {
    essentials::essentials();
    text.setString(textContent);
    text.setPosition(posx, posy);
    if (isTitle=='t') {
        text.setCharacterSize(90);
        text.setFont(essentials::title);
        text.setStyle(Text::Bold);
    }
    else if(isTitle=='n'){
        text.setCharacterSize(40);
        text.setFont(essentials::normal);
    }
    else if (isTitle == 'w') {
        text.setCharacterSize(25);
        text.setFont(essentials::normal);
    }
    else if (isTitle == 's') {
        text.setCharacterSize(60);
        text.setFont(essentials::subtitle);
    }
    text.setFillColor(sf::Color(static_cast<sf::Uint8>(colors[0]),
        static_cast<sf::Uint8>(colors[1]),
        static_cast<sf::Uint8>(colors[2])));

}

essentials::essentials() {
    essentials::normal.loadFromFile("BritishGreen.otf");
    essentials::title.loadFromFile("Claire Palmer Script.otf");
}

Circle::Circle(int posx, int posy, string textContent) {
    circle.setRadius(11);
    circle.setFillColor(Color(210, 105, 30, 128));
    circle.setPosition(posx, posy);
    circle.setOutlineThickness(1);
    circle.setOutlineColor(Color::White);

    label.setFont(essentials::normal);
    label.setString(textContent);
    label.setPosition(posx+50, posy-10);
    label.setCharacterSize(30);
    label.setFillColor(Color(149, 69, 53));

}

void Circle::circleDraw(RenderWindow& window) {
    window.draw(Circle::circle);
    window.draw(Circle::label);
}

TextField::TextField(int posx, int posy) {

    field.setSize(Vector2f(370, 40));
    //field.setFillColor(Color(255, 255, 255, 0));
    field.setPosition(posx, posy);
    field.setOutlineColor(Color(210, 105, 30));
    field.setOutlineThickness(-0.5);

    input.setFont(essentials::normal);
    input.setCharacterSize(30);
    input.setFillColor(sf::Color(245, 245, 220));
    input.setPosition(posx, posy-3);
}
void TextField::fieldDraw(RenderWindow& window) {
    window.draw(field);
    window.draw(input);
}




