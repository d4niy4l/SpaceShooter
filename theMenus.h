#pragma once
#include "SFML/Graphics.hpp"
using namespace sf;
class theMenus
{
protected:
	int options;
	int optionNo;
	float timer;
	float currentPos;
	Texture backgroundTex;
	Sprite background;

	Font font;
	bool isMenu;
	bool isGame;
	bool isExtra;
	bool instructions;
	bool isScore;
	bool isExit;
public:
	theMenus(bool flag,int op);
	virtual void displayMenu(RenderWindow& window) = 0;
	virtual void menuFunction(Event& e) = 0;
	virtual void playAnimation(float time) = 0;
	bool getIsMenu();
	bool getIsExit();
	virtual bool getIsExtra() = 0;
	bool getIsGame();
	bool getIsInstructions();
	void setIsMenu(bool flag);
	void setIsExit(bool flag);
	virtual void moveBackground(float time);
	void setIsScore(bool flag);
	bool returnScore();
	virtual void setIsExtra(bool flag) = 0;
	void setIsGame(bool flag);
	void setIsInstructions(bool flag);
	virtual ~theMenus() {};
};

