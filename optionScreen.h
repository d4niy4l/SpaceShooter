#pragma once	
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
using namespace sf;
class optionScreen{
	Texture backgrounds[10];
	Font font;
	Text title;
	Text options[5];
	Text layout;
	Text musics[10];
	Text background[10];
	Texture ship;
	Sprite ship1;
	Sprite ship2;
	Text volume;
	int current;
	int vol;
	int noOfbackGrounds;
	int noOfMusic;
	int option;
public:
	optionScreen();
	void function(Event& event, Sprite& sprite, Music music[], int& layout,int& songno);
	void shipGoesUp();
	void shipGoesDown();
	void display(RenderWindow& window);
	bool isActive;
	bool goBack;
};

