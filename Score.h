#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
using namespace std;
using namespace sf;
class Score
{
	Font font;
	Text score;
	Text no;
	int number;
	Texture barText;
	Sprite bar;
public:
	Score();
	Score& operator += (int n) {
		number += n;
		return *this;
	}
	Score& operator =(int n) {
		number = n;
		return *this;
	}
	int returnScore();
	void display(RenderWindow& window);
};

