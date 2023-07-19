#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "theMenus.h"
#include <iostream>
using namespace sf;
class Menu : public theMenus {
    bool isOptions;
    Text title, option[5];
    Texture spaceship;
    Sprite ship1;
    Animation* animation;
    Sprite ship2;
public:
    //add menu attributes here
    Menu() : theMenus(1, 3)
    {   
        isMenu = 1;
        optionNo = 0;
        spaceship.loadFromFile("img/menuShip.png");
        title.setFont(font);
        title.setPosition(120, 50);
        title.setString("SPACESHOOTER");
        title.setCharacterSize(75);
        option[0].setFont(font);
        option[0].setPosition(275, 210);
        option[0].setString("START GAME");
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
        option[3].setPosition(315, 540);
        option[3].setString("OPTIONS");
        option[3].setCharacterSize(40);
        option[4].setString("EXIT");
        option[4].setFont(font);
        option[4].setPosition(345, 650);
        option[4].setCharacterSize(40);
        ship1.setTexture(spaceship);
        ship1.setPosition(140, 190);
        ship1.setScale(1, 1);
        background.setPosition(0, 0);
        background.setTextureRect(IntRect(0, 0, 780,820));
        ship2.setTexture(spaceship);
        ship2.setPosition(550, 190);
        ship2.setScale(1, 1);
       
        background.setTexture(backgroundTex);
        background.setScale(1.5, 1.5);
        animation = new Animation("img/coolAnimation.png",0.09,4,5);
      
        animation->sprite.setPosition(380, 400);
        isOptions = 0;
        animation->sprite.setScale(1.5, 1.5);
    }
    void playAnimation(float time) {
        if(animation->getXimage() >= 3 && animation->getYimage() >= 4)
           animation->restartAnimation();
        animation->timer += time;
        if (!animation->animationFinished())
          animation->upDateAnimation();
    }
    void shipMoveUp(){
        if (optionNo > 0) {
            option[optionNo].setFillColor(Color::White);
            optionNo -= 1;
            option[optionNo].setFillColor(Color::Red);
            ship1.setPosition(140, ship1.getPosition().y - 110);
            ship2.setPosition(550, ship2.getPosition().y - 110);
        }
    }
    void shipMoveDown() {
        if (optionNo < 4) {
            option[optionNo].setFillColor(Color::White);
            optionNo += 1;
            option[optionNo].setFillColor(Color::Red);
            ship1.setPosition(140, ship1.getPosition().y + 110);
            ship2.setPosition(550, ship2.getPosition().y + 110);
        }
    }
    bool getIsMenu() {
        return isMenu;
    }
    void setIsMenu(bool flag) {
        isMenu = flag;
    }
    void setIsExtra(bool flag) {
        isOptions = flag;
    }
    bool getIsExtra() {
        return isOptions;
    }
    void menuFunction(Event& event) {
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
                        setIsMenu(false);
                        setIsScore(true);
                        break;
                    case 2:
                        setIsMenu(false);
                        instructions = 1;
                        break;
                    case 3:
                        setIsMenu(false);
                        setIsExtra(true);
                        break;
                    case 4:
                        setIsExit(true);
                        break;
                    }
                }
        }
    }
    void displayMenu(RenderWindow& window)
    {
        window.draw(background);
        window.draw(animation->sprite);
        window.draw(title);
        for(int i = 0;i<5;++i)
            window.draw(option[i]);
        window.draw(ship1);
        window.draw(ship2);

            //Game g;
        //display menu screen here

        // add functionality of all the menu options here

        //if Start game option is chosen 

        //g.start_game();



    }
    virtual ~Menu() {
        delete animation;
    }

};
