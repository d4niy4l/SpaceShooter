#pragma once
#include "theMenus.h"
#include "Animation.h"
class GameOverMenu :
    public theMenus
{
    int optionNo;
    bool tomain;
    Text option[5], title;
    Texture spaceship;
    Sprite ship1;
    Animation* animation;
    Sprite ship2;
public:
    GameOverMenu();
    void shipMoveUp();
    void shipMoveDown();
    void displayMenu(RenderWindow& window);
    void menuFunction(Event& event);
    bool getIsExtra();
    void playAnimation(float time);
    void setIsExtra(bool flag);
    ~GameOverMenu() {
        delete animation;
    }
};

