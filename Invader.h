#pragma once
#include <cmath>

#include "Enemies.h"
class Invader : public Enemies
{
protected:
	bool timetomove;
	bool left, right;
	SoundBuffer explosion;
	Sound explode;
	int instance;
	float floattimer;
public:
	Invader(string pathName,int s) : Enemies(pathName,0.5,"img/explosion.png",4,1,0.06) {
		timer = 0;
		sprite.setOrigin(37.5, 32);
		instance = 0;
		floattimer = 0;
		explosion.loadFromFile("Music/vineboom.ogg");
		explode.setBuffer(explosion);
		timetomove = 0;
		left = 0, right = 0;
		moveDelay = 0;
		score = s;
	}
	
	void fireBomb(Bomb& b);
	void Move(float time);
	bool detectCollision(Bullet& b);
	float returnTimeDelay();
	void animate(float time) {
		animation->timer += time;
		animation->upDateAnimation();
		showAnimation = 1;
	}
	virtual string returnType() = 0;
	virtual int getScore() = 0;
	void waveDescend();
	void setScore(int n) {
		score = n;
	}
	virtual ~Invader() {
		
	}
	bool HasDescended() {
		if (sprite.getPosition().y >= this->y)
			return true;
		return false;
	}
	void ascendEnemy();
	void enemyDescend();
	virtual bool getMove() { return timetomove; }
	bool hasAscended();
	void display(RenderWindow& window);
};
class Alpha : public Invader{
	string type;
public:
	Alpha() : Invader("img/alpha.png",10) {
		timeDelay = 5.0;
		type = "alpha";
	}
	virtual int getScore() {
		return 10;
	}
	string returnType() {
		return "alpha";
	}
	~Alpha() {
		delete bomb;
		delete animation;
	}
	
};
class Beta : public Invader {
	string type;
public:
	Beta() : Invader("img/beta.png",20) {
		timeDelay = 3.0;
		type = "beta";
	}
	virtual int getScore() {
		return 20;
	}
	string returnType() {
		return "beta";
	}
	~Beta() {
		delete bomb;
		delete animation;
	}
};
class Gamma : public Invader {
	string type;
public:
	Gamma() : Invader("img/gamma.png",30){
		timeDelay = 2.0;
		type = "gamma";
	}
	virtual int getScore() {
		return 30;
	}
	string returnType() {
		return "gamma";
	}
	~Gamma() {
		delete bomb;
		delete animation;
	}
};

