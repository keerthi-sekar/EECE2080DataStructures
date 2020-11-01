#pragma once

#include "IRace.h"
class IShip
{
public:

    IShip(IRace* race) :  m_numberGuns(0), m_dmgPerGun(0), m_race(race), m_speedMod(0)
    {
		m_hull = 6 + race->GetHullPointMods();
    }

	bool IsAlive()
	{
		// hardcoded
		return true;
	}

	int GetHullPoints()
	{
		return m_hull;
	}

    virtual ~IShip() {}

protected:
	int m_hull;
	int m_numberGuns;
	int m_dmgPerGun;
	int m_speedMod;
	IRace* m_race;

};

