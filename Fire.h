#pragma once
#include "Addons.h"
class Fire : public Addons{
	float time;
public:
	Fire();
	void manipulateSpaceship(bool& flag);
	virtual string returnType();
};

