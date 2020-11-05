#pragma once
#include "Character.h"
class Fighter :
    public Character
{
public:
    //Has much higher hitpoints and armor than other classes but is very slow and does mild damage.
    Fighter(Race* race) : Character(race)
    {
        m_hitpoints = 14 + race->getHitPointMods();
        m_armorclass = 16 + race->getArmorClassMods();
        m_hitbonus = 8 + race->getHitBonusMods();
        m_initiativebonus = 2 + race->getInitiativeBonusMods();
    }

    virtual ~Fighter()
    {

    }


private:
    Fighter();

};