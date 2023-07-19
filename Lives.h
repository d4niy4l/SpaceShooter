#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
class Lives
{
	int noOfLives;
	sf::Texture heart;
	Texture noheart;;
	Texture barText;
	Sprite bar;
	sf::Sprite hearts[3];
public:
	Lives();
	Lives& operator ++();
	int returnLives();
	Lives& operator --();
	void display(RenderWindow& window);
	void setLives(int n);
};

