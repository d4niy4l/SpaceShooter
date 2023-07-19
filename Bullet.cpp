#include "Bullet.h"
Bullet::Bullet(std :: string direction) {
	if (direction == "rocket") {
		angle = 0;
		text.loadFromFile("img/rocket.png");
		isFire = 1;
	}
	else if (direction == "rocket2") {
		angle = -45;
		text.loadFromFile("img/rocket2.png");
		isFire = 1;
	}
	else if (direction == "rocket1") {
		angle = 45;
		text.loadFromFile("img/rocket1.png");
		isFire = 1;
	}
	else if (direction == "rocket3") {
		angle = 135;
		text.loadFromFile("img/rocket3.png");
		isFire = 1;
	}
	else if (direction == "rocket4") {
		angle = 135;
		text.loadFromFile("img/rocket4.png");
		isFire = 1;
	}
	else if (direction == "leftUp") {
		angle = -45;
		text.loadFromFile("img/left.png");
		isFire = 0;
	}
	else if (direction == "rightUp") {
		text.loadFromFile("img/right.png");
		angle = 45;
		isFire = 0;
	}
	else if (direction == "leftDown") {
		text.loadFromFile("img/right.png");
		angle = -135;
		isFire = 0;
	}
	else if (direction == "rightDown") {
		text.loadFromFile("img/left.png");
		angle = 135;
		isFire = 0;
	}
	else if (direction == "30") {
		text.loadFromFile("img/30.png");
		angle = 30;
		isFire = 0;
	}
	else if (direction == "15") {
		text.loadFromFile("img/15.png");
		angle = 15;
		isFire = 0;
	}
	else if (direction == "-30") {
		text.loadFromFile("img/-30.png");
		angle = -30;
		isFire = 0;
	}
	else if (direction == "-15") {
		text.loadFromFile("img/-15.png");
		angle = -15;
		isFire = 0;
	}
	else if (direction == "60") {
		text.loadFromFile("img/60.png");
		angle = 60;
		isFire = 0;
	}
	else if (direction == "-60") {
		text.loadFromFile("img/-60.png");
		angle = -60;
		isFire = 0;
	}
	else if (direction == "-90") {
		text.loadFromFile("img/0.png");
		angle = -90;
		isFire = 0;
	}
	else if (direction == "90") {
		text.loadFromFile("img/0.png");
		angle = 90;
		isFire = 0;
	}
	else if (direction == "75") {
		text.loadFromFile("img/75.png");
		angle = 75;
		isFire = 0;
	}
	else if (direction == "-75") {
		text.loadFromFile("img/-75.png");
		angle = -75;
		isFire = 0;
	}
	else {
		text.loadFromFile("img/greenLaser.png");
		angle = 0;
		isFire = 0;
	}
	sprite.setTexture(text);
	sprite.setOrigin(25, 25);
	x = 0;
	y = 0;
	isCollided = 0;
}
bool& Bullet :: getIsFire() {
	return isFire;
}
void Bullet :: move(){
	if (angle == 45)
		sprite.move(0.707 * 1.2, 0.707 * -1.2);
	else if (angle == -45)
		sprite.move(0.707 * -1.2, 0.707 * -1.2);
	else if (angle == 135)
		sprite.move(0.707 * 1.2, 0.707 * 1.2);
	else if (angle == -135)
		sprite.move(0.707 * -1.2, 0.707 * 1.2);
	else if (angle == -15)
		sprite.move(0.258 * -1.2, 0.96 * -1.2);
	else if (angle == 15)
		sprite.move(0.258 * 1.2, 0.96 * -1.2);
	else if (angle == -30)
		sprite.move(0.5 * -1.2, 0.866 * -1.2);
	else if (angle == 30)
		sprite.move(0.5 * 1.2, 0.866 * -1.2);
	else if (angle == -20)
		sprite.move(0.939 * -1.2, 0.34 * -1.2);
	else if (angle == 20)
		sprite.move(0.939 * 1.2, 0.34 * -1.2);
	else if (angle == -60)
		sprite.move(0.866 * -1.2, 0.5 * -1.2);
	else if (angle == 60)
		sprite.move(0.866 * 1.2, 0.5 * -1.2);
	else if (angle == -75)
		sprite.move(0.96 * -1.2, 0.258 * -1.2);
	else if (angle == 75)
		sprite.move(0.96 * 1.2, 0.258 * -1.2);
	else if (angle == -90)
		sprite.move(-1.2, 0);
	else if (angle == 90)
		sprite.move(1.2, 0);
	else
		sprite.move(0, -1.2);
}

bool Bullet :: outOfBounds() {
	if (sprite.getPosition().y < 0.000)
		return true;
	return false;
}
void Bullet::destroyBullet() {
	delete this;
}
void Bullet :: changeSprite(std :: string direction) {
	if (direction == "leftUp")
		text.loadFromFile("img/left.png");
	else if (direction == "rightUp")
		text.loadFromFile("img/right.png");
	else if (direction == "leftDown")
		text.loadFromFile("img/right.png");
	else if (direction == "rightDown")
		text.loadFromFile("img/left.png");
	sprite.setTexture(text);
	sprite.setOrigin(25, 25);
}