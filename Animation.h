#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
class Animation
{
	int currentImageX;
	int totalX;
	int currentImageY;
	int totalY;
	float width;
	float height;
	float topLeft;
	float top;
	sf::Texture tex;
public:
	float timer;
	float delay;
	sf::Sprite sprite;
	Animation(std::string filePath, float timeDelay,int countX, int countY);
	void loadAnimation(float x, float y);
	void upDateAnimation();
	int getXimage();
	int getYimage();
	void revertToFirstFrame();
	void restartAnimation() {
		//if (currentImageX >= tex.getSize().x / width) {
			topLeft = 0;
			top = 0;
			currentImageX = 0;
			currentImageY = 0;
			timer = 0;
		
	}
	bool animationFinished();

};

