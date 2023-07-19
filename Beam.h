#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
class Beam
{
	Texture tex;
	int direction;
	float x, y;
	float angle;
	float speed;
public:
	Sprite sprite;
	Beam(std::string pathName);
	Beam(int direction);
	void move(int direction);
	void colliderMove();
	int getDirection();
	void setPosition(int x, int y);
	void display(RenderWindow& window) {
		window.draw(sprite);
	}
private :
	Texture colliderTex;
public:
	Sprite collider;
};

