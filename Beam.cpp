#include "Beam.h"
void Beam::move(int direction) {
	if (direction == 1)
		sprite.move(speed, 0);
	else if (direction == 2)
		sprite.move(speed * -1, 0);
}

Beam::Beam(std :: string pathName) {
	speed = 0.5;
	tex.loadFromFile(pathName);
	sprite.setTexture(tex);
	sprite.setOrigin(sprite.getTexture()->getSize().x * 0.5, sprite.getTexture()->getSize().y * 0.5);
	x = y = 0;
	
}
void Beam::colliderMove() {
	if (angle == -45)
		collider.move(-15 * 0.5, 15 * 0.866);
	else if (angle == 45)
		collider.move(15 * 0.5, 15 * 0.866);
	else
		collider.move(0, 15);
	if (collider.getPosition().y > 850) {
		if (angle == -45)
			collider.setPosition(340 + 40, 155);
		else if (angle == 45)
			collider.setPosition(360 + 15, 155);
		else 
			collider.setPosition(340 + 15, 160);

	}
}
Beam::Beam(int direction){
	if (direction == 0) {
		tex.loadFromFile("img/beam.png");
		colliderTex.loadFromFile("img/ufoBlue.png");
		collider.setTexture(colliderTex);
		this->direction = 0;
		angle  = 0;
	}
	else if (direction == 1) {
		tex.loadFromFile("img/leftBeam.png");
		colliderTex.loadFromFile("img/ufoBlue.png");
		collider.setTexture(colliderTex);
		this->direction = 1;
		angle = -45;
	}
	else if (direction == 2) {
		tex.loadFromFile("img/rightBeam.png");
		colliderTex.loadFromFile("img/ufoBlue.png");
		collider.setTexture(colliderTex);
		this->direction = 2;
		angle = 45;
	}
	sprite.setTexture(tex);
	speed = 0;
	x = y = 0;
}
void Beam::setPosition(int x, int y) {
	sprite.setPosition(x, y);
	collider.setPosition(x+ 300, y);
}
int Beam :: getDirection() {
	return direction;
}

