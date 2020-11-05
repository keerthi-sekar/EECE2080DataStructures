#pragma once

class Race
{
public:
    Race(int hitpoints, int armorclass, int hitbonus, int ibonus) : m_hitpointmods(hitpoints),
                                                                    m_armorclassmods(armorclass),
                                                                    m_hitbonusmods(hitbonus),
                                                                    m_initiativebonusmods(ibonus)
    {
    }
    void HitPointModification(int hitpoints) { m_hitpointmods = hitpoints; }
    void ArmorClassModification(int armorclass) { m_armorclassmods = armorclass; }
    void HitBonusModification(int hitbonus) { m_hitbonusmods = hitbonus; }
    void InitiativeBonusModification(int ibonus) { m_initiativebonusmods = ibonus; }

    virtual int getHitPointMods() { return m_hitpointmods; }
    virtual int getArmorClassMods() { return m_armorclassmods; }
    virtual int getHitBonusMods() { return m_hitbonusmods; }
    virtual int getInitiativeBonusMods() { return m_initiativebonusmods; }

    ~Race(){};

protected:
    int m_hitpointmods;
    int m_armorclassmods; //1 for light, 2 for medium, 3 for heavy armor
    int m_hitbonusmods;
    int m_initiativebonusmods;
};