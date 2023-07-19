
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <time.h>
#include "Menu.h"
#include "optionScreen.h"
#include "File.h"
#include "HelpScreen.h"
#include "Monster.h"
#include "Collider.h"
#include "Levels.h"
#include "Invader.h"
#include "GameOverMenu.h"
#include "Dragon.h"
#include "Bomb.h"
#include "Animation.h"
#include "Life.h"
#include "PauseMenu.h"
#include "PowerUp.h"
#include "Shield.h"
#include "highscoreScreen.h"
#include "UserNameScreen.h"
#include "Fire.h"
#include "Danger.h"
#include <iostream>
using namespace std;
#include "player.h"
const char title[] = "OOP-Project, Spring-2023";
using namespace sf;

class Game
{
    Sprite background; //Game background sprite
    Texture bg_texture;
    Player* p; //player 
    optionScreen* options;
    File* file;
    theMenus** menu;
    Bomb** bombRack;
    Addons* addon;
    Collider* colliders;
    UserNameScreen* enterName;
    highscoreScreen* highscore;
    Animation** portals;
    HelpScreen* help;
    Shield* shield;
    int noOfBombs;
    bool startGame;
    int layout;
    Levels* level;
    Bullet** arsenal;
    int numberOfBullets;
    int numberOfenemys, totalEnemies;
    Enemies** enemy;
    float addOntimer = 0;
    Enemies** disapperPtr;
    Music music[10];
    float backgroundTop;
    float yPosition;
    float backgroundtime;
    int songNO;
    float monsterTime;
    float dragonTime;
    float invaderTime;
    bool invaderGone;
    bool isFiring;
    bool shieldOn;
    bool invaderCome;
    bool monster,monsterAppear;
    bool boss, bossAppear;
    bool levelOut;
    bool dragon,dragonAppear;
    bool invader;
    bool dropAddon;
public:
    // add other game attributes
    Game()
    {
        layout = 1;
        yPosition = 0;
        startGame = 0;
        p = new Player("img/player_ship.png");
        bg_texture.loadFromFile("img/back1.jpg");
        bg_texture.setRepeated(true);
        background.setTexture(bg_texture);
        menu = new theMenus*[4];
        menu[0] = new Menu;
        menu[1] = new PauseMenu;
        invaderTime = 6;
        menu[2] = new GameOverMenu;
        level = new Levels;
        enterName = new UserNameScreen;
        help = new HelpScreen;
        songNO = 0;
        arsenal = nullptr;
        numberOfBullets = 0;
        numberOfenemys = 0;
        bombRack = nullptr;
        shieldOn = 0;
        levelOut = 0;
        options = new optionScreen;
        noOfBombs = 0;
        shield = new Shield;
        isFiring = 0;
        invaderGone = 0;
        backgroundtime = 0;
        invaderCome = 0;
        addOntimer = 0;
        background.setTextureRect(IntRect(0, 0, 780, 820));
   
        dropAddon = 0;
        totalEnemies = 0;
        enemy = NULL;
        disapperPtr = nullptr;
        addon = nullptr;
        monster = 0;
        portals = new Animation * [2];
        portals[0] = new Animation("img/portalRight.png", 0.06, 3, 3);
        portals[1] = new Animation("img/portalLeft.png", 0.06, 3, 3);
        portals[0]->sprite.setPosition(-10, 230);
        portals[1]->sprite.setPosition(780, 230);
        music[0].openFromFile("Music/track1.ogg");
        music[1].openFromFile("Music/track2.ogg");
        music[2].openFromFile("Music/track3.ogg");
        music[3].openFromFile("Music/track4.ogg");
        music[4].openFromFile("Music/track5.ogg");
        music[5].openFromFile("Music/track6.ogg");
        music[6].openFromFile("Music/track7.ogg");
        music[7].openFromFile("Music/track8.ogg");
        music[8].openFromFile("Music/track9.ogg");
        music[9].openFromFile("Music/track10.ogg");
        dragonTime = 0;
        monsterAppear = 0;
        dragonAppear = 0;
        dragon = 0;
        file = new File;
        colliders = new Collider[2]{Collider("img/collider2.png"),Collider("img/collider.png")};
        highscore = new highscoreScreen;
        invader = 1;
        monsterTime = 0;
    }
    void displayPortals(float time, RenderWindow& window,bool flag) {
        for (int i = 0; i < 2; i++) {
            if (portals[i]->getXimage() == 2 && portals[i]->getYimage() == 2)
                portals[i]->restartAnimation();
            if (!portals[i]->animationFinished())
                portals[i]->upDateAnimation();
            if (flag) {
                window.draw(portals[i]->sprite);
            }
        }
    }
    void moveBackground(float time) {
        backgroundtime += time;
        if (backgroundtime > 1.0)
            yPosition -= 0.1;
        background.setTextureRect(IntRect(0,backgroundTop + yPosition,780,820));
    }
    void restartGame() {
        if (bombRack != nullptr) {
            for (int i = 0; i < noOfBombs; i++)
                delete bombRack[i];
            delete[] bombRack;
        }
        if (dragon || monster) {
            delete* enemy;
            delete enemy;
        }
        else if (invader) {
            for (int i = 0; i < numberOfenemys; i++)
                delete enemy[i];
            delete enemy;
        }
        for (int i = 0; i < numberOfBullets; i++) {
            reloadBullet(i);
        }
        delete[] arsenal;
        arsenal = nullptr;
       // if (disapperPtr != nullptr) {
         //   for (int i = 0; i < numberOfenemys; i++)
           //     delete disapperPtr[i];
            //delete disapperPtr;;
        //}
        startGame = 0;
        enemy = nullptr;
        bombRack = nullptr;
        monster = 0;
        dragonTime = 0;
        *(p->getScore()) = 0;
        monsterAppear = 0;
        dragonAppear = 0;
        dragon = 0;
        numberOfenemys = 0;
        shieldOn = 0;
        p->setShieldOn(false);
        p->getShieldTime() = 0;
        p->getShield() = nullptr;
        invader = 1;
        numberOfenemys = 0;
        p->sprite.setPosition(390, 700);
        noOfBombs = 0;
        isFiring = 0;
        numberOfBullets = 0;
        invaderGone = 0;
        invaderCome = 0;
        dropAddon = 0;
        level->setLevelNo(1);
        level->setWaveNo(0);
        if (!p->getAnimation()->animationFinished())
            p->getAnimation()->sprite.setPosition(-1600, -1600);
        for(int i = 0;i<3;i++)
            ++*(p->getLive());
        totalEnemies = 0;
        monsterTime = 0;
        p->setIsDestroyed(0);
        addOntimer = 0;
    }
    void extendArsenal(string path) {
        if (arsenal == nullptr) {
            arsenal = new Bullet * [numberOfBullets + 1];
            numberOfBullets = 1;
            arsenal[0] = new Bullet(path);
        }
        else {
            Bullet** temp = arsenal;
            arsenal = new Bullet * [numberOfBullets + 1];
            for (int i = 0; i < numberOfBullets; i++)
                arsenal[i] = temp[i];
            delete temp;
            arsenal[numberOfBullets] = new Bullet(path);
            numberOfBullets += 1;
        }
    }
void makeBullets() {
    p->time = 0;
        if (p->getAngle() == 45.00) {
            if (p->getFire()) {
                extendArsenal("rocket1.png");
                p->fire(*(arsenal[numberOfBullets-1]), "rightUp");
            }
            else {
                extendArsenal("rightUp");
                p->fire(*(arsenal[numberOfBullets-1]), "rightUp");
                if (p->getPowerUp()) {
                    extendArsenal("30");
                    p->fire(*(arsenal[numberOfBullets - 1]), "30");
                    extendArsenal("15");
                    p->fire(*(arsenal[numberOfBullets - 1]), "15");
                    extendArsenal("60");
                    p->fire(*(arsenal[numberOfBullets - 1]), "60");
                    extendArsenal("90");
                    p->fire(*(arsenal[numberOfBullets - 1]), "90");
                    extendArsenal("75");
                    p->fire(*(arsenal[numberOfBullets - 1]), "75");
                    extendArsenal("");
                    p->fire(*(arsenal[numberOfBullets - 1]), "");
                }
            }
        }
        else if (p->getAngle() == 315.00) {
            if (p->getFire()) {
                extendArsenal("rocket2");
                    p->fire(*(arsenal[numberOfBullets - 1]), "leftUp");
            }
            else {
                extendArsenal("leftUp");
                p->fire(*(arsenal[numberOfBullets - 1]), "leftUp");
                if (p->getPowerUp()) {
                    extendArsenal("-30");
                    p->fire(*(arsenal[numberOfBullets - 1]), "-30");
                    extendArsenal("-15");
                    p->fire(*(arsenal[numberOfBullets - 1]), "-15");
                    extendArsenal("-60");
                    p->fire(*(arsenal[numberOfBullets - 1]), "-60");
                    extendArsenal("-90");
                    p->fire(*(arsenal[numberOfBullets - 1]), "-90");
                    extendArsenal("-75");
                    p->fire(*(arsenal[numberOfBullets - 1]), "-75");
                    extendArsenal("");
                    p->fire(*(arsenal[numberOfBullets - 1]), "");
                }
            }
        }
        else if (p->getAngle() == 135.00) {
            if (p->getFire()) {
                extendArsenal("rocket3");
                p->fire(*(arsenal[numberOfBullets - 1]), "rightDown");
            }
            else {
                extendArsenal("rightDown");
                p->fire(*(arsenal[numberOfBullets - 1]), "rightDown");
            }
        }
        else if (p->getAngle() == 225.00) {
            if (p->getFire()) {
                extendArsenal("rocket4");
                p->fire(*(arsenal[numberOfBullets - 1]), "leftDown");
            }
            else {
                extendArsenal("leftDown");
                p->fire(*(arsenal[numberOfBullets - 1]), "leftDown");
            }
        }
        else {
            if (p->getFire()) {
                extendArsenal("");
                p->fire(*(arsenal[numberOfBullets - 1]), "");
            }
            else {
                extendArsenal("");
                p->fire(*(arsenal[numberOfBullets - 1]), "");
                if (p->getPowerUp()) {
                    extendArsenal("-30");
                    p->fire(*(arsenal[numberOfBullets - 1]), "-30");
                    extendArsenal("-15");
                    p->fire(*(arsenal[numberOfBullets - 1]), "-15");
                    extendArsenal("30");
                    p->fire(*(arsenal[numberOfBullets - 1]), "30");
                    extendArsenal("15");
                    p->fire(*(arsenal[numberOfBullets - 1]), "15");
                    extendArsenal("leftUp");
                    p->fire(*(arsenal[numberOfBullets - 1]), "leftUp");
                    extendArsenal("rightUp");
                    p->fire(*(arsenal[numberOfBullets - 1]), "rightUp");
                }
            }
        }
 
}
void makeBomb(int i) {
    if (bombRack == nullptr) {
        noOfBombs = 0;
        bombRack = new Bomb * [1];
        bombRack[noOfBombs] = new Bomb;
        noOfBombs += 1;
    }
    else {
        Bomb** temp = bombRack;
        bombRack = new Bomb * [noOfBombs + 1];
        for (int k = 0; k < noOfBombs; k++)
            bombRack[k] = temp[k];
        bombRack[noOfBombs] = new Bomb;
        noOfBombs += 1;
    }
    enemy[i]->fireBomb(*(bombRack[noOfBombs - 1]));
    enemy[i]->timer = 0;
 }
    void spawnDragon() {
        disapperPtr = enemy;
        enemy = new Enemies*;
        *enemy = new Dragon;
        invader = 0;
        dragon = 1;
        dragonTime = 0;
    }
    void spawnMonster() {
        disapperPtr = enemy;
        enemy = new Enemies*;
        *enemy = new Monster;
        invader = 0;
        monster = 1;
        monsterTime = 0;
    }
    /*void addAnimation(string filePath, float delay, int x, int y, int xPos, int yPos) {
        if (animation == nullptr) {
            animation = new Animation * [1];
            animation[0] = new Animation(filePath, delay, x, y);
            noOfAnimations += 1;
            animation[0]->loadAnimation(xPos, yPos);
            return;
        }
        Animation** temp = animation;
        animation = new Animation * [noOfAnimations + 1];
        for (int i = 0; i < noOfAnimations; i++)
            animation[i] = temp[i];
        animation[noOfAnimations] = new Animation(filePath, delay, x, y);
        animation[noOfAnimations]->loadAnimation(xPos, yPos);
        noOfAnimations += 1;
        delete[] temp;
    }
    void removeAnimation(int i) {
        Animation** temp = animation;
        animation = new Animation * [noOfAnimations - 1];
        int count = 0;
        for (int j = 0; j < noOfAnimations; j++)
            if (i != j)
                animation[count++] = temp[j];
        delete temp[i];
        delete[] temp;
        noOfAnimations -= 1;
    }
    */
    void respawnPlayer() {
        shieldOn = 1;
        p->restartBoom();
        p->sprite.setPosition(-500, -500);
        p->getShield() = shield;
        p->setIsDestroyed(true);
        -- *(p->getLive());
    }
    void spawnEnemies() {
        switch (level->getLevelNo()) {
        case 1:
            totalEnemies = 14;
            break;
        case 2:
            totalEnemies = 16;
            break;
        case 3:
            totalEnemies = 20;
            break;
        }
        numberOfenemys = totalEnemies;
        enemy = new Enemies * [numberOfenemys];
        for (int i = 0; i < numberOfenemys; i++) {
            srand(time(0) + i);
            int x = rand() % 3 + 1;
            if (x == 1) enemy[i] = new Alpha;
            if (x == 2) enemy[i] = new Beta;
            if (x == 3) enemy[i] = new Gamma;
        }
        if (level->getLevelNo() == 1)
            switch (level->getWaveNo()) {
            case 1:
                level->arrangeIntoRectangle(enemy, numberOfenemys);
                break;
            case 2:
                level->arrangeIntoTriangle(enemy, numberOfenemys);
                break;
            case 3:
                level->arrangeIntoCross(enemy, numberOfenemys);
                break;
            }
        else if (level->getLevelNo() == 2)
            switch (level->getWaveNo()) {
            case 1:
                level->arrangeIntoDiamond(enemy, numberOfenemys);
                break;
            case 2:
                level->arrangeIntoCircle(enemy, numberOfenemys);
                break;
            case 3:
                level->arrangeIntoHeart(enemy, numberOfenemys);
                break;
            }
        else if (level->getLevelNo() == 3)
            switch (level->getWaveNo()) {
            case 1:
                level->fillRectangle(enemy, numberOfenemys);
                break;
            case 2:
                level->fillCircle(enemy, numberOfenemys);
                break;
            case 3:
                srand(time(0));
                int x = rand() % 2 + 1;
                if(x == 1)
                    level->fillDiamond(enemy, numberOfenemys);
                else if(x == 2)
                    level->fillTriangle (enemy, numberOfenemys);
                break;
            }
        level->setWaveReset(false);
        level->setStart(false);
    }
    void increaseLevelAndWave() {
        if (level->getWaveNo() >= 3 && level->getLevelNo() < 3) {
            level->setWaveNo(0);
            level->setLevelNo(level->getLevelNo() + 1);
        }
        level->setWaveReset(1);
        if(level->getLevelNo() <= 3 && level->getWaveNo() < 3)
            level->addWaveNo(1);
        else if (level->getLevelNo() == 3 && level->getWaveNo() == 3) {
            level->setWaveNo(0);
            levelOut = 1;
            numberOfenemys = 0;
            level->setWaveReset(true);
            invader = 0;
            level->setLevelNo(level->getLevelNo() + 1);
        }


    }
    void reloadBullet(int i) {
        Bullet** temp = arsenal;
        arsenal = new Bullet * [numberOfBullets - 1];
        int count = 0;
        for (int j = 0; j < numberOfBullets; j++)
            if (i != j) {
                arsenal[count++] = temp[j];

            }
        delete temp[i];
        delete[] temp;
        numberOfBullets -= 1;
    }
    void bombSelfDestruct(int i, int bombNo) {
        Bomb** temp = enemy[i]->returnBomb();
        enemy[i]->returnBomb() = new Bomb * [enemy[i]->getNumBombs() - 1];
        int count = 0;
        for (int j = 0; j < enemy[i]->getNumBombs(); j++)
            if (bombNo != j)
                enemy[i]->returnBomb()[count++] = temp[j];
        delete temp[bombNo];
        delete[] temp;
        enemy[i]->setNumBombs(enemy[i]->getNumBombs() - 1);
    }
    void bringBackInvaders() {
        delete *enemy;
        delete enemy;
        enemy = disapperPtr;
        disapperPtr = nullptr;
        invader = 1;
    }
    void bombSelfDestruct(int bombNo) {
        Bomb** temp = bombRack;;
        bombRack = new Bomb * [noOfBombs - 1];
        int count = 0;
        for (int i = 0; i < noOfBombs; i++)
            if (bombNo != i)
                bombRack[count++] = temp[i];
        delete temp[bombNo];
        delete[] temp;
        noOfBombs -= 1;
    }
    void destoryenemy(int enemyNo) {
        Enemies** temp = enemy;
        enemy = new Enemies * [numberOfenemys - 1];
        for (int i = 0, count = 0; i < numberOfenemys; i++)
            if (enemyNo != i)
                enemy[count++] = temp[i];
        delete temp[enemyNo];
        delete[] temp;
        numberOfenemys -= 1;
    }
    void beginDescent() {
        if (!levelOut && !level->getStart() && numberOfenemys >= 0 &&enemy[0]->sprite.getPosition().y <= level->endPoint) {
            for (int i = 0; i < numberOfenemys; i++)
                enemy[i]->waveDescend();
            if (enemy[0]->sprite.getPosition().y > level->endPoint)
                level->setStart(1);
        }
    }
    void addOnCreation() {
        srand(time(0) + rand());
        if (addOntimer > 1 && !dropAddon) {
            int chance = rand() % 4 + 1;
            if (chance == 1)
                addon = new PowerUp;
            else if (chance == 2)
                addon = new Fire;
            else if (chance == 3)
                addon = new Life;
            else if (chance == 4)
                addon = new Danger;
            dropAddon = 1;
            addOntimer = 0;
        }
    }
    void deleteAddon() {
        if (addon != nullptr) {
            delete addon;
            addon = nullptr;
            dropAddon = 0;
            addOntimer = 0;
        }
    }
    void start_game()
    {
        music[0].play();
        srand(time(0));
        RenderWindow window(VideoMode(780, 820), "APOLLO");
        Clock clock;
        float currentTime;
        float timer = 0;
            Event event;
        while (window.isOpen())
        {
            float time = clock.getElapsedTime().asSeconds();
            timer += time;
            currentTime = clock.restart().asSeconds();
            float fps = 1/currentTime;
            //cout << fps<<endl;
            while (window.pollEvent(event))
            {   
               if(menu[0]->getIsMenu() )
                    menu[0]->menuFunction(event);
               if (menu[1]->getIsMenu())
                    menu[1]->menuFunction(event);
               if (menu[2]->getIsMenu()) {
                   enterName->setActive(false);
                   menu[2]->menuFunction(event);
                   startGame = 0;
               }
               if (help->getActive())
                   help->function(event);
                if (menu[1]->getIsGame())
                    startGame = 1;
                if (menu[0]->getIsExit())
                    window.close();
                if (menu[2]->getIsInstructions()) {
                    menu[2]->setIsInstructions(false);
                    help->setActive(true);
                    help->setOver(true);
                    menu[2]->setIsMenu(false);
                }
                if (menu[1]->getIsInstructions()) {
                    menu[1]->setIsInstructions(false);
                    help->setActive(true);
                    help->setPause(true);
                    menu[1]->setIsMenu(false);
                }
                if (menu[0]->getIsGame()) {
                    restartGame();
                    menu[0]->setIsGame(false);
                    menu[0]->setIsMenu(false);
                    startGame = 1;
                }
                if (menu[0]->getIsInstructions()) {
                    help->setActive(true);
                    menu[0]->setIsInstructions(0);
                    help->setMenu(true);
                }
                if (menu[0]->getIsExtra()) {
                    options->isActive = 1;
                    menu[0]->setIsExtra(false);
                }
                if (options->isActive)
                    options->function(event, background, music, layout,songNO);
                if (menu[2]->getIsGame()) {
                    menu[2]->setIsGame(false);
                    restartGame();
                    startGame = 1;
                }
                if (options->goBack) {
                    menu[0]->setIsMenu(true);
                    options->goBack = 0;
                    options->isActive = 0;
                }
                if (menu[0]->returnScore()) {
                    highscore->setMenu(1);
                    highscore->setActive(true);
                    menu[0]->setIsScore(false);
                }
                if (menu[2]->returnScore()) {
                    highscore->setOver(1);
                    highscore->setActive(true);
                    menu[2]->setIsScore(false);
                }
                if (menu[1]->returnScore()) {
                    highscore->setPause(1);
                    highscore->setActive(true);
                    menu[1]->setIsScore(false);
                }
                if (menu[2]->getIsExtra()) {
                    menu[0]->setIsMenu(1);
                    menu[2]->setIsExtra(false);
                    menu[2]->setIsMenu(false);
                    restartGame();
                    startGame = 0;
                }
                if (menu[2]->getIsExit())
                    window.close();
                if (highscore->getActive()) {
                    highscore->function(event);
                }
                if (startGame) {
                    if(event.type == Event :: KeyReleased)
                        if (event.key.code == Keyboard::Escape) {
                            startGame = 0;
                            menu[0]->setIsGame(false);
                            menu[1]->setIsGame(false);
                            menu[1]->setIsMenu(true);
                            menu[1]->setIsExit(false);
                        }
                }
                if (menu[1]->getIsExit()) {
                    restartGame();
                    startGame = 0;
                    menu[0]->setIsGame(false);
                    menu[1]->setIsExit(false);
                    menu[0]->setIsMenu(true);
                }
                if (menu[1]->getIsExtra()) {
                    restartGame();
                    menu[1]->setIsExtra(0);
                    menu[1]->setIsMenu(false);
                    menu[0]->setIsMenu(false);
                    menu[0]->setIsGame(false);
                    startGame = 1;
                }
               if (enterName->getActive())
                    enterName->functioning(event);
                if (event.type == Event::Closed) // If cross/close is clicked/pressed
                    window.close(); //close the game                        	    
            }
            if (music[songNO].getStatus() == sf::Music::Stopped) {
                songNO += 1;
                if (songNO > 9) songNO = 0;
                music[songNO].play();
            }
            if (startGame) {
                if (level->getLevelNo() > 3) levelOut = 1;
                /*
                for (int i = 0; i < noOfAnimations; i++)
                    animation[i]->timer += time;
                */
                p->time += time;
                if (!monster && !dragon) {
                    //monsterTime += time;
                    dragonTime += time;
                }
                for(int i = 0;i<2;i++)
                    portals[i]->timer += time;
                addOntimer += time;
                if(!p->getIsDestroyed()){
                    if (layout == 1) {
                        if (Keyboard::isKeyPressed(Keyboard::A)) //If left key is pressed
                            p->move("l");    // Player will move to left
                        if (Keyboard::isKeyPressed(Keyboard::D)) // If right key is pressed
                            p->move("r");  //player will move to right
                        if (Keyboard::isKeyPressed(Keyboard::W)) //If up key is pressed
                            p->move("u");    //playet will move upwards
                        if (Keyboard::isKeyPressed(Keyboard::S)) // If down key is pressed
                            p->move("d");  //player will move downwards
                        if (Keyboard::isKeyPressed(Keyboard::W) && Keyboard::isKeyPressed(Keyboard::D))
                            p->rotateMove("u", "r");
                        else if (Keyboard::isKeyPressed(Keyboard::W) && Keyboard::isKeyPressed(Keyboard::A))
                            p->rotateMove("u", "l");
                        else if (Keyboard::isKeyPressed(Keyboard::S) && Keyboard::isKeyPressed(Keyboard::D))
                            p->rotateMove("d", "r");
                        else if (Keyboard::isKeyPressed(Keyboard::S) && Keyboard::isKeyPressed(Keyboard::A))
                            p->rotateMove("d", "l");
                    }
                    else {
                        if (Keyboard::isKeyPressed(Keyboard::Left)) //If left key is pressed
                            p->move("l");    // Player will move to left
                        if (Keyboard::isKeyPressed(Keyboard::Right)) // If right key is pressed
                            p->move("r");  //player will move to right
                        if (Keyboard::isKeyPressed(Keyboard::Up)) //If up key is pressed
                            p->move("u");    //playet will move upwards
                        if (Keyboard::isKeyPressed(Keyboard::Down)) // If down key is pressed
                            p->move("d");  //player will move downwards
                        if (Keyboard::isKeyPressed(Keyboard::Up) && Keyboard::isKeyPressed(Keyboard::Right))
                            p->rotateMove("u", "r");
                        else if (Keyboard::isKeyPressed(Keyboard::Up) && Keyboard::isKeyPressed(Keyboard::Left))
                            p->rotateMove("u", "l");
                        else if (Keyboard::isKeyPressed(Keyboard::Down) && Keyboard::isKeyPressed(Keyboard::Right))
                            p->rotateMove("d", "r");
                        else if (Keyboard::isKeyPressed(Keyboard::Down) && Keyboard::isKeyPressed(Keyboard::Left))
                            p->rotateMove("d", "l");
                    }
                }
                ////////////////////////////////////////////////
                /////  Call your functions here            ////
                /////////////////////////////////////////////
                for (int i = 0; i < numberOfBullets; i++) {
                    if (arsenal[i]->outOfBounds())
                        reloadBullet(i);
                }
                if (shieldOn)
                    p->getShieldTime() += time;
                if (p->getShieldTime() > 5) {
                    shield->setPos(-555, -555);
                    shieldOn = 0;
                    p->getShieldTime() = 0;
                    p->setShieldOn(false);
                    p->getShield() = nullptr;
                }
                if (p->getPowerUp()) {
                    p->getShieldTime() += time;
                    shieldOn = 1;
                    p->setShieldOn(1);
                    p->getShield() = shield;
                    shield->setPos(p->sprite.getPosition().x, p->sprite.getPosition().y);
                }
                int chance3 = rand() % 50;
                if (p->getPowerUpTime(time)) deleteAddon();
                if (addOntimer > 10 && !dropAddon && chance3 == 7) 
                    addOnCreation();
                if (dropAddon) {
                    if (!p->getFire() && !p->getPowerUp())
                        addon->move();
                    if (p->detectCollision(addon)) {
                        //deleteAddon();
                        dropAddon = 0;
                        //p->returnAddon() = nullptr;
                    }
                    else if (addon != nullptr && addon->outofBounds()) {
                        if (addon->returnType() == "danger")
                            *(p->getScore()) += 50;
                        deleteAddon();
                    }
                }
                if (p->time > 0.3 && Keyboard::isKeyPressed(Keyboard::Space)) {
                    makeBullets();
                }
                if (p->getBooming())
                    p->playBoom(time);
                p->respawn(time);
                srand(std :: time(0) + rand());
                int chance = rand() % 50;
                int chance2 = rand() % 50;
                if (dragonTime > 25.00  && (chance == 5 || chance == 15)) {
                    bool flag = false;
                    monsterTime = 0;
                    for (int i = 0; i < numberOfenemys; i++) {
                        if (enemy[i]->sprite.getPosition().y >= 80)
                            flag = true;
                        else {
                            flag = false;
                            break;
                        }
                    }
                    if (flag) {
                        dragonTime = 0;
                        invaderGone = true;
                        isFiring = 0;
                        for (int i = 0; i < numberOfenemys; i++) {
                            enemy[i]->y = enemy[i]->sprite.getPosition().y;
                        }
                        dragonAppear = 1;
                    }
                }
                if (p->getLive()->returnLives() <= 0 && file->returnLowestScore() < p->getScore()->returnScore()) {
                    startGame = 0;
                    enterName->setActive(true);
                    for (int i = 0; i < 3; i++)
                        ++* (p->getLive());
                }
                else if(p->getLive()->returnLives() <= 0) {
                    for (int i = 0; i < 3; i++)
                        ++* (p->getLive());
                    menu[2]->setIsMenu(true);
                    startGame = 0;
                }
                else if (levelOut && file->returnLowestScore() < p->getScore()->returnScore()) {
                    levelOut = 0;
                    startGame = 0;
                    enterName->setActive(true);
                    for (int i = 0; i < 3; i++)
                        ++* (p->getLive());
                }
                else if (levelOut && file->returnLowestScore() >= p->getScore()->returnScore()) {
                    for (int i = 0; i < 3; i++)
                        ++* (p->getLive());
                    menu[2]->setIsMenu(true);
                    startGame = 0;
                    levelOut = 0;
                }
                if (monsterTime > 5.00  && (chance == 1 || chance == 10)) {
                    dragonTime = 0;
                    bool flag = false;
                    for (int i = 0; i < numberOfenemys; i++) {
                        if (enemy[i]->sprite.getPosition().y >= 80)
                            flag = true;
                        else {
                            flag = false;
                            break;
                        }
                    }
                    if (flag) {
                        monsterTime = 0;
                        invaderGone = true;
                        isFiring = 0;
                        for (int i = 0; i < numberOfenemys; i++) {
                            enemy[i]->y = enemy[i]->sprite.getPosition().y;
                        }
                        monsterAppear = 1;
                    }
                }
                if (invaderGone && (dragonAppear || monsterAppear)) {
                    isFiring = 0;
                    bool flag = 0;
                    for (int i = 0; i < numberOfenemys; i++) {
                        if (!enemy[i]->hasAscended())
                            enemy[i]->ascendEnemy();
                        else
                            flag = 1;
                    }
                    if (flag && dragonAppear) {
                        spawnDragon();
                        invaderGone = 0;
                        isFiring = 1;
                        dragonAppear = 0;
                    }
                    else if (flag && monsterAppear) {
                        spawnMonster();
                        monsterAppear = 0;
                        invaderGone = 0;
                        isFiring = 1;
                    }

                }
                if (dragon) {
                    if(!(*enemy)->HasDescended())
                        (*enemy)->enemyDescend();
                     (*enemy)->Move(time);
                    for (int i = 0; i < numberOfBullets; i++)
                        if ((*enemy)->detectCollision(*(arsenal[i])))
                            reloadBullet(i);
                    if (p->detectCollisonDragon(*(enemy)))
                        respawnPlayer();
                    if ((*enemy)->HasDescended()) {
                        (*enemy)->fireBeam(p->sprite.getPosition().x);
                        if ((*enemy)->isFiring)
                            if (p->detectCollosionwithDragonFire(*(*enemy)->getBeam())) {
                                if (!p->getShieldOn()) {
                                    respawnPlayer();
                                    p->broWasNotDestroyed = 0;
                                }
                            }
                    }
                    (*enemy)->timer += time;
                    if ((*enemy)->timer > 20.00) {
                        (*enemy)->ascendEnemy();
                        (*enemy)->isFiring = 0;
                    }
                    if ((*enemy)->hasAscended()) {
                        dragon = 0;
                        bringBackInvaders();
                        invaderCome = 1;
                        if (p->broWasNotDestroyed)
                            *(p->getScore()) += 50;
                        p->broWasNotDestroyed = 1;
                    }
                }
                if (monster) {
                    //if((*enemy)->ascended)
                        (*enemy)->enemyDescend();
                    for(int i = 0;i<numberOfBullets;i++)
                        if((*enemy)->detectCollision(*(arsenal[i])))
                            reloadBullet(i);
                    if (p->detectCollisonMonster(*(enemy)))
                        respawnPlayer();
                    if ((*enemy)->HasDescended()) {
                        (*enemy)->fireBeam(0);
                        if((*enemy)->isFiring)
                            if (p->detectCollision(*(*enemy)->getBeam())) {
                                if (!p->getShieldOn()) {
                                    respawnPlayer();
                                    p->broWasNotDestroyed = 0;
                                }
                            }
                        (*enemy)->Move(time);
                    }
                    (*enemy)->timer += time;
                    if ((*enemy)->timer > 7.00) {
                        (*enemy)->setText(1);
                        (*enemy)->ascendEnemy();
                    }
                    if ((*enemy)->hasAscended()) {
                        timer = 0;
                        monster = 0;
                        bringBackInvaders();
                        invaderCome = 1;
                        if (p->broWasNotDestroyed)
                            *(p->getScore()) += 40;
                        p->broWasNotDestroyed = 1;
                    }
                }
                if (invaderCome) {
                    for (int i = 0; i < numberOfenemys; i++) {
                        if (!enemy[i]->HasDescended()) {
                            enemy[i]->enemyDescend();
                        }
                        else {
                            invaderCome = 0;
                            isFiring;
                        }
                    }
                }
                if (invader) {
                    if (level->getLevelNo() == 1 && level->getWaveNo() == 0 && level->getWaveReset() == 1) {
                        increaseLevelAndWave();
                        colliders[0].setScreen(1);
                        colliders[1].setScreen(1);
                        colliders[0].isCollided = 0;
                        colliders[1].isCollided = 0;
                        colliders[0].moveIn(-50);
                        colliders[1].moveIn(675);
                    }
                    else if (level->getWaveReset() == 0 && numberOfenemys == 0) {
                        increaseLevelAndWave();
                        colliders[0].setScreen(1);
                        colliders[1].setScreen(1);
                        colliders[0].moveIn(-50);
                        colliders[0].isCollided = 0;
                        colliders[1].isCollided = 0;
                        invaderTime = 0;
                        colliders[1].moveIn(675);
                    }
                    if (colliders[0].getScreen() && colliders[1].getScreen()) {
                        for (int i = 0; i < 2; i++) {
                            colliders[i].swirl(time);
                            colliders[1].move(-0.3);
                            colliders[0].move(0.3);
                            if (colliders[0].detectCollision(colliders[1])) {
                                colliders[i].setBoom(true);
                               colliders[i].setAnimationPos(colliders[i].sprite.getPosition().x, colliders[i].sprite.getPosition().y);
                                colliders[i].moveOut();
                                colliders[1].isCollided = 1;
                                colliders[0].isCollided = 1;
                               colliders[1].setScreen(false);
                                colliders[0].setScreen(false);
                            }
                        }
                    }
                    if (!colliders[0].getScreen() && !colliders[1].getScreen() && invaderTime > 0.65 && 1 <= level->getLevelNo() <= 3) {
                        if (level->getWaveReset())
                            spawnEnemies();
                        if (!level->getStart())
                            beginDescent();
                        if (level->getStart())
                            isFiring = 1;
                    }
                    else if (level->getLevelNo() > 4) {
                        invaderCome = 0;
                        invader = 0;
                    }
                        invaderTime += time;

                    if (colliders[0].getBoom())
                        colliders[0].animate(time);
                    if (colliders[1].getBoom())
                        colliders[1].animate(time);
                }
                moveBackground(time);
                if(invader){
                    for (int i = 0; i < numberOfenemys; i++) {
                        if (enemy[i]->showAnimation)
                            enemy[i]->animate(time);
                        enemy[i]->timer += time;
                        enemy[i]->Move(time);
                    }
                    for (int i = 0; i < numberOfenemys; i++) {
                        enemy[i]->returnDelay() += time;
                        for (int k = 0; k < numberOfBullets; k++)
                            if (enemy[i]->detectCollision(*(arsenal[k]))) {
                                enemy[i]->setAnimationShow(true);
                                enemy[i]->getAnimation()->sprite.setPosition(enemy[i]->sprite.getPosition().x, enemy[i]->sprite.getPosition().y);
                                enemy[i]->sprite.setPosition(1600, enemy[i]->sprite.getPosition().y);
                                *(p->getScore()) += level->getLevelNo() * enemy[i]->getScore();
                                if (!arsenal[k]->getIsFire())
                                    reloadBullet(k);
                            }
                        if (enemy[i]->getAnimation()->animationFinished()) {
                            destoryenemy(i);
                        }
                    }
                    int noOfAlpha = 0, noOfBeta = 0, noOfGamma = 0;
                    for (int j = 0; j < numberOfenemys; j++) {
                        if (enemy[j]->returnType() == "alpha") noOfAlpha++;
                        else if (enemy[j]->returnType() == "beta") noOfBeta++;
                        else if (enemy[j]->returnType() == "gamma") noOfGamma++;
                    }
                    bool alpha = 0, beta = 0, gamma = 0;
                    int c1 = 0, c2 = 0, c3 = 0;
                    int alphaNo = 0, betaNo = 0, gammaNo = 0;
                    srand(std::time(0));
                    for (int i = 0; i < numberOfenemys && level->getStart(); i++) {
                        if(noOfAlpha > 0) c1 = rand() % (noOfAlpha);
                        if(noOfBeta > 0) c2 = rand() % (noOfBeta);
                        if(noOfGamma > 0) c3 = rand() % (noOfGamma);
                        if (enemy[i]->getTimeDelay() < enemy[i]->timer) {
                            if (enemy[i]->returnType() == "alpha" && !alpha) {
                                if (alphaNo == c1) {
                                    makeBomb(i);
                                    alpha = 1;
                                }
                                alphaNo++;
                                
                            }
                            else if (enemy[i]->returnType() == "beta" && !beta) {
                                if (betaNo == c2) {
                                    makeBomb(i);
                                    beta = 1;
                                }
                                betaNo++;
                            }
                            else if (enemy[i]->returnType() == "gamma" && !gamma) {
                                if (gammaNo == c3) {
                                    makeBomb(i);
                                    gamma = 1;
                                }
                                gammaNo++;
                            }
                            enemy[i]->timer;
                        }
                        if (enemy[i]->timer > enemy[i]->getTimeDelay()) enemy[i]->timer = 0;
                        if (p->detectCollision(enemy[i])) {
                            enemy[i]->setAnimationShow(true);
                            enemy[i]->getAnimation()->sprite.setPosition(enemy[i]->sprite.getPosition().x, enemy[i]->sprite.getPosition().y);
                            enemy[i]->sprite.setPosition(1600, 1600);
                            if(!p->getShieldOn())
                                respawnPlayer();
                        }
                        if (enemy[i]->getAnimation()->animationFinished()) {
                            destoryenemy(i);
                        }
                    }
                }
                for (int i = 0; i < numberOfBullets; ++i) {
                    arsenal[i]->move();
                }
                for (int i = 0; i < noOfBombs; i++) {
                    bombRack[i]->dropBomb();
                    if (p->detectCollision(*(bombRack[i]))) {
                        bombSelfDestruct(i);
                        if(!p->getShieldOn())
                            respawnPlayer();
                    }
                }
                for (int i = 0; i < noOfBombs; i++)
                    if (bombRack[i]->outOfBounds())
                        bombSelfDestruct(i);
                /*
                for (int i = 0; i < noOfAnimations; i++) {
                
                    if (animation[i]->animationFinished()) {
                        removeAnimation(i);
                        continue;
                    }
                    animation[i]->upDateAnimation();
                }
                */
                
            }
            
            if (enterName->getnameEntered()) {
                string s = enterName->returnString();
                startGame = 0;
                file->readFile();
                file->writeFile(p->getScore()->returnScore(), s);
                enterName->setNameEntered(false);
                enterName->setActive(false);
                enterName->resetString();
                highscore->update();
                menu[2]->setIsGame(false);
                menu[2]->setIsMenu(true);
                startGame = 0;
            }
           window.clear(Color::Black); //clears the screen
            if(startGame || options->isActive)
                window.draw(background);  // setting background
            if (options->isActive) {
                options->display(window);
            }
            if (startGame) {
                if (p->returnIsfiring())
                    for (int i = 0; i < numberOfBullets; i++)
                        window.draw(arsenal[i]->sprite);
                if (invader) {
                    for (int i = 0; i < numberOfenemys; i++) {
                        displayPortals(time, window, enemy[i]->getMove());
                        if (enemy[i]->showAnimation) {
                            window.draw(enemy[i]->getAnimation()->sprite);
                        }
                        else enemy[i]->display(window);
                        /*for (int j = 0; j < enemy[i]->getNumBombs(); j++)
                            window.draw(enemy[i]->returnBomb()[j]->sprite);*/
                    }
                }
                for (int i = 0; i < noOfBombs; ++i)
                    window.draw(bombRack[i]->sprite);
                window.draw(p->sprite);   // setting player on screen
                if (p->getShield() != nullptr && !p->getIsDestroyed()) window.draw(p->getShield()->sprite);
                if (p->getBooming())
                    p->showBoom(window);
                if (dragon) {
                    (*enemy)->display(window);
                }
                if (monster) {
                    (*enemy)->display(window);
                }
                p->getLive()->display(window);
                if (dropAddon || p->getPowerUp() || p->getFire()) {
                    window.draw(addon->sprite);
                }
                colliders[0].display(window);
                colliders[1].display(window);
                displayPortals(time, window, colliders[0].getScreen() || colliders[1].getScreen());
                level->display(window);
                p->getScore()->display(window);
                p->changeSprite(p->tex);

                //window.draw(level->barTex);
            }
            if (enterName->getActive()) {
                enterName->animate(time);
                enterName->display(window);
            }
            if (menu[1]->getIsMenu()) {
                menu[1]->moveBackground(time);
                menu[1]->displayMenu(window);
            }
            if (help->getActive()) {
                help->display(window);
            }
            if (menu[0]->getIsMenu()) {
                menu[0]->playAnimation(time);
                menu[0]->moveBackground(time);
                menu[0]->displayMenu(window);
            }
            if (menu[2]->getIsMenu()) {
                menu[2]->playAnimation(time);
                menu[2]->moveBackground(time);
                menu[2]->displayMenu(window);
            }
            if (!help->getActive() && help->getMenu()) {
                menu[0]->setIsMenu(true);
                help->setMenu(false);
            }
            else if (!help->getActive() && help->getPause()) {
                menu[1]->setIsMenu(true);
                help->setPause(false);
            }
            else if (!help->getActive() && help->getOver()) {
                menu[2]->setIsMenu(true);
                help->setOver(false);
            }
            if (highscore->getActive())
                highscore->display(window);
            if (highscore->getMenu() && !highscore->getActive()) {
                menu[0]->setIsMenu(1);
                highscore->setMenu(0);
            }
            else if (highscore->getOver() && !highscore->getActive()) {
                menu[2]->setIsMenu(1);
                highscore->setOver(0);
            }
            else if (highscore->getPause() && !highscore->getActive()) {
                menu[1]->setIsMenu(1);
                highscore->setPause(0);
            }
            if (menu[2]->getIsMenu()) startGame = 0;
            window.display();  //Displying all the sprites
        }


    }

