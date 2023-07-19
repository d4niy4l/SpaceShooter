#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
class HelpScreen
{
	Texture back;
	Sprite background;
	Text text[3];
	Sprite space;
	Font font;
	Sprite arrowKeys;
	Texture arrowText;
	Texture wasdTExt;
	Sprite wasd;
	bool active;
	bool frommenu;
	bool fromover;
	bool frompause;
	Texture spacebar;
public:
	HelpScreen();
	void setActive(bool flag);
	bool getActive();
	void setMenu(bool flag);
	bool getMenu();
	void setPause(bool flag);
	bool getPause();
	void setOver(bool flag);
	bool getOver();
	void display(RenderWindow& window);
	void function(Event& event);

};

