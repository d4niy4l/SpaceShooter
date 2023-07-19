#include "Fire.h"
Fire :: Fire() : Addons(2,"img/fire.png"){
	time = 5;
}
void Fire :: manipulateSpaceship(bool& flag) {
	flag = 1;
}
string Fire :: returnType() {
	return "fire";
}