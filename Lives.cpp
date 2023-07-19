#include "Lives.h"
Lives :: Lives() {
	noOfLives = 3;
	heart.loadFromFile("img/life.png");
	noheart.loadFromFile("img/noLife.png");
	barText.loadFromFile("img/livesBar.png");
	bar.setTexture(barText);
	bar.setScale(0.8, 0.74);
	bar.setPosition(0, 760);
	for (int i = 0,increment = 0; i < 3; i++,increment += 60) {
		hearts[i].setTexture(heart);
		hearts[i].setScale(0.9, 0.75);
		hearts[i].setPosition(70 + increment, 775);
	}
}
Lives& Lives :: operator ++() {
	if (noOfLives < 3) {
		noOfLives += 1;
		hearts[noOfLives - 1].setTexture(heart);
	}
	return *this;
}
void Lives::setLives(int n) {
	noOfLives = n;
}
Lives& Lives :: operator --() {
	if (noOfLives > 0) {
		hearts[noOfLives - 1].setTexture(noheart);
		noOfLives -= 1;
	}
	return *this;
}
void Lives::display(RenderWindow& window) {
	window.draw(bar);
	for (int i = 0; i < 3; i++)
		window.draw(hearts[i]);
}
int Lives :: returnLives() {
	return noOfLives;
}