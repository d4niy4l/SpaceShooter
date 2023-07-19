#include "Monster.h"
Monster :: Monster() : Enemies("img/monster.png",0.5,"img/boom.png",3,4,0.03) {
	beamTime = 2;
	instance = 1;
	timer = 0;
	isFiring = false;
	beam = nullptr;
	IsDescended = 0;
	attackMode.loadFromFile("img/eyeOpen.png");
	sprite.setPosition(390, -200);
}
void Monster::fireBeam(int x) {
	if (IsDescended) {
		if (!isFiring && beamTime > 2.0) {
			sprite.setTexture(attackMode);
			beam = new Beam("img/laser.png");
			beam->sprite.setPosition(sprite.getPosition().x, sprite.getPosition().y + beam->sprite.getTexture()->getSize().y*0.65);
			isFiring = true;
			beamTime = 0;
		}
		else if (isFiring && beamTime > 5.0) {
			sprite.setTexture(text);
			delete beam;
			beam = nullptr;
			isFiring = false;
			beamTime = 0;
		}
	}
}
void Monster::Move(float time) {
	beamTime += time;
	if (instance == 1) {
		sprite.move(speed, 0);
		if(isFiring)
			beam->move(1);
	}
	else if (instance == 2) {
		sprite.move(-1 * speed, 0);
		if (isFiring)
			beam->move(2);
	}
	if (sprite.getPosition().x - sprite.getTexture()->getSize().x * 0.5 < 0 ) {
		//instance = 0;
		//moveDelay += time;
		//if (moveDelay >= 1.2) {
			instance--;
			//moveDelay = 0;
		//}
	}
	else if (sprite.getPosition().x + sprite.getTexture()->getSize().x * 0.5 > 780){
		//instance = 0;
		//moveDelay += time;
		//if (moveDelay >= 1.2) {
			//moveDelay = 0;
			instance++;
		//}
	}
}
void Monster :: ascendEnemy() {
	isFiring = 0;
	IsDescended = 0;
	sprite.move(0, -1);
}
void Monster::enemyDescend() {
	if (sprite.getPosition().y < 200.0)
		sprite.move(0, speed * 1);
	if (sprite.getPosition().y >= 200 && ascended == 1) {
		IsDescended = 1;
		ascended = 0;
	}

}
bool Monster ::detectCollision(Bullet& b){
	float wBullet = b.sprite.getOrigin().x;
	float hBullet = b.sprite.getOrigin().y;
	float wMonster = sprite.getOrigin().x;
	float hMonster = sprite.getOrigin().y;
	if (abs(sprite.getPosition().x - b.sprite.getPosition().x) + 70 < hBullet + hMonster && abs(sprite.getPosition().y - b.sprite.getPosition().y) < wBullet + wMonster)
		return true;
	return false;
}
void Monster::display(RenderWindow& window) {
	window.draw(sprite);

	if (isFiring)
		window.draw(getBeam()->sprite);
}
