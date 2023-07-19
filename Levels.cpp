#include "Levels.h"
Levels :: Levels(){
	levelNo = 3;
	waveNo = 3;
	waveReset = true;
	font.loadFromFile("Fonts/Title.ttf");
	level.setFont(font);
	wave.setFont(font);
	n1.setFont(font);
	n2.setFont(font);
	levelbarText.loadFromFile("img/bar3.png");
	waveBarText.loadFromFile("img/bar.png");
	waveBar.setPosition(0, -71);
	levelBar.setPosition(570, -95);
	levelBar.setTexture(levelbarText);
	waveBar.setTexture(waveBarText);
	wave.setFont(font);
	n1.setString(to_string(waveNo));
	n1.setFillColor(Color::Black);
	n2.setFillColor(Color::Black);
	n2.setString(to_string(levelNo));
	n1.setPosition(125.5, 0.5);
	n2.setPosition(710, 0.5);
	wave.setString("WAVE : ");
	level.setString("LEVEL :");
	wave.setPosition(22.5, 0.5);
	level.setFillColor(Color::Black);
	wave.setFillColor(Color::Black);
	level.setPosition(590, 0.5);
	waveStart = 0;
	endPoint = 0;
}
void Levels:: display(RenderWindow& window) {
	n1.setString(to_string(waveNo));
	n2.setString(to_string(levelNo));
	window.draw(levelBar);
	window.draw(waveBar);
	window.draw(wave);
	window.draw(n1);
	window.draw(n2);
	window.draw(level);
}
void Levels ::arrangeIntoRectangle(Enemies**& invaders,int number){
	if (invaders != nullptr) {
		invaders[0]->sprite.setPosition(780.00 / ((number - 4) /2) - number, -400);
		for (int i = 1, row = 1; i < number;) {
			if (row == 1) {
				invaders[i]->sprite.setPosition(invaders[i - 1]->sprite.getPosition().x + 115, -400);
				i++;
				if (i >= ((number -4) /2)) row++;
			}
			else if (row == 2) {
				invaders[(number - 4) /2]->sprite.setPosition(invaders[0]->sprite.getPosition().x, invaders[0]->sprite.getPosition().y + 100);
				invaders[(number -4)/ 2 + 1]->sprite.setPosition(invaders[(number - 4) / 2 - 1]->sprite.getPosition().x, invaders[0]->sprite.getPosition().y + 100);
				row++;
				i += 2;
			}
			else if (row == 3){
				invaders[(number - 4) / 2 + 2]->sprite.setPosition(invaders[0]->sprite.getPosition().x, invaders[0]->sprite.getPosition().y + 200);
				invaders[(number - 4) / 2 + 3]->sprite.setPosition(invaders[(number - 4) / 2 - 1]->sprite.getPosition().x, invaders[0]->sprite.getPosition().y + 200);
				row++;
				i += 2;
			}
			else if (row == 4)
				invaders[i++]->sprite.setPosition(invaders[i-10]->sprite.getPosition().x, -100);
			endPoint = 80;
		}
	}
}
void Levels :: arrangeIntoTriangle(Enemies**& invaders, int number) {	
	invaders[0]->sprite.setPosition(360, -270);
	invaders[1]->sprite.setPosition(280, -210);
	invaders[2]->sprite.setPosition(440, -210);
	invaders[3]->sprite.setPosition(200, -150);
	invaders[4]->sprite.setPosition(520, -150);
	invaders[5]->sprite.setPosition(120, -80);
	invaders[6]->sprite.setPosition(600, -80);
	for (int i = 7; i < number; i++) {
		if(i == 7)
			invaders[i]->sprite.setPosition(invaders[5]->sprite.getPosition().x - number*3.7, invaders[5]->sprite.getPosition().y + 70);
		else
			invaders[i]->sprite.setPosition(invaders[i - 1]->sprite.getPosition().x + (37.5*35)/number, invaders[i - 1]->sprite.getPosition().y);
	}
	endPoint = 80;
}
void Levels::arrangeIntoDiamond(Enemies**& invaders, int number) {
	invaders[0]->sprite.setPosition(300, -500);
	for (int i = 1; i < number / 4; i++)
		invaders[i]->sprite.setPosition(invaders[i - 1]->sprite.getPosition().x - 70, invaders[i - 1]->sprite.getPosition().y + 50);
	for(int i = number/4;i<2* number/4;i++)
		invaders[i]->sprite.setPosition(invaders[i - 1]->sprite.getPosition().x + 70, invaders[i - 1]->sprite.getPosition().y + 50);
	for (int i = 2 * number / 4; i < 3 * number / 4; i++)
		invaders[i]->sprite.setPosition(invaders[i - 1]->sprite.getPosition().x + 70, invaders[i - 1]->sprite.getPosition().y - 50);
	for (int i = 3 * number / 4; i < number; i++)
		invaders[i]->sprite.setPosition(invaders[i - 1]->sprite.getPosition().x - 70, invaders[i - 1]->sprite.getPosition().y - 50);
	endPoint = 90;
}
void Levels::arrangeIntoCircle(Enemies**& invaders, int number) {
	for (int i = 0; i < number; i++) {
		float angle = i * ((2 * 3.1416) / number);
		float y =-480.00 / 2 + std::sin(angle) * 200;
		float x = 780.00 / 2 + std::cos(angle) * 250;
		invaders[i]->sprite.setPosition(x, y);
	}
	endPoint = 280;
}
void Levels::arrangeIntoCross(Enemies**& invaders, int number) {
	invaders[0]->sprite.setPosition(50, -500);
	invaders[number / 2]->sprite.setPosition(730, -500);
	if (invaders != nullptr) {
		for (int i = 1;i<number/2;i++)
			invaders[i]->sprite.setPosition(invaders[i - 1]->sprite.getPosition().x + 100, invaders[i - 1]->sprite.getPosition().y + 65);
		for (int i = number / 2 + 1; i < number; i++) 
			invaders[i]->sprite.setPosition(invaders[i - 1]->sprite.getPosition().x - 100, invaders[i - 1]->sprite.getPosition().y + 65);
		
	}
	endPoint = 70;
}
void Levels :: arrangeIntoHeart(Enemies**& invaders, int number) {
	invaders[0]->sprite.setPosition(390, -240);
	invaders[1]->sprite.setPosition(320, -300);
	invaders[2]->sprite.setPosition(460, -300);
	invaders[3]->sprite.setPosition(260, -360);
	invaders[4]->sprite.setPosition(520, -360);
	invaders[5]->sprite.setPosition(200, -420);
	invaders[6]->sprite.setPosition(570, -420);
	int no = (number - 7) / 2;
	for (int i = 7, count = 0; i < no + 7; i++, count++) {
		float angle = -1 * count * ((3.1416) / no);
		float y = -950.00 / 2 + std::sin(angle) * 120;
		float x = 420.00 / 2 + std::cos(angle) * 120;
		invaders[i]->sprite.setPosition(x, y);
	}
	for (int i = 7 + no, count = 0; i < number; i++,count++) {
		float angle = -1 * count * ((3.1416) / (number - (7 + no)));
		float y = -950 / 2 + std::sin(angle) * 120;
		float x = 1020.00 / 2 + std::cos(angle) * 120;
		invaders[i]->sprite.setPosition(x, y);
	}
	endPoint = 420;
}
void Levels::fillRectangle(Enemies**& invaders, int number) {
	float x = 780.00 / (number/4);
	float y = -500.00;
	for (int i = 0,inc1 = 0,j = 0; i < 4; i++) {
		for (int inc2 = 0; j < number/4; j++,i++) {
			invaders[i]->sprite.setPosition(x + inc2, y + inc1);
			inc2 += 115;
		}
		inc1 += 100;
		for (int inc2 = 0; j < 2 * number / 4; j++,i++) {
			invaders[i]->sprite.setPosition(x + inc2, y + inc1);
			inc2 += 115;
		}
		inc1 += 100;
		for (int inc2 = 0; j < 3 * number / 4; j++, i++) {
			invaders[i]->sprite.setPosition(x + inc2, y + inc1);
			inc2 += 115;
		}
		inc1 += 100;
		for (int inc2 = 0; j < 4 * number / 4; j++, i++) {
			invaders[i]->sprite.setPosition(x + inc2, y + inc1);
			inc2 += 115;
		}
		endPoint = 80;
	}
}
void Levels :: fillCircle(Enemies**&invaders, int number){
	int i = 0;
	for (i = 0; i < 3* number/4; i++) {
		float angle = i * ((2 * 3.1416) / (3*number/4));
		float y = -480.00 / 2 + std::sin(angle) * 200;
		float x = 780.00 / 2 + std::cos(angle) * 200;
		invaders[i]->sprite.setPosition(x, y);
	}
	for (i = 3 * number / 4; i < number; i++) {
		float angle = i * ((2 * 3.1416) / (number - 3*number/4));
		float y = -480.00 / 2 + std::sin(angle) * 100;
		float x = 780.00 / 2 + std::cos(angle) * 100;
		invaders[i]->sprite.setPosition(x, y);
	}
	endPoint = 280;
}
void Levels::fillDiamond(Enemies**& invaders, int number) {
	invaders[0]->sprite.setPosition(300, -500);
	for (int i = 1; i < (number-4) / 4; i++)
		invaders[i]->sprite.setPosition(invaders[i - 1]->sprite.getPosition().x - 70, invaders[i - 1]->sprite.getPosition().y + 50);
	for (int i = (number - 4) / 4; i < 2 * number / 4; i++)
		invaders[i]->sprite.setPosition(invaders[i - 1]->sprite.getPosition().x + 70, invaders[i - 1]->sprite.getPosition().y + 50);
	for (int i = 2 * (number - 4) / 4; i < 3 * number / 4; i++)
		invaders[i]->sprite.setPosition(invaders[i - 1]->sprite.getPosition().x + 70, invaders[i - 1]->sprite.getPosition().y - 50);
	for (int i = 3 * (number - 4) / 4; i < number-4; i++)
		invaders[i]->sprite.setPosition(invaders[i - 1]->sprite.getPosition().x - 70, invaders[i - 1]->sprite.getPosition().y - 50);
	endPoint = 90;
	invaders[(number-4)]->sprite.setPosition(370, -450);
	invaders[(number - 3)]->sprite.setPosition(240, -350);
	invaders[(number - 2)]->sprite.setPosition(500, -350);
	invaders[number - 1]->sprite.setPosition(370, -250);
}
void Levels :: fillTriangle(Enemies**& invaders, int number) {
	int a;
	for (int i = 0,row = 0,column = 0,spacing = 100; i < number; i++)
	{
		invaders[i]->sprite.setPosition(250 + column * 75 + spacing, -400 + row * 75);
		column++;
		column > row ? row++, column = -(row / 2),spacing -=20 : a = 0;
	}
	invaders[number - 1]->sprite.setPosition(250, -400 +75);
	endPoint = 80;
}
