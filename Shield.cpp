#include "Shield.h"
Shield::Shield() {
	tex.loadFromFile("img/shield.png");
	sprite.setTexture(tex);
	sprite.setOrigin(66.5, 54);
	sprite.setPosition(666, 555);
}
void Shield :: setPos(float x, float y) {
	sprite.setPosition(x, y);
}
void Shield::display(RenderWindow& window) {
	window.draw(sprite);
}
void Shield :: move(float x, float y) {
	sprite.move(x, y);
	wrapSides();
}
void Shield :: wrapSides() {
	if (sprite.getPosition().x + 66.5 < 0) sprite.setPosition(780 - 66.5, sprite.getPosition().y);
	else if (sprite.getPosition().x - 66.6 > 780) sprite.setPosition(0 + 66.5, sprite.getPosition().y);
	if (sprite.getPosition().y + 54 < 0) sprite.setPosition(sprite.getPosition().x, 780 - 54);
	else if (sprite.getPosition().y - 54 > 830) sprite.setPosition(sprite.getPosition().x, 0 +  54);
}