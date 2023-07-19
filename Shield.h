#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
class Shield
{
	Texture tex;
public:
	Shield();
	void setPos(float x, float y);
	void display(RenderWindow& window);
	void move(float x, float y);
	void wrapSides();
	Sprite sprite;
};