    ~Game() {
        if (bombRack != nullptr) {
            for (int i = 0; i < noOfBombs; i++)
                delete bombRack[i];
            delete[] bombRack;
        }
        if (dragon || monster) {
            delete* enemy;
            delete enemy;
        }
        if (invader) {
            for (int i = 0; i < numberOfenemys; i++)
                delete enemy[i];
            delete enemy;
        }
        for (int i = 0; i < numberOfBullets; i++) {
            reloadBullet(i);
        }
        delete[] arsenal;
        if (disapperPtr != nullptr) {
            for (int i = 0; i < numberOfenemys; i++)
                delete disapperPtr[i];
            delete disapperPtr;
        }
        delete help;
        for (int i = 0; i < 3; i++)
            delete menu[i];
        delete[] menu;
        delete highscore;
        delete options;
        enemy = nullptr;
        bombRack = nullptr;
        monster = 0;
        dragonTime = 0;
        monsterAppear = 0;
        dragonAppear = 0;
        dragon = 0;
        numberOfenemys = 0;
        invader = 1;
        numberOfenemys = 0;
        noOfBombs = 0;
        isFiring = 0;
        invaderGone = 0;
        invaderCome = 0;
        dropAddon = 0;
        for (int i = 0; i < 2; i++)
            delete portals[i];
        delete[] portals;
        level->setLevelNo(1);
        level->setWaveNo(0);
        if (!p->getAnimation()->animationFinished())
            p->getAnimation()->sprite.setPosition(-1600, -1600);
        for (int i = 0; i < 3; i++)
            ++* (p->getLive());
        totalEnemies = 0;
        monsterTime = 0;
        p->setIsDestroyed(0);
        addOntimer = 0;
        delete p;
        delete shield;
    }
};

