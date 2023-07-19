#include "HelpScreen.h"
HelpScreen::HelpScreen() {
	active = 0;
	frommenu = 0;
	frompause = 0;
	fromover = 0;
	back.loadFromFile("img/highscore.png");
	background.setTexture(back);
	background.setScale(2, 2);
	font.loadFromFile("Fonts/title.ttf");
	for (int i = 0; i < 3; i++)
		text[i].setFont(font);
	text[0].setPosition(100, 75);
	text[0].setString("USE  WASD  OR  ARROW  KEYS  TO  MOVE ");
	spacebar.loadFromFile("img/spacebar.png");
	wasdTExt.loadFromFile("img/wasd.png");
	wasd.setTexture(wasdTExt);
	space.setTexture(spacebar);
	arrowText.loadFromFile("img/arrowkeys.png");
	arrowKeys.setTexture(arrowText);
	text[1].setString("USE  SPACEBAR  TO  SHOOT");
	space.setPosition(230, 325);
	wasd.setPosition(20, 125);
	space.setScale(1.5,1.5);
	arrowKeys.setPosition(550, 125);
	text[1].setPosition(190, 325);
	text[2].setString("DESTORY INVADERS, AVOID MONSTER AND DRAGON\n USE POWER UPS AND SAVE\nTHE GALAXY");
	text[2].setPosition(10, 600);


}
void HelpScreen::display(RenderWindow& window) {
	window.draw(background);
	window.draw(wasd);
	window.draw(arrowKeys);
	window.draw(space);
	for (int i = 0; i < 3; i++)
		window.draw(text[i]);
}
void HelpScreen::function(Event& event) {
	if (event.type == Event::KeyReleased) {
		if (event.key.code == Keyboard::BackSpace)
			active = 0;
	}
}
void HelpScreen ::setActive (bool flag) {
	active = flag;
}
bool HelpScreen::getActive() {
	return active;
}
void HelpScreen::setMenu(bool flag) {
	frommenu = flag;
}
bool HelpScreen::getMenu() {
	return frommenu;
}
void HelpScreen::setPause(bool flag) {
	frompause = flag;
}
bool HelpScreen::getPause() {
	return frompause;
}
void HelpScreen::setOver(bool flag) {
	fromover = flag;
}
bool HelpScreen::getOver() {
	return fromover;
}