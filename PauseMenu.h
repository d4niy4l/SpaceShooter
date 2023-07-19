#pragma once
#include "theMenus.h"
#include "Animation.h"
class PauseMenu : public theMenus
{
    bool restart;
    Text title, option[5];
    Texture spaceship;
    Sprite ship1;
    Animation* animation;
    Sprite ship2;
public:
    void shipMoveUp();
    void shipMoveDown();
    PauseMenu();
    void displayMenu(RenderWindow& window);
    void menuFunction(Event& event);
    bool getIsExtra();
    void playAnimation(float time){}
    void setIsExtra(bool flag);
    ~PauseMenu() {

    }
};

