#pragma once
#include "Character.h"
class Wizard : public Character
{
public:
    //Balanced hitpoints and armor, however the wizard will attack all opposing party members with low damage
    Wizard(Race *race) : Character(race)
    {
        m_hitpoints = 12 + race->getHitPointMods();
        m_armorclass = 10 + race->getArmorClassMods();
        m_hitbonus = 2 + race->getHitBonusMods();
        m_initiativebonus = 12 + race->getInitiativeBonusMods();
    }

    virtual ~Wizard()
    {
    }



private:
    Wizard();
};