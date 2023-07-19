#include "Addons.h"
Addons::Addons(int type,std :: string path){
	this->type = type;
	tex.loadFromFile(path);
	sprite.setTexture(tex);
	speed = 0.3;
	sprite.setOrigin(sprite.getTexture()->getSize().x * 0.5, sprite.getTexture()->getSize().y * 0.5);
	srand(time(0));
	sprite.setPosition(rand() % 700 + 10, -50);
}
void Addons::move() {
	sprite.move(0,  speed);
}
bool Addons ::  outofBounds() {
	if (sprite.getPosition().y >= 850)
		return true;
	return false;
}