#pragma once
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
using namespace sf;
class Bullet
{
	float angle;
	bool isFire;
	float x;
	float y;
	Texture text;
public:
	Sprite sprite;
	bool isCollided;
public:
	Bullet(std :: string direction = "");
	bool outOfBounds();
	void move();
	void destroyBullet();
	void changeSprite(std::string direction);
	void setAngle(float ang) {
		angle = ang;
	}
	bool& getIsFire();
	float getAngle() const {
		return angle;
	}
};

