#include "Animation.h"
Animation::Animation(std::string filePath, float timeDelay, int countX, int countY) {
	tex.loadFromFile(filePath);
	totalX = countX;
	totalY = countY;
	width = tex.getSize().x / countX;
	height = tex.getSize().y / countY;
	topLeft = 0.0;
	top = 0;
	delay = timeDelay;
	timer = 0;
	currentImageX = 0;
	currentImageY = 0;
	sprite.setTexture(tex);
	sprite.setOrigin(width * 0.5, height * 0.5);
	sprite.setTextureRect(sf :: IntRect(0, 0, width, height));
}
bool Animation::animationFinished() {
	if (currentImageX >= totalX && currentImageY >= totalY)
		return true;
	return false;
}
void Animation::revertToFirstFrame() {
	topLeft = 0.0;
	top = 0.0;
	currentImageX = 0;
	timer= 0;
	currentImageY = 0;
}
int Animation :: getXimage() {
	return currentImageX;
}
int Animation:: getYimage() {
	return currentImageY;
}
void Animation::upDateAnimation() {
	if (timer >= delay) {
		timer = 0;
		currentImageX++;
		if (currentImageY < totalY && currentImageX >= totalX) {
			currentImageY++;
			currentImageX = 0;
		}
		//if (currentImageX >= tex.getSize().x / width)
			//restartAnimation();
	}
	topLeft = currentImageX * width;
	top = currentImageY * height;
	sprite.setTextureRect(sf::IntRect(topLeft, top, width, height));
}
void Animation::loadAnimation(float x, float y) {
	sprite.setPosition(x, y);
}