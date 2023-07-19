#include "highscoreScreen.h"
void  highscoreScreen :: display(RenderWindow& window) {
	window.draw(background);
	window.draw(title);
	for (int i = 0; i < 6; i++)
		window.draw(text[i]);
	window.draw(copper);
	window.draw(gold);
	window.draw(silver);
	window.draw(back);
}
highscoreScreen :: highscoreScreen() {
	fromMenu = 0;
	fromGameOver = 0;
	fromPause = 0;
	Backgroundtxt.loadFromFile("img/highscore.png");
	background.setTexture(Backgroundtxt);
	background.setScale(1.5, 1.5);
	font.loadFromFile("Fonts/title.ttf");
	title.setFont(font);
	title.setString("THE  HALL  OF  WARRIORS");
	title.setPosition(30, 100);
	title.setCharacterSize(60);
	back.setFont(font);
	for (int i = 0, yinc = 0,xinc = 0; i < 6;) {
		text[i].setFont(font);
		text[i].setPosition(180 + xinc, 300 + yinc);
		text[i].setCharacterSize(50);
		xinc += 320;
		text[i].setCharacterSize(35);
		if (i % 2 != 0) { yinc += 150, xinc = 0; }
		i++;
		//yinc += 175;
	}
	fstream file("scores.txt");
	string name;
	int score;
	for (int i = 0; file >> name >> score;) {
		if (i < 6) {
			text[i++].setString(name);
			text[i++].setString(to_string(score));
		}
		else break;
	}
	goldTex.loadFromFile("img/gold.png");
	silverTex.loadFromFile("img/silver.png");
	copperTex.loadFromFile("img/bronze.png");
	silver.setTexture(silverTex);
	gold.setTexture(goldTex);
	gold.setPosition(30, 280);
	copper.setTexture(copperTex);
	copper.setPosition(30, 580);
	silver.setPosition(30, 425);
	back.setString("BACK");
	back.setPosition(10, 780);
	back.setFillColor(Color::Red);
	isActive = 0;;
}
void highscoreScreen::update() {
	fstream file("scores.txt");
	string name;
	int score;
	for (int i = 0; file >> name >> score;) {
		if (i < 6) {
			text[i++].setString(name);
			text[i++].setString(to_string(score));
		}
	}

}
void highscoreScreen ::  function(Event& event) {
	if (event.type == Event::KeyReleased) {
		if (event.key.code == Keyboard::BackSpace)
			isActive = 0;
	}
}
bool highscoreScreen ::  getMenu() {
	return fromMenu;
}
bool highscoreScreen::getPause() {
	return fromPause;
}
bool highscoreScreen::getOver() {
	return fromGameOver;
}
void  highscoreScreen:: setMenu(bool flag) {
	fromMenu = flag;
}
void  highscoreScreen:: setPause(bool flag) {
	fromPause = flag;
}
void  highscoreScreen:: setOver(bool flag) {
	fromGameOver = flag;
}

