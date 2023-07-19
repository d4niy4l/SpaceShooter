#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
class Bomb
{
	Texture tex;
	float x, y;
public:
	Sprite sprite;
	Bomb();
	Bomb(std::string path);
	bool outOfBounds();
	bool collidedWithPlayer();
	void dropBomb();
	
};

