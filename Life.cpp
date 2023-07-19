#include "Life.h"
Life::Life() : Addons(3,"img/life.png") {}
void Life::manipulateSpaceship(bool& flag) {
	flag = 1;
}
string Life::returnType() {
	return "life";
}