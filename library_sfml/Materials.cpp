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
int colors::background[3] = { 245, 245, 220 };




buttons::buttons(int posx,int posy, string buttonName,bool isNav) {
    essentials::essentials();

    if (!isNav) {
        button.setSize(Vector2f(200, 80));
        button.setFillColor(Color(210, 105, 30, 128));
        button.setOutlineThickness(3);
        button.setOutlineColor(Color(210, 105, 30, 128));
        button.setPosition(posx, posy);

        buttonText.setFont(essentials::normal);
        buttonText.setString(buttonName);
        buttonText.setPosition(posx + 50, posy + 20);
        buttonText.setFillColor(Color(245, 245, 220));
        
    }
    else {
        button.setSize(Vector2f(100, 60));
        button.setFillColor(Color(210, 105, 30, 128));
        button.setPosition(posx, posy);

        buttonText.setFont(essentials::normal);
        buttonText.setLetterSpacing(1.25);
        buttonText.setString(buttonName);
        buttonText.setPosition(posx + 20, posy + 10);
        buttonText.setFillColor(Color(245, 245, 220));
    }
    button_float = button.getGlobalBounds();
}
void buttons::buttonDraw(RenderWindow& window) {
    window.draw(button);
    window.draw(buttonText);
}
void buttons::onUnHover() {
    button.setFillColor(Color(210, 105, 30, 128));
    button.setOutlineColor(Color(210, 105, 30, 128));
}
void buttons::onHover() {
    button.setFillColor(Color(210, 105, 30));
    button.setOutlineColor(Color(210, 105, 30));
}

texts::texts(int posx, int posy, string textContent,char isTitle, int colors[3]) {
    essentials::essentials();
    text.setString(textContent);
    text.setPosition(posx, posy);
    if (isTitle=='t') {
        text.setCharacterSize(80);
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
    circle.setOutlineThickness(3);
    circle.setOutlineColor(Color(210, 105, 30, 128));

    label.setFont(essentials::normal);
    label.setString(textContent);
    label.setPosition(posx+50, posy-10);
    label.setCharacterSize(30);
    label.setFillColor(Color(149, 69, 53));

    CheckFloat = circle.getGlobalBounds();

}

void Circle::circleDraw(RenderWindow& window) {
    window.draw(Circle::circle);
    window.draw(Circle::label);
}
void Circle::onCheck() {
    circle.setFillColor(Color(245, 245, 220));
}
void Circle::onUncheck() {
    circle.setFillColor(Color(210, 105, 30, 128));
}

TextField::TextField(int posx, int posy) {

    field.setSize(Vector2f(370, 40));
    field.setFillColor(Color(210, 105, 30, 128));
    field.setPosition(posx, posy);
    field.setOutlineColor(Color(210, 105, 30));
    field.setOutlineThickness(-0.5);

    input.setFont(essentials::normal);
    input.setCharacterSize(30);
    input.setFillColor(sf::Color(245, 245, 220));
    input.setPosition(posx, posy-3);
    fieldFloat = field.getGlobalBounds();
    inputEntered = false;

}
void TextField::fieldDraw(RenderWindow& window) {
    window.draw(field);
    window.draw(input);
}
void TextField::onselect() {
    input.setFillColor(Color(245, 245, 220));
    field.setFillColor(Color(210, 105, 30));
}
void TextField::onunselect() {
    input.setFillColor(sf::Color(245, 245, 220));
    field.setFillColor(Color(210, 105, 30, 128));
}

void TextField::inputHandelling(Event event, bool isPassword, TextField& field)
{
    if (event.text.unicode == 8)
    {
        //login
        if (field.data.size() > 0)
        {
            field.data.erase(field.data.end() - 1);

            if (isPassword) {
                field.input.setString(string(field.data.size(), '*'));
            }
            else {
                field.input.setString(field.data);
            }

        }
    }

    else if (event.text.unicode >= 32 && event.text.unicode < 127)
    {
        field.data += static_cast<char>(event.text.unicode);

        if (isPassword) {
            field.input.setString(string(field.data.size(), '*'));
        }
        else {
            field.input.setString(field.data);
        }
    }
        
        
}

photos::photos(string path, int posx, int posy,float scalex, float scaley) {
    picTexture.loadFromFile(path);
    pic.setTexture(picTexture);
    pic.setPosition(posx, posy);
    pic.setScale(scalex, scaley);
}