#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>

using namespace std;
using namespace sf;



class Fonts {
public:
	Font titles,normal,subtitles;
	void initialize();
};

class buttons
{
public:
	
	buttons(float posx, float posy, string buttonName, bool isNav);
	buttons(float posx, float posy, string buttonName);
	buttons(float posx, float posy, string buttonName, int size);
	buttons();
	FloatRect button_float;
	RectangleShape button;
	Text buttonText;
	void buttonDraw(RenderWindow& window);
	void onHover();
	void onUnHover();
	void linksOnUnHover();
	void linksOnHover();

};



class texts {
public:
	Text text;
	texts(float posx, float posy, string textContent, char isTitle, int colors[3]);
	texts();
};

class colors {
public:
	static int title[3];
	static int warning[3];
	static int navbackground[3];
	static int success[3];
	static int icon[3];
	static int ntexts[3];
	static int background[3];


};

class Circle {
public:
	CircleShape circle;
	Text label;
	Circle(float posx, float posy, string textContent);
	void circleDraw(RenderWindow& window);
	FloatRect CheckFloat;
	void onCheck();
	void onUncheck();
};

class TextField {
public:
	RectangleShape field;
	Text input;
	string data;
	TextField(float posx, float posy);
	void fieldDraw(RenderWindow& window);
	FloatRect fieldFloat;
	void onselect();
	void onunselect();
	static void inputHandelling(Event event, bool isPassword, TextField& field);
	bool inputEntered;
};

class photos {
public:
	photos();
	photos(string path,float posx,float posy,float scalex, float scaley);
	Sprite pic;
	Texture picTexture;

	

};

