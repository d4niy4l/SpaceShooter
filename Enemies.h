#pragma once
#include <iostream>
#include <string>
#include "Bomb.h"
#include <SFML/Audio.hpp>
#include "Beam.h"
#include "Bullet.h"
#include "Animation.h"
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf;
class Enemies
{
protected:
	bool dropbomb;
	int numberofBombs;
	Bomb** bomb;
	float timeDelay;
	float speed;
	int score;
	float moveDelay;
	Animation *animation;
public:
	bool isFiring;
	bool ascended;
	Beam* beam;
	bool showAnimation;
	float timer;
	sf :: Texture text;
	sf :: Sprite sprite;
	float x, y;
	Enemies(string pathName,float f,string animationPath, int x, int y, float time);
	void setNumBombs(int n) {
		numberofBombs = n;
	}
	int getNumBombs() {
		return numberofBombs;
	}
	float getTimeDelay() {
		return timeDelay;
	}
	void setAnimationShow(bool flag) {
		showAnimation = flag;
	}
	float getSpeed();
	Bomb**& returnBomb();
	Animation*& getAnimation() {
		return animation;
	}
	float& returnDelay() {
		return moveDelay;
	}
	virtual Beam*& getBeam() {
		return beam;
	}
	virtual int getScore() = 0;
	virtual void setScore(int n) = 0;
	virtual void animate(float time)  = 0;
	virtual bool detectCollision(Bullet& b) = 0;
	virtual void fireBomb(Bomb& b) {};
	virtual void Move(float time) = 0;
	virtual float returnTimeDelay() = 0;
	virtual void ascendEnemy() = 0;
	virtual void waveDescend() {};
	virtual bool hasAscended() = 0;
	virtual void enemyDescend() = 0;
	virtual bool HasDescended() = 0;
	virtual void fireBeam(int x) {}
	virtual string returnType() = 0;
	virtual void setText(int n){}
	virtual void display(RenderWindow& window) = 0;
	virtual ~Enemies() {}
	virtual bool getMove() = 0;
};

