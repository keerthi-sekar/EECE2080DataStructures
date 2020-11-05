#pragma once
#include "Character.h"
class Rogue :
    public Character
{
public:
    //Low hitpoints and armor but does a lot of damage and is very fast 
    //along with being able to hit the back row of the opposing party
    Rogue(Race* race) : Character(race)
    {
        m_hitpoints = 6 + race->getHitPointMods();
        m_armorclass = 10 + race->getArmorClassMods();
        m_hitbonus = 11 + race->getHitBonusMods();
        m_initiativebonus = 13 + race->getInitiativeBonusMods();
    }

    virtual ~Rogue()
    {

    }


private:
    Rogue();

};