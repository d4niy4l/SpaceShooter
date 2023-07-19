#pragma once
#include "Addons.h"
class Danger :
    public Addons
{
    int lifecount = 0;
public:
    Danger();
    virtual string returnType();
    void manipulateSpaceship(bool& flag);
};

