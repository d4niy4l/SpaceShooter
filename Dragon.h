#pragma once
#include "Enemies.h"
class Dragon : public Enemies
{
	int currentFrame;
	float top;
	int direction;
public:
	bool warning;
	Animation* flasher;
	Dragon();
	void Move(float time);
	void animate(float time);
	virtual int getScore();
	virtual void setScore(int n);
	virtual void ascendEnemy();
	virtual void fireBeam(int x);
	virtual void waveDescend();
	virtual bool hasAscended();
	virtual bool detectCollision(Bullet& b);
	virtual void enemyDescend();
	string returnType() { return "dragon"; }
	virtual bool HasDescended();
	void display(RenderWindow& window);
	void detectPlayerLocation(int x);
	float returnTimeDelay();
	virtual bool getMove() { return warning; }
	virtual ~Dragon() {
		delete animation;
	}
};

