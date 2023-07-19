#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"
using namespace sf;
class Collider
{
	int x, y;
	float top, left , width, height;
	Texture text;
	bool isBoom;
	float speed;
	Animation* animation;
	float timer;
	bool onScreen;
public:
	void move(float xSpeed);
	void swirl(float time);
	void moveOut();
	void moveIn(float x);
	void setScreen(bool flag);
	bool getScreen();
	void animate(float time);
	void display(RenderWindow& window);
	bool detectCollision(Collider& c);
	bool getBoom();
	void setAnimationPos(float x, float y);
	void setBoom(bool flag);
	Collider(std :: string filePath);
	~Collider();
	Sprite sprite;
	bool isCollided;
};

