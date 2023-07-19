#pragma once
#include "Enemies.h"
#include <SFML/Graphics.hpp>
#include <cmath>
using namespace sf;
class Levels
{
	int levelNo, waveNo;
	bool waveReset;
	bool waveStart;
	Font font;
	Text level;
	Text n1;
	Text n2;
	Texture levelbarText;
	Texture waveBarText;
	Text wave;
public:
	float endPoint;
	Sprite levelBar;
	Sprite waveBar;
	Levels();
	bool getWaveReset() {
		return waveReset;
	}
	void setWaveReset(bool flag) {
		waveReset = flag;
	}
	void setWaveNo(int n) {
		waveNo = n;
	}
	void setLevelNo(int n) {
		levelNo = n;
	}
	void addWaveNo(int n) {
		waveNo += n;
	}
	Levels& operator+=(int n) {
		levelNo += n;
	}
	int getLevelNo() {
		return levelNo;
	}
	int getWaveNo() {
		return waveNo;
	}
	bool getStart() {
		return waveStart;
	}
	void setStart(bool flag) {
		waveStart = flag;
	}
	void arrangeIntoRectangle(Enemies**& invader,int number);
	void arrangeIntoCross(Enemies**& invaders, int number);
	void arrangeIntoTriangle(Enemies**& invaders, int number);
	void arrangeIntoDiamond(Enemies**& invaders, int number);
	void arrangeIntoCircle(Enemies**& invaders, int number);
	void arrangeIntoHeart(Enemies**& invaders, int number);
	void fillRectangle(Enemies**&, int number);
	void fillCircle(Enemies**& invaders, int number);
	void fillDiamond(Enemies**& invaders, int number);
	void display(RenderWindow& window);
	void fillTriangle(Enemies**& invaders, int number);
};

