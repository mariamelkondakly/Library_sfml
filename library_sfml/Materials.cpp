#include "Materials.h"

Font essentials::title;
Font essentials::normal;
Font essentials::subtitle;


buttons::buttons(int posx,int posy, string buttonName) {
    essentials::essentials();
    button.setSize(Vector2f(200, 80));
    button.setFillColor(Color(0, 141, 220, 128));
    button.setPosition(posx, posy);
    button.setOutlineColor(Color::White);
    button.setOutlineThickness(2);

    buttonText.setFont(essentials::normal);
    buttonText.setString(buttonName);
    buttonText.setPosition(posx+50, posy+20);

}

texts::texts(int posx, int posy, string textContent,char isTitle) {
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
    else if (isTitle == 's') {
        text.setCharacterSize(60);
        text.setFont(essentials::subtitle);
    }
    
}

essentials::essentials() {
    essentials::normal.loadFromFile("BritishGreen.otf");
    essentials::title.loadFromFile("Claire Palmer Script.otf");
}

void buttons::buttonDraw(RenderWindow& window) {
    window.draw(button);
    window.draw(buttonText);
}


