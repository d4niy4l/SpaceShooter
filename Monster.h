#pragma once
#include "Beam.h"
#include "Enemies.h"
class Monster :
    public Enemies
{
    Texture attackMode;
    int instance;
    float beamTime;
    bool IsDescended;
public:
    Beam*& returnBeam() {
        return beam;
    }
    Monster();
    void fireBeam(int x);
    //void unFireBeam();
    virtual int getScore() {
        return 50;
    }
    virtual void setScore(int n) {
        score = n;
    }
    virtual void animate(float time) {}
    virtual bool detectCollision(Bullet& b);
    virtual void Move(float time);
    virtual float returnTimeDelay() {
        return beamTime;
    }
    virtual bool getMove() { return instance; }
    void display(RenderWindow& window);
    void ascendEnemy();
    virtual void enemyDescend();
    bool HasDescended() {
        return IsDescended;
    }
    virtual Beam*& getBeam() {
        return beam;
    }
    bool hasAscended() {
        if (sprite.getPosition().y <= -500)
            return true;
        return false;
    }
    void monsterFunction();
    ~Monster() {
        if(beam != nullptr)
            delete beam;
    }
    void setText(int n) {
        if (n == 1)  sprite.setTexture(text);
        else if (n == 2) sprite.setTexture(attackMode);
    }
    string returnType() { return "monster"; }
};

