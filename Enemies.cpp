#include "Enemies.h"
Enemies::Enemies(string pathName, float s,string animationPath,int x,int y,float time) {
	text.loadFromFile(pathName);
	sprite.setTexture(text);
	sprite.setOrigin(sprite.getTexture()->getSize().x * 0.5, sprite.getTexture()->getSize().y * 0.5);
	bomb = NULL;
	timeDelay = NULL;
	beam = nullptr;
	ascended = 1;
	numberofBombs = 0;
	dropbomb = 0;
	speed = s;
	score = 0;
	timer = 0;
	animation = new Animation(animationPath, time, x, y);
	showAnimation = 0;
	x = 0, y = 0;
}
float Enemies::getSpeed() {
	return speed;
}
Bomb**& Enemies :: returnBomb() {
	return bomb;
}
