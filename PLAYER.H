#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "Bullet.h"
#include "Lives.h"
#include "Enemies.h"
#include "Shield.h"
#include "Bomb.h"
#include "Score.h"
#include "Beam.h"
#include "PowerUp.h"
#include<string.h>
#include "Animation.h"
#include "point.h"
using namespace sf;
	class Player {
		SoundBuffer explodeNoises, pewpew;
		Sound pew, boomer;
		Texture tex1, tex2, tex3, tex4;
		float angle;
		bool isFiring;
		Shield* shield;
		Score* score;
		bool powerUped;
		float powerUptime;
		bool increaseLife;
		bool shieldOn;
		bool decreaseLife;
		bool isDestroyed;
		bool fireActivate;
		Animation* boom;
		float shieldTime;
		Lives* lives;
		Addons* addon;
	public:
		bool broWasNotDestroyed;
		float time = 0;
		Texture tex;
		Sprite sprite;
		float speed = 0.5;
		Bullet** bullet;
		bool isBooming;
		float respawnTimer;
		int x, y;
		Player(std::string png_path)
		{
			shield = nullptr;
			shieldTime = 0;
			angle = 0;
			isFiring = 0;
			fireActivate = 0;
			addon = nullptr;
			lives = new Lives;
			broWasNotDestroyed = 1;
			increaseLife = 0;
			respawnTimer = 0;
			pewpew.loadFromFile("Music/pew.wav");
			explodeNoises.loadFromFile("Music/bruh.ogg");
			pew.setBuffer(pewpew);
			boomer.setBuffer(explodeNoises);
			decreaseLife = 0;
			isDestroyed = 0;
			powerUptime = 0;
			isBooming = 0;
			bullet = new Bullet*[1];
			shieldOn = 0;
			tex.loadFromFile(png_path);
			tex1.loadFromFile("img/45.png");
			tex2.loadFromFile("img/-45.png");
			tex3.loadFromFile("img/135.png");
			tex4.loadFromFile("img/-135.png");
			sprite.setTexture(tex);
			x = 340, y = 700;
			sprite.setPosition(340+32,700);
			sprite.setOrigin(72 * 0.5, 75 * 0.5);
			score = new Score;
			powerUped = 0;
			boom = new Animation("img/boom.png", 0.06, 3, 2);
		}
		bool getPowerUpTime(float time) {
			if (powerUped || fireActivate) {
				powerUptime += time;
				if (powerUptime > 5.0) {
					powerUped = fireActivate = 0;
					powerUptime = 0;
					addon = NULL;
					return true;
				}
			}
			return false;
		}
		Score*& getScore() {
			return score;
		}
		void respawn(float time) {
			if(isDestroyed) respawnTimer += time;
			if (isDestroyed && respawnTimer > 1.5) {
				if(shield != nullptr)
					shield->setPos(390, 700);
				sprite.setPosition(390, 700);
				shieldTime = 0;
				isDestroyed = 0;
				shieldOn = 1;
				respawnTimer = 0;
			}
		}
		bool getIsDestroyed() {
			return isDestroyed;
		}
		void setIsDestroyed(bool flag) {
			isDestroyed = flag;
		}
		void warpSides() {
			if (sprite.getPosition().x - 72 * 0.5 > 780)
				sprite.setPosition(72 * 0.5, sprite.getPosition().y);
			else if (sprite.getPosition().x + 72 * 0.5 < 0)
				sprite.setPosition(780.0 - (72 * 0.5), sprite.getPosition().y);
			if (sprite.getPosition().y - (75 * 0.5) > 830)
				sprite.setPosition(sprite.getPosition().x, 0  + (75 * 0.5));
			else if (sprite.getPosition().y + 37.5 < 0)
				sprite.setPosition(sprite.getPosition().x, 830 - (75 * 0.5));
		}
		void restartBoom() {
			boom->sprite.setPosition(sprite.getPosition().x, sprite.getPosition().y);
			boom->restartAnimation();
			isBooming = 1;
		}
		void playBoom(float time) {
			if (!boom->animationFinished()) {
				boom->upDateAnimation();
				boom->timer += time;
			}
			else if (boom->animationFinished()) {
				boomer.play();
				isBooming = 0;
			}

		}
		bool getShieldOn() {
			return shieldOn;
		}
		void setShieldOn(bool flag) {
			shieldOn = flag;
		}
		float& getShieldTime() {
			return shieldTime;
		}
		Shield*& getShield() {
			return shield;
		}
		int getBooming() {
			return isBooming;
		}
		void setBooming(bool flag) {
			isBooming = flag;
		}
		void showBoom(RenderWindow& window) {
			window.draw(boom->sprite);
		}
		void changeSprite(Texture& tex){
			sprite.setTexture(tex);
			sprite.setOrigin(72 * 0.5, 75 * 0.5);
			angle = 0;
		}
		bool returnIsfiring() {
			return isFiring;
		}
		bool& getFire() {
			return fireActivate;
		}
		void setIsFiring(bool flag) {
			isFiring = flag;
		}
		void setAngle(float angle) {
			this->angle = angle;
		}
		float getAngle() const {
			return angle;
		}
		Lives*& getLive() {
			return lives;
		}
		Animation*& getAnimation() {
			return boom;
		}
		void rotateMove(std::string s1, std::string s2) {
			if (s1 == "u" && s2 == "r") {
				changeSprite(tex1);
				angle = 45.00;
			}
			else if (s1 == "u" && s2 == "l") {
				changeSprite(tex2);
				this->angle = 315.00;
			}
			else if (s1 == "d" && s2 == "r") {
				changeSprite(tex3);
				angle = 135;
			}
			else if (s1 == "d" && s2 == "l") {
				changeSprite(tex4);
				angle = 225.00;
			}
		}
		void fire(Bullet& b,string direction = "") {
			pew.play();
			bullet[0] = &b;
			if (direction == "") {
				if (angle == 0)
					bullet[0]->sprite.setPosition(sprite.getPosition().x, sprite.getPosition().y - (75 * 0.5));
				else if (angle == 45)
					bullet[0]->sprite.setPosition(sprite.getPosition().x + 36, sprite.getPosition().y - (75 * 0.5));
				else if(angle == 315)
					bullet[0]->sprite.setPosition(sprite.getPosition().x - 36, sprite.getPosition().y - (75 * 0.5));
				bullet[0]->setAngle(0);
			}
			else if (direction == "60") {
				bullet[0]->sprite.setPosition(sprite.getPosition().x + 36, sprite.getPosition().y - (75 * 0.5));
			}
			else if (direction == "-60") {
				bullet[0]->sprite.setPosition(sprite.getPosition().x - 36, sprite.getPosition().y - (75 * 0.5));
			}
			else if (direction == "-30") {
				bullet[0]->setAngle(-30);
				if(angle == 0)
					bullet[0]->sprite.setPosition(sprite.getPosition().x, sprite.getPosition().y - (75 * 0.5));
				else if(angle == 315)
					bullet[0]->sprite.setPosition(sprite.getPosition().x - 36, sprite.getPosition().y - (75 * 0.5));
			}
			else if (direction == "30") {
				bullet[0]->setAngle(30);
				if (angle == 0)
					bullet[0]->sprite.setPosition(sprite.getPosition().x, sprite.getPosition().y - (75 * 0.5));
				else if (angle == 45)
					bullet[0]->sprite.setPosition(sprite.getPosition().x + 36, sprite.getPosition().y - (75 * 0.5));
			}
			else if (direction == "-15") {
				bullet[0]->setAngle(-15);
				bullet[0]->sprite.setPosition(sprite.getPosition().x, sprite.getPosition().y - (75 * 0.5));
				if (angle == 0)
					bullet[0]->sprite.setPosition(sprite.getPosition().x, sprite.getPosition().y - (75 * 0.5));
				else if (angle == 315)
					bullet[0]->sprite.setPosition(sprite.getPosition().x - 36, sprite.getPosition().y - (75 * 0.5));
			}
			else if (direction == "15") {
				bullet[0]->setAngle(15);
				if (angle == 0)
					bullet[0]->sprite.setPosition(sprite.getPosition().x, sprite.getPosition().y - (75 * 0.5));
				else if (angle == 45)
					bullet[0]->sprite.setPosition(sprite.getPosition().x + 36, sprite.getPosition().y - (75 * 0.5));
			}
			else if (direction == "90") {
				bullet[0]->setAngle(90);
				bullet[0]->sprite.setPosition(sprite.getPosition().x + 36, sprite.getPosition().y - (75 * 0.5));
			}
			else if (direction == "-90") {
				bullet[0]->setAngle(-90);
				bullet[0]->sprite.setPosition(sprite.getPosition().x - 36, sprite.getPosition().y - (75 * 0.5));
			}
			else if (direction == "rightUp") {
				bullet[0]->sprite.setPosition(sprite.getPosition().x + 36, sprite.getPosition().y - (75 * 0.5));
				bullet[0]->setAngle(45);
			}
			else if (direction == "leftUp") {
				bullet[0]->sprite.setPosition(sprite.getPosition().x - 36, sprite.getPosition().y - (75 * 0.5));
				bullet[0]->setAngle(-45);
			}
			else if (direction == "rightDown") {
				bullet[0]->sprite.setPosition(sprite.getPosition().x + 36, sprite.getPosition().y + (75 * 0.5));
				bullet[0]->setAngle(135);
			}
			else if (direction == "leftDown") {
				bullet[0]->sprite.setPosition(sprite.getPosition().x - 36, sprite.getPosition().y + (75 * 0.5));
				bullet[0]->setAngle(-135);
			}
			
			else if (direction == "-75") {
				bullet[0]->sprite.setPosition(sprite.getPosition().x - 36, sprite.getPosition().y - (75 * 0.5));
			}
			else if (direction == "75") {
				bullet[0]->sprite.setPosition(sprite.getPosition().x + 36, sprite.getPosition().y - (75 * 0.5));
			}
			else if (direction == "-30") {
				bullet[0]->setAngle(-30);
				if (angle == 0)
					bullet[0]->sprite.setPosition(sprite.getPosition().x, sprite.getPosition().y - (75 * 0.5));
				else if (angle == 315)
					bullet[0]->sprite.setPosition(sprite.getPosition().x -36, sprite.getPosition().y - (75 * 0.5));
			}
			else if (direction == "30") {
				bullet[0]->setAngle(30);
				if (angle == 0)
					bullet[0]->sprite.setPosition(sprite.getPosition().x, sprite.getPosition().y - (75 * 0.5));
				else if (angle == 45)
					bullet[0]->sprite.setPosition(sprite.getPosition().x + 36, sprite.getPosition().y - (75 * 0.5));
			}
			bullet[0] = nullptr;
			isFiring = 1;
		}
		
		void move(std::string s) {
			float delta_x = 0, delta_y = 0;
			if (s == "l")
				delta_x = -1;
			//move the player left
			else if (s == "r")
				delta_x = 1;
			//move the player right
			if (s == "u")
				delta_y = -1;
			else if (s == "d")
				delta_y = 1;
			delta_x *= speed;
			delta_y *= speed;
			sprite.move(delta_x, delta_y);
			warpSides();
			if (shield != nullptr) shield->move(delta_x, delta_y);
		}
		bool detectCollision(Bomb& b) {
			float wBomb = b.sprite.getOrigin().x;
			float hBomb = b.sprite.getOrigin().y;
			float wPlayer = sprite.getOrigin().x;
			float hPlayer = sprite.getOrigin().y;
			//sprite.getGlobalBounds().
			if (abs(sprite.getPosition().x - b.sprite.getPosition().x) < hBomb + hPlayer && abs(sprite.getPosition().y  - b.sprite.getPosition().y + 22) < wBomb + wPlayer)
				return true;
			return false;
		}
		bool detectCollision(Enemies* enemy) {
			float wBomb = enemy->sprite.getOrigin().x;
			float hBomb = enemy->sprite.getOrigin().y;
			float wPlayer = enemy->sprite.getOrigin().x;
			float hPlayer = enemy->sprite.getOrigin().y;
			if (abs(sprite.getPosition().x - enemy->sprite.getPosition().x) < hBomb + hPlayer && abs(sprite.getPosition().y - enemy->sprite.getPosition().y + 22) < wBomb + wPlayer)
				return true;
			return false;
		}
		bool detectCollisonMonster(Enemies* enemy) {
			float wBomb = enemy->sprite.getOrigin().x;
			float hBomb = enemy->sprite.getOrigin().y;
			float wPlayer = enemy->sprite.getOrigin().x;
			float hPlayer = enemy->sprite.getOrigin().y;
			if (abs(sprite.getPosition().x - enemy->sprite.getPosition().x) + 130 < hBomb + hPlayer && abs(sprite.getPosition().y - enemy->sprite.getPosition().y + 22) < wBomb + wPlayer)
				return true;
			return false;
		}
		Addons*& returnAddon() {
			return addon;
		}
		bool detectCollisonDragon(Enemies* enemy) {
			float wPlayer = sprite.getOrigin().x;
			float hPlayer = sprite.getOrigin().y;
			float hDragon = (enemy)->sprite.getTextureRect().height;
			float wDragon = (enemy)->sprite.getTextureRect().width;
			if ((enemy->sprite.getPosition().x + enemy->sprite.getTextureRect().width >= sprite.getPosition().x && enemy->sprite.getPosition().y + enemy->sprite.getTextureRect().height >= sprite.getPosition().y) && (enemy->sprite.getPosition().x <= sprite.getPosition().x + sprite.getTexture()->getSize().x && enemy->sprite.getPosition().y + 20 <= sprite.getPosition().y + sprite.getTexture()->getSize().y))
				return true;
			return false;
		}
		bool detectCollision(Beam& b) {
			float wBeam = b.sprite.getOrigin().x;
			float hBeam = b.sprite.getOrigin().y ;
			float wPlayer = sprite.getOrigin().x;
			float hPlayer = sprite.getOrigin().y;
			if (abs((sprite.getPosition().x) - b.sprite.getPosition().x + 150)< wBeam + wPlayer && abs(sprite.getPosition().y - b.sprite.getPosition().y) < hBeam + hPlayer)
				return true;
			return false;
		}
		bool& getPowerUp() {
			return powerUped;
		}
		bool detectCollosionwithDragonFire(Beam& b) {
				float wCollider = b.collider.getOrigin().x + 30;
				float hCollider = b.collider.getOrigin().y + 30;
				float wPlayer = sprite.getOrigin().x;
				float hPlayer = sprite.getOrigin().y;
			if (b.getDirection() == 0) {
				float wBeam = b.sprite.getOrigin().x + 33;
				float hBeam = b.sprite.getOrigin().y + 600;
				if (abs((sprite.getPosition().x - 15) - (b.sprite.getPosition().x + 15)) < wBeam + wPlayer && abs(sprite.getPosition().y - b.sprite.getPosition().y) < hBeam + hPlayer)
					return true;
			}
			else if (b.getDirection() == 1 || b.getDirection() == 2) {
				if (abs(b.collider.getPosition().x - sprite.getPosition().x) < wPlayer + wCollider && abs(sprite.getPosition().y - b.collider.getPosition().y) < hCollider + hPlayer)
					return true;
			}
			return false;
		}
		bool detectCollision(Addons* add) {
			float wBomb = add->sprite.getOrigin().x;
			float hBomb = add->sprite.getOrigin().y;
			float wPlayer = sprite.getOrigin().x;
			float hPlayer = sprite.getOrigin().y;
			if (abs(sprite.getPosition().x - add->sprite.getPosition().x) < hBomb + hPlayer && abs(sprite.getPosition().y - add->sprite.getPosition().y + 22) < wBomb + wPlayer) {
				addon = add;
				if (addon->returnType() == "powerup") {
					addon->manipulateSpaceship(powerUped);
					shieldTime = 0;
				}
				else if (addon->returnType() == "fire")
					addon->manipulateSpaceship(fireActivate);
				else if (addon->returnType() == "life") {
					addon->manipulateSpaceship(increaseLife);
					++* (lives);
					increaseLife = 0;
				}
				else if (addon->returnType() == "danger") {
					addon->manipulateSpaceship(decreaseLife);
					--* (lives);
					decreaseLife = 0;
				}
				addon->sprite.setPosition(32, 786);
				return true;
			}
			return false;
		}
		~Player() {
			delete score;
			delete lives;
		}
	};

	