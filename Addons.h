#pragma once
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
using std::string;
using namespace sf;
class Addons
{
	int type;
	Texture tex;
	float speed;
public:
	Sprite sprite;
	Addons(int type,std :: string path);
	virtual string returnType() = 0;
	virtual void manipulateSpaceship(bool& flag) = 0;
	virtual void move();
	bool outofBounds();
};

