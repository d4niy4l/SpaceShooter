#include "Bomb.h"
Bomb :: Bomb() {
	tex.loadFromFile("img/bomb.png");
	sprite.setTexture(tex);
	sprite.setOrigin(25 * 0.5, 25 * 0.5);
	x = 0, y = 0;
}
Bomb::Bomb(std::string path) {
	tex.loadFromFile(path);
	sprite.setTexture(tex);
	sprite.setOrigin(25 * 0.5, 25 * 0.5);
	x = 0, y = 0;
}
bool Bomb::outOfBounds() {
	if (sprite.getPosition().y > 780.00)
		return true;
	return false;
}
void Bomb :: dropBomb() {
	sprite.move(0, 0.6);
}
bool Bomb::collidedWithPlayer() {
	return true;
}