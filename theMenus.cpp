#include "theMenus.h"
bool theMenus ::  getIsMenu() {
	return isMenu;
}
theMenus::theMenus(bool flag,int op) {
	isMenu = flag;
	isScore = 0;
	options = op;
	optionNo = 0;
	isGame = 0;
	backgroundTex.loadFromFile("img/menuimg.jpg");
	backgroundTex.setRepeated(true);
	timer = 0;
	currentPos = 0;
	isExtra = 0;
	instructions = 0;
	isExit = 0;
	font.loadFromFile("Fonts/Title.ttf");
}
bool theMenus::getIsExit() {
	return isExit;
}
bool theMenus::getIsGame() {
	return isGame;
}
bool theMenus::getIsInstructions() {
	return instructions;
}
void  theMenus::setIsMenu(bool flag) {
	isMenu = flag;
}
void theMenus::setIsExit(bool flag) {
	isExit = flag;
}
void theMenus::setIsGame(bool flag) {
	isGame = flag;
}
void theMenus :: moveBackground(float time) {
	timer += time;
	if (timer > 0.01) {
		timer = 0;
		currentPos += 1;
	}
	background.setTextureRect(IntRect(currentPos, 0, 780, 820));
}
void theMenus::setIsInstructions(bool flag) {
	instructions = flag;
}
void theMenus :: setIsScore(bool flag) {
	isScore = flag;
}
bool theMenus::returnScore() {
	return isScore;
}
