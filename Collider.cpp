#include "Collider.h"
void Collider::move(float xSpeed) {
	sprite.move(xSpeed, 0);
}
void Collider::swirl(float time) {
	timer += time;
	if (timer > 0.09) {
		timer = 0;
		x++;
		if (x >= 3) {
			x = 0;
			y++;
		}
		if (y >= 3) {
			y = 0;
			x = 0;
		}
	}
	left = (sprite.getTexture()->getSize().y / 3.0) * x;
	top = (sprite.getTexture()->getSize().y / 3.0) * y;
	sprite.setTextureRect(IntRect(left, top, width, height));
}
void Collider::moveOut() {
	animation->restartAnimation();
	sprite.setPosition(-300, -1000);
}
void Collider::moveIn(float x) {
	sprite.setPosition(x, 100);
}
void Collider::setScreen(bool flag) {
	onScreen = flag;
}
bool Collider::getScreen() {
	return onScreen;
}
void Collider ::  animate(float time) {
	animation->timer += time;
	if (!animation->animationFinished())
		animation->upDateAnimation();
	if(animation->getXimage() == 3 && animation->getYimage() == 5) {
		isBoom = 0;
	}
}
void Collider ::  display(RenderWindow& window) {
	if(!isCollided)
		window.draw(sprite);
	if (isBoom) {
		window.draw(animation->sprite);
	}
}
Collider :: Collider(std :: string filePath) {
	isCollided = 0;
	x = y = 0;
	text.loadFromFile(filePath);
	sprite.setTexture(text);
	sprite.setPosition(-500, -500);
	width = sprite.getTexture()->getSize().x / 3;
	height = sprite.getTexture()->getSize().y / 3;
	top = 0;
	left = 0;
	sprite.setTextureRect(IntRect(0, 0, width, height));
	animation = new Animation("img/colliderBoom.png", 0.05, 4, 5);
	isBoom = false;
	onScreen = false;
	animation->sprite.setScale(2.5, 3);
	speed = 0.5;
	timer = 0;
}
void Collider :: setAnimationPos(float x, float y) {
	animation->sprite.setPosition(390, 190);
}
Collider :: ~Collider() {
	delete animation;
}
bool Collider::detectCollision(Collider& c) {
	if(sprite.getPosition().x + sprite.getTextureRect().width + 160 >= c.sprite.getPosition().x + c.sprite.getTextureRect().width)
		return true;
	return false;
}
bool Collider::getBoom() {
	return isBoom;
}
void Collider::setBoom(bool flag) {
	isBoom = flag;
}