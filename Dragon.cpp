#include "Dragon.h"
Dragon::Dragon() : Enemies("img/dragon.png",0.4,"img/dragonEffect.png",3,4,0.09) {
	sprite.setTextureRect(IntRect(0, 0, sprite.getTexture()->getSize().x, sprite.getTexture()->getSize().y / 4.0));
	top = 0;
	sprite.setOrigin(0, 0);
	sprite.setPosition(320, -100);
	currentFrame = 0;
	warning = 0;
	direction = 0;
	animation = new Animation("img/light.png", 0.06, 4, 2);
	animation->sprite.setScale(2, 2);
	animation->sprite.setPosition(390, 0);
	flasher = new Animation("img/warnings.png", 0.1, 1, 2);
}
float Dragon::returnTimeDelay() {
	return timer;
}
void Dragon :: fireBeam(int x) {

	if (timeDelay > 2.0 && !isFiring) {
			warning = 0;
			beam = new Beam(direction);
			if (direction == 0) {
				beam->sprite.setPosition(340, 160);
				beam->collider.setPosition(340 + 15, 160);
			}
			else if (direction == 2) {
				beam->sprite.setPosition(360, 155);
				beam->collider.setPosition(360 + 15, 155);
			}
			else if (direction == 1) {
				beam->sprite.setPosition(35, 155);
				beam->collider.setPosition(340 + 40, 155);
			}
				isFiring = true;
				timeDelay = 0;
	}	
	if (timeDelay < 1 && !isFiring)
		detectPlayerLocation(x);
	else if (timeDelay < 3.0 && timeDelay > 1.0 && !isFiring) {
		warning = 1;
		if (direction == 0)
			flasher->sprite.setPosition(370, 500);
		else if(direction == 2)
			flasher->sprite.setPosition(700, 500);
		else if(direction == 1)
			flasher->sprite.setPosition(120, 500);
		flasher->upDateAnimation();
		if (flasher->animationFinished())
			flasher->restartAnimation();
	}
	else if (isFiring && timeDelay > 3.0) {
		//sprite.setTexture(text);
		delete beam;
		beam = nullptr;
		isFiring = 0;
		timeDelay = 0;
		flasher->restartAnimation();
	}
	if (isFiring)
		beam->colliderMove();
}
void Dragon :: Move(float time) {
	moveDelay += time;
	flasher->timer += time;
	animation->timer += time;
	timeDelay += time;
	timer += time;
	if (moveDelay > 0.12) {
		moveDelay = 0;
		currentFrame++;
		if (currentFrame > 3) {
			currentFrame = 0;
		}
	}
		top = (sprite.getTexture()->getSize().y / 4.0) * currentFrame;
		sprite.setTextureRect(IntRect(0, top, sprite.getTexture()->getSize().x, sprite.getTexture()->getSize().y / 4.0));
}
void Dragon:: animate(float time) {
	animation->timer += time;
	if (!animation->animationFinished())
		animation->upDateAnimation();
	if (animation->getXimage() == 2 && animation->getYimage() == 1) {
		animation->restartAnimation();
		showAnimation = 0;
	}
}
void Dragon:: ascendEnemy() {
	sprite.move(0, -0.3);
}
void Dragon :: waveDescend() {
	sprite.move(0, 0.5);
}
bool Dragon :: hasAscended() {
	if (sprite.getPosition().y <= -200)
		return true;
	return false;
} 
void Dragon :: enemyDescend() {
	showAnimation = 1;
	if (!animation->animationFinished())
		animation->upDateAnimation();
	sprite.move(0, 0.2);
}
void Dragon :: detectPlayerLocation(int x) {
	if (x > 0 && x <= 260)
		direction = 1;
	else if (x > 260 && x <= 520)
		direction = 0;
	else
		direction = 2;
}
bool Dragon :: HasDescended() {
	if (sprite.getPosition().y >= 70) {
		showAnimation = 0;
		return true;
	}
	return false;
}
int Dragon::getScore() {
	return 50;
}
void  Dragon::setScore(int n) {
	score = n;
}
bool Dragon :: detectCollision(Bullet& b){
	float wBullet = b.sprite.getOrigin().x;
	float hBullet = b.sprite.getOrigin().y;
	float hDragon = sprite.getTextureRect().height;
	float wDragon = sprite.getTextureRect().width;
	if ((sprite.getPosition().x + sprite.getTextureRect().width - 25 >= b.sprite.getPosition().x && sprite.getPosition().y + sprite.getTextureRect().height >= b.sprite.getPosition().y) && (sprite.getPosition().x + 20 <= b.sprite.getPosition().x + b.sprite.getTexture()->getSize().x && sprite.getPosition().y + 20 <= b.sprite.getPosition().y + b.sprite.getTexture()->getSize().y))
		return true;
	return false;
}
void Dragon :: display(RenderWindow& window) {
	if (showAnimation)
		window.draw(animation->sprite);
	if (isFiring) {
		window.draw(beam->sprite);
		//window.draw(beam->collider);
	}
	window.draw(sprite);
	if (warning)
		window.draw(flasher->sprite);
}