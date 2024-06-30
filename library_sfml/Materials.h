#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>

using namespace std;
using namespace sf;

class buttons
{
public:
	RectangleShape button;
	Text buttonText;
	buttons(int posx, int posy, string buttonName, bool isNav);
	void buttonDraw(RenderWindow& window);
	void onHover();
	void onUnHover();
	FloatRect button_float;
};




class essentials {
public:
	static Font title, normal, subtitle;
	essentials();
};

class texts {
public:
	Text text;
	texts(int posx, int posy, string textContent, char isTitle, int colors[3]);
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
	Circle(int posx, int posy, string textContent);
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
	TextField(int posx, int posy);
	void fieldDraw(RenderWindow& window);
	FloatRect fieldFloat;
	void onselect();
	void onunselect();
	static void inputHandelling(Event event, bool isPassword, TextField& field);
	bool inputEntered;
};

class photos {
public:
	Texture picTexture;
	photos(string path,int posx,int posy,float scalex, float scaley);
	Sprite pic;
};

