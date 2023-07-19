#pragma once
#include "Addons.h"
class PowerUp : public Addons{
	int time;
public:
	PowerUp();
	void manipulateSpaceship(bool& flag);
	virtual string returnType();
};

