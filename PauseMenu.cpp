#include "PauseMenu.h"
void PauseMenu :: displayMenu(RenderWindow& window) {
    window.draw(background);
    //window.draw(animation->sprite);
    window.draw(title);
    for (int i = 0; i < 5; ++i)
        window.draw(option[i]);
    window.draw(ship1);
    window.draw(ship2);
}
void PauseMenu::menuFunction(Event& event) {
    if (event.type == Event::KeyReleased) {
        switch (event.key.code) {
        case Keyboard::Up:
            shipMoveUp();
            break;
        case Keyboard::Down:
            shipMoveDown();
            break;
        case Keyboard::Return:
            switch (optionNo) {
            case 0:
                setIsMenu(false);
                setIsGame(true);
                break;
            case 1:
                setIsScore(true);
                setIsGame(false);
                setIsMenu(false);
                break;
            case 2:
                setIsInstructions(true);
                setIsMenu(false);
                break;
            case 3:
                setIsExtra(true);
                setIsGame(true);
                setIsMenu(false);
                break;
            case 4:
                setIsExit(true);
                setIsGame(false);
                setIsMenu(false);
                setIsExtra(false);
                break;
            }
        }
    }
}
bool PauseMenu::getIsExtra() {
	return restart;
}
void PauseMenu::setIsExtra(bool flag) {
    restart = flag;
}
PauseMenu::PauseMenu() : theMenus(0,4){
    isMenu = 0;
    optionNo = 0;
    spaceship.loadFromFile("img/menuShip.png");
    title.setFont(font);
    restart = 0;
    title.setPosition(270, 50);
    title.setString("PAUSED");
    title.setCharacterSize(75);
    option[0].setFont(font);
    option[0].setPosition(260, 210);
    option[0].setString("RESUME GAME");
    option[0].setCharacterSize(40);
    option[0].setFillColor(Color::Red);
    option[1].setFont(font);
    option[1].setPosition(279, 320);
    option[1].setString("HIGHSCORES");
    option[1].setCharacterSize(40);
    option[2].setFont(font);
    option[2].setPosition(345, 430);
    option[2].setString("HELP");
    option[2].setCharacterSize(40);
    option[3].setFont(font);
    option[3].setPosition(310, 540);
    option[3].setString("RESTART");
    option[3].setCharacterSize(40);
    option[4].setFont(font);
    option[4].setPosition(240, 650);
    option[4].setString("RETURN TO MENU");
    option[4].setCharacterSize(40);
    ship1.setTexture(spaceship);
    ship1.setPosition(100, 190);
    ship1.setScale(1, 1);
    ship2.setTexture(spaceship);
    ship2.setPosition(590, 190);
    ship2.setScale(1, 1);
    backgroundTex.loadFromFile("img/menuimg.jpg");
    background.setTexture(backgroundTex);
    background.setScale(1.5, 1.5);
}
void PauseMenu ::  shipMoveUp() {
    if (optionNo > 0) {
        option[optionNo].setFillColor(Color::White);
        optionNo -= 1;
        option[optionNo].setFillColor(Color::Red);
        ship1.setPosition(100, ship1.getPosition().y - 110);
        ship2.setPosition(590, ship2.getPosition().y - 110);
    }
}
void PauseMenu :: shipMoveDown() {
    if (optionNo < 4) {
        option[optionNo].setFillColor(Color::White);
        optionNo += 1;
        option[optionNo].setFillColor(Color::Red);
        ship1.setPosition(100, ship1.getPosition().y + 110);
        ship2.setPosition(590, ship2.getPosition().y + 110);
    }
}