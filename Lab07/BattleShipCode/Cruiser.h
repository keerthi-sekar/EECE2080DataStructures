#pragma once
#include "Iship.h"
class Cruiser :
    public IShip
{
public:
    Cruiser(IRace* race) : IShip(race)
    {
        m_dmgPerGun = 6;
        m_hull = 6;
        m_numberGuns = 2;
        m_speedMod = 10;
    }
    virtual ~Cruiser()
    {

    }


private:
    Cruiser();

};

