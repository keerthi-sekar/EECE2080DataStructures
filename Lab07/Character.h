#pragma once

#include "Race.h"
#include "Party.h"
#include <stdlib.h>

class Character
{
public:
    Character(Race *race) : m_hitpoints(0),
                            m_hitbonus(0),
                            m_initiativebonus(0),
                            m_race(race),
                            m_wizard(0),
                            m_rogue(0)
    {
        //Do nothing
    }

    int getHitpoints() { return m_hitpoints + m_race->getHitPointMods(); }
    int getArmorClass() { return m_armorclass + m_race->getArmorClassMods(); }
    int getHitBonus() { return m_hitbonus + m_race->getHitBonusMods(); }
    int getInitiativeBonus() { return m_initiativebonus + m_race->getInitiativeBonusMods(); }

    virtual void takeDamage(int damage) { m_hitpoints -= damage; }

    bool isAlive()
    {
        if (m_hitpoints <= 0)
        {
            return false;
        }

        return true;
    }

    virtual void Attack(Character *defender)
    {
        if ((m_hitbonus + (rand() % 20 + 1) - defender->m_armorclass) > 0)
        {
            defender->m_hitpoints -= (m_hitbonus + (rand() % 20 + 1) - defender->m_armorclass);
        }
    }

    virtual void AttackWizard(Party<Character> party)
    {
        int attack = m_hitbonus + (rand() % 20 + 1);
        if (party.frontrow.at(0)->getHitpoints() > 0)
        {
            party.frontrow.at(0)->takeDamage(attack - party.frontrow.at(0)->getArmorClass());
        }
        else if (party.frontrow.at(1)->getHitpoints() > 0)
        {
            party.frontrow.at(1)->takeDamage(attack - party.frontrow.at(1)->getArmorClass());
        }
        else if (party.backrow.at(0)->getHitpoints() > 0)
        {
            party.backrow.at(0)->takeDamage(attack - party.backrow.at(0)->getArmorClass());
        }
        else if (party.backrow.at(1)->getHitpoints() > 0)
        {
            party.backrow.at(1)->takeDamage(attack - party.backrow.at(1)->getArmorClass());
        }
    }

    virtual void Heal(Character *target)
    {
        target->m_hitpoints += 5;
    }

    virtual void setParty(int p) { m_party = p; }
    virtual int getParty() { return m_party; }
    virtual void setWizard() { m_wizard = 1; }
    virtual int getWizard() { return m_wizard; }

    virtual void setRogue() { m_rogue = 1; }
    virtual int getRogue() { return m_rogue; }

    virtual ~Character(){};

protected:
    int m_hitpoints;
    int m_armorclass;
    int m_hitbonus;
    int m_initiativebonus;
    int m_party;
    int m_wizard;
    int m_rogue;
    Race *m_race;
};