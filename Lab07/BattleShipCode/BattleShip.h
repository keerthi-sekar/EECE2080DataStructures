#pragma once

#include "Iship.h"
#include "IRace.h"

class BattleShip : public IShip
{
public:

	BattleShip(IRace* race) : IShip(race)
	{
        m_dmgPerGun = 10;
        m_hull = 10;
        m_numberGuns = 4;
        m_speedMod = 0;
	}

    ~BattleShip() {}



private :
    BattleShip();

};

