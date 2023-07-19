#include "Danger.h"
Danger::Danger() : Addons(4,"img/danger.png") {
	lifecount = 1;
}
string Danger::returnType() {
	return "danger";
}
void Danger::manipulateSpaceship(bool& flag) {
	flag = 1;
}