#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf;
class highscoreScreen
{
	bool isActive;
	Texture goldTex, silverTex, copperTex;
	Sprite gold, silver, copper;
	Texture Backgroundtxt;
	Sprite background;
	Font font;
	Text text[6];
	Text title;
	bool fromPause;
	Text back;
	public:
	void display(RenderWindow& window);
	bool fromGameOver;
	highscoreScreen();
	void update();
	void function(Event& event);
	void setActive(bool flag) {
		isActive = flag;
	}
	bool getActive() {
		return isActive;
	}
	bool getMenu();
	bool getPause();
	bool getOver();
	void setMenu(bool flag);
	void setPause(bool flag);
	void setOver(bool flag);
public:
	bool fromMenu;
};

