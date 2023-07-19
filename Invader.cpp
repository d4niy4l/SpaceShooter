#include "Invader.h"
bool Invader ::  detectCollision(Bullet& b) {
	float d = pow(pow(sprite.getPosition().x - b.sprite.getPosition().x, 2) + (pow(sprite.getPosition().y - b.sprite.getPosition().y, 2)), 0.5);
	float wBullet = b.sprite.getOrigin().x;
	float hBullet = b.sprite.getOrigin().y + 25.0;
	float wInvader = sprite.getOrigin().x + 37.5;
	float hInvader = sprite.getOrigin().y - 32.0;
	if (d < hBullet + hInvader && d < wBullet + wInvader)
		return true;
	return false;
}
 void Invader :: fireBomb(Bomb &b) {
	if (bomb == nullptr) {
		bomb = new Bomb * [1];
		bomb[0] = &b;
		numberofBombs += 1;
		bomb[0]->sprite.setPosition(sprite.getPosition().x, sprite.getPosition().y + 37.5);
	}
	else {
		Bomb** temp = bomb;
		bomb = new Bomb * [numberofBombs + 1];
		for (int i = 0; i < numberofBombs; i++)
			bomb[i] = temp[i];
		delete[] temp;
		bomb[numberofBombs] = &b;
		bomb[numberofBombs]->sprite.setPosition(sprite.getPosition().x, sprite.getPosition().y + 32);
		numberofBombs += 1;
	}
}
void Invader::Move(float time) {
	floattimer += time;
	if (moveDelay > 1.5){
		if (instance > 3) instance = 0;
		if (instance == 0)
			sprite.setPosition(sprite.getPosition().x + speed*20, sprite.getPosition().y);
		else if (instance == 1)
			sprite.setPosition(sprite.getPosition().x - speed * 20, sprite.getPosition().y);
		else if (instance == 2)
			sprite.setPosition(sprite.getPosition().x - speed * 20, sprite.getPosition().y);
		else if (instance == 3)
			sprite.setPosition(sprite.getPosition().x + speed * 20, sprite.getPosition().y);
		instance++;
		moveDelay = 0;
	}	
	if (floattimer > 5 && !timetomove && instance == 4) {
		x = sprite.getPosition().x;
		floattimer = 0;
		timetomove = 1;
		right = 1;
	}
	if (timetomove) {
		if (right)
			sprite.move(-0.5, 0);
		else if (left) 
			sprite.move(-0.5, 0);
		
	}
	if (sprite.getPosition().x <= x && left) timetomove = 0, left = right =  0,floattimer = 0;
	if (sprite.getPosition().x + 37.5 < 0) {
		right = 0;
		left = 1;
		sprite.setPosition(780 + 37.5, sprite.getPosition().y);
	}

}
float Invader :: returnTimeDelay() {
	return timeDelay;
}
void Invader::waveDescend() {
	sprite.move(0, 1.0);
}
void Invader :: ascendEnemy() {
	sprite.move(0, -1 * 0.5);
}
void Invader :: enemyDescend() {
	sprite.move(0, 0.5);
}
bool Invader::hasAscended() {
	if (sprite.getPosition().y <= y - 400)
		return true;
	return false;
}
void Invader :: display(RenderWindow& window) {
	window.draw(sprite);
}