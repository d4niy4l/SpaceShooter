#include "GameOverMenu.h"
GameOverMenu :: GameOverMenu () : theMenus(0,5) {
    isMenu = 0;
    optionNo = 0;
    spaceship.loadFromFile("img/menuShip.png");
    title.setFont(font);
    tomain = 0;
    title.setPosition(180, 50);
    title.setString("GAME OVER");
    title.setCharacterSize(75);
    option[0].setFont(font);
    option[0].setPosition(290, 210);
    option[0].setString("MAINMENU");
    option[0].setCharacterSize(40);
    option[0].setFillColor(Color::Red);
    option[1].setFont(font);
    option[1].setPosition(279, 320);
    option[1].setString("HIGHSCORES");
    option[1].setCharacterSize(40);
    option[2].setFont(font);
    background.setTextureRect(IntRect(0, 0, 780, 820));
    option[2].setPosition(345, 430);
    option[2].setString("HELP");
    option[2].setCharacterSize(40);
    option[3].setFont(font);
    option[3].setPosition(310, 540);
    option[3].setString("RESTART");
    option[3].setCharacterSize(40);
    option[4].setFont(font);
    option[4].setPosition(350, 650);
    option[4].setString("EXIT");
    option[4].setCharacterSize(40);
    ship1.setTexture(spaceship);
    ship1.setPosition(100, 190);
    ship1.setScale(1, 1);
    ship2.setTexture(spaceship);
    ship2.setPosition(590, 190);
    ship2.setScale(1, 1);
    animation = new Animation("img/finalBoss.png",0.5,1,2);
    animation->sprite.setPosition(395, 400);
    animation->sprite.setScale(1.5, 1.5);
}
void GameOverMenu::shipMoveUp() {
    if (optionNo > 0) {
        option[optionNo].setFillColor(Color::White);
        optionNo -= 1;
        option[optionNo].setFillColor(Color::Red);
        ship1.setPosition(100, ship1.getPosition().y - 110);
        ship2.setPosition(590, ship2.getPosition().y - 110);
    }
}
void GameOverMenu::shipMoveDown() {
    if (optionNo < 4) {
        option[optionNo].setFillColor(Color::White);
        optionNo += 1;
        option[optionNo].setFillColor(Color::Red);
        ship1.setPosition(100, ship1.getPosition().y + 110);
        ship2.setPosition(590, ship2.getPosition().y + 110);
    }
}
void GameOverMenu::displayMenu(RenderWindow& window) {
    window.draw(background);
    window.draw(animation->sprite);
    window.draw(title);
    for (int i = 0; i < 5; ++i)
        window.draw(option[i]);
    window.draw(ship1);
    window.draw(ship2);
}
void GameOverMenu::menuFunction(Event& event) {
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
                setIsExtra(true);
                break;
            case 1:
                setIsMenu(false);
                setIsScore(true);
                break;
            case 2:
                setIsInstructions(true);
                setIsMenu(false);
            case 3:
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
bool GameOverMenu::getIsExtra() {
    return tomain;
}
void GameOverMenu:: playAnimation(float time) {
    if (animation->getXimage() >= 0 && animation->getYimage() >= 2)
        animation->restartAnimation();
    animation->timer += time;
    if (!animation->animationFinished())
        animation->upDateAnimation();
}
void GameOverMenu:: setIsExtra(bool flag) {
    tomain = flag;
}