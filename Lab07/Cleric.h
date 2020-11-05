#pragma once
#include "Character.h"
class Cleric :
    public Character
{
public:
    //Very balanced stats with the ability to heal other party members
    Cleric(Race* race) : Character(race)
    {
        m_hitpoints = 10 + race->getHitPointMods();
        m_armorclass = 10 + race->getArmorClassMods();
        m_hitbonus = 5 + race->getHitBonusMods();
        m_initiativebonus = 10 + race->getInitiativeBonusMods();
    }

    virtual ~Cleric()
    {

    }


private:
    Cleric();

};