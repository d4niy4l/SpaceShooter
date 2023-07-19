#include "UserNameScreen.h"
UserNameScreen::UserNameScreen() {
	name = "";
	nameEntered = 0;
	isActive = 0;
	title.setFont(font);
	title.setString("WARRIOR  ENTER  YOUR   NAME");
	title.setPosition(20, 100);
	title.setCharacterSize(50);
	animation = new Animation("img/menuAnimation.png",0.09,3,3);
	animation->sprite.setPosition(390, 390);
	font.loadFromFile("Fonts/title.ttf");
	enteredName.setFont(font);
	enteredName.setFillColor(Color::White);
	enteredName.setPosition(40, 400);
	enteredName.setString("");
	enteredName.setCharacterSize(50);
}
bool UserNameScreen :: getActive() {
	return isActive;
}
void UserNameScreen::setActive(bool flag) {
	isActive = flag;
}
void UserNameScreen::display(RenderWindow& window) {
	window.draw(animation->sprite);
	window.draw(title);
	window.draw(enteredName);
}
void UserNameScreen::functioning(Event& event) {
	if (event.type == Event::KeyReleased) {
		if (event.key.code == Keyboard::Return) {
			isActive = 0;
			nameEntered = 1;
			return;
		}
	}
	if (event.type == Event::TextEntered) {
		if (event.text.unicode == '\b' && name.size()>0) {
			name.erase(name.size() - 1, 1);
		}
		else if(event.text.unicode < 128){
			char alpha = event.text.unicode;
			name += alpha;
		}
		enteredName.setString(name);
	}	
}
string UserNameScreen::returnString() {
	return name;
}
void UserNameScreen::resetString() {
	name = "";
}
void UserNameScreen ::  animate(float time) {
	animation->timer += time;
	if (!animation->animationFinished())
		animation->upDateAnimation();
	if (animation->getXimage() == 1 && animation->getYimage() == 1)
		animation->restartAnimation();
}