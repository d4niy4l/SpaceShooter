#include "PowerUp.h"
PowerUp::PowerUp() : Addons(1, "img/powerUp.png") { time = 5; }
void PowerUp::manipulateSpaceship(bool& flag) {
	flag = 1;
}
string PowerUp :: returnType() {
	return "powerup";
}
