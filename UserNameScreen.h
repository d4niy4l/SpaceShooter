#pragma once
#include "Animation.h"
#include <iostream>
using namespace std;
#include <string>
#include <SFML/Graphics.hpp>
using namespace sf;
class UserNameScreen
{
	string name;
	bool isActive;
	bool nameEntered;
	Font font;
	Text title;
	Text enteredName;
	Animation* animation;
public:
	UserNameScreen();
	void display(RenderWindow& window);
	void functioning(Event& event);
	string returnString();
	bool getActive();
	void setActive(bool flag);
	bool getnameEntered() {
		return nameEntered;
	}
	void setNameEntered(bool flag) {
		nameEntered = flag;
	}
	void resetString();
	void animate(float time);
};

