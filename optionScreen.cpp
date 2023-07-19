#include "optionScreen.h"
void optionScreen::function(Event& event, Sprite& sprite, Music music[],int& layout,int& songno) {
	if (event.type == Event::KeyReleased) {
		if (event.key.code == Keyboard::Up) {
			if (option > 0) {
				options[option].setFillColor(Color::White);
				option--;
				options[option].setFillColor(Color::Red);
			}
		}
		if (event.key.code == Keyboard::Down) {
			if (option < 4) {
				options[option].setFillColor(Color::White);
				option++;
				options[option].setFillColor(Color::Red);
			}
		}
		if (event.key.code == Keyboard::Right && option == 0) {
			if (noOfbackGrounds < 9) {
				noOfbackGrounds++;
				sprite.setTexture(backgrounds[noOfbackGrounds]);
			}
		}
		else if (event.key.code == Keyboard::Left && option == 0) {
			if (noOfbackGrounds > 0) {
				noOfbackGrounds--;
				sprite.setTexture(backgrounds[noOfbackGrounds]);
			}
		}
		if (event.key.code == Keyboard::Right && option == 1) {
			if (noOfMusic < 9) {
				music[noOfMusic].stop();
				noOfMusic++;
				songno = noOfMusic;
				music[noOfMusic].play();
			}
		}
		else if (event.key.code == Keyboard::Left && option == 1) {
			if (noOfMusic > 0) {
				music[noOfMusic].stop();
				noOfMusic--;
				songno = noOfMusic;
				music[noOfMusic].play();
			}
		}
		
		if (event.key.code == Keyboard::Left && option == 3) {
			if (layout > 1) {
				layout--;
				current = layout;
			}
		}
		else if (event.key.code == Keyboard::Right && option == 3) {
			if (layout < 2) {
				layout++;
				current = layout;
			}
		}
		if (event.key.code == Keyboard::Return && option == 4) {
			isActive = 0;
			option = 0;
			options[4].setFillColor(Color::White);
			goBack = 1;
		}
	}
	else if (event.type == Event::KeyPressed) {
		if (event.key.code == Keyboard::Left && option == 2) {
			if (vol > 0) {
				vol--;
				for (int i = 0; i < 5; i++) music[i].setVolume(vol);
			}
		}
		else if (event.key.code == Keyboard::Right && option == 2) {
			if (vol < 100) {
				vol++;
				for (int i = 0; i < 5; i++) music[i].setVolume(vol);
			}
		}
	}
}
void optionScreen::shipGoesUp() {

}
void optionScreen::shipGoesDown() {

}
optionScreen::optionScreen() {
	current = 1;
	isActive = 0;
	vol = 100;
	option = 0;
	goBack = 0;
	font.loadFromFile("Fonts/Title.ttf");
	noOfbackGrounds = 0;
	noOfMusic = 0;
	title.setFont(font);
	title.setPosition(270, 30);
	title.setString("OPTIONS");
	title.setCharacterSize(60);
	title.setFillColor(Color::White);
	for (int i = 0; i < 10; i++) {
		options[i].setFont(font);
		options[i].setCharacterSize(37);
	}
	options[0].setFillColor(Color::Red);
	options[0].setPosition(100, 200);
	options[1].setPosition(100, 325);
	options[2].setPosition(100, 450);
	options[0].setString("BACKGROUND");
	options[1].setString("MUSIC");
	options[2].setString("VOLUME");
	options[4].setPosition(300, 700);
	options[3].setPosition(100, 575);
	options[3].setString("CONTROLS");
	options[4].setString("BACK");
	layout.setFont(font);
	layout.setCharacterSize(37);
	layout.setString(std::to_string(1));
	layout.setPosition(450, 575);
	volume.setFont(font);
	volume.setString(std::to_string(vol));
	volume.setPosition(450, 450);
	volume.setCharacterSize(37);
	for (int i = 0; i < 10; i++) {
		std :: string s1 = "BACKGROUND ", s2 = "TRACK ";
		s2 += std::to_string(i + 1);
		s1 += std::to_string(i + 1);
		background[i].setFont(font);
		background[i].setString(s1);
		background[i].setPosition(450, 200);
		background[i].setCharacterSize(37);
		musics[i].setFont(font);
		musics[i].setString(s2);
		musics[i].setPosition(450, 325);
		musics[i].setCharacterSize(37);
	}
	backgrounds[1].loadFromFile("img/back10.png");
	backgrounds[2].loadFromFile("img/back2.png");
	backgrounds[3].loadFromFile("img/back3.jpg");
	backgrounds[4].loadFromFile("img/back4.jpg");
	backgrounds[5].loadFromFile("img/back5.jpeg");
	backgrounds[6].loadFromFile("img/back6.jpg");
	backgrounds[7].loadFromFile("img/back7.png");
	backgrounds[8].loadFromFile("img/back8.jpg");
	backgrounds[9].loadFromFile("img/back9.png");
	backgrounds[0].loadFromFile("img/back1.jpg");
	for (int i = 0; i < 4; i++)
		backgrounds[i].setRepeated(true);
}
void optionScreen::display(RenderWindow& window) {
	options[option].setFillColor(Color::Red);
	layout.setString(std::to_string(current));
	window.draw(musics[noOfMusic]);
	window.draw(background[noOfbackGrounds]);
	window.draw(title);
	for (int i = 0; i < 5; i++)
		window.draw(options[i]);
	volume.setString(std::to_string(vol));
	window.draw(volume);
	window.draw(layout);
}