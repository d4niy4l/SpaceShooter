#include "Score.h"
void Score::display(RenderWindow& window) {
	no.setString(to_string(number));
	window.draw(bar);
	window.draw(no);
	window.draw(score);
}
Score::Score() {
	number = 0;
	barText.loadFromFile("img/ScoreBar.png");
	bar.setTexture(barText);
	bar.setScale(1.5, 1);
	font.loadFromFile("Fonts/Title.ttf");
	no.setFont(font);
	score.setFont(font);
	score.setString("SCORE : ");
	score.setFillColor(Color::Black);
	score.setPosition(550, 770);
	no.setString(to_string(number));
	no.setFillColor(Color::Black);
	no.setPosition(660, 770);
	bar.setPosition(520, 690);
}
int Score::returnScore() {
	return number;
}