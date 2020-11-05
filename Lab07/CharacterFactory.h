#pragma once

#include "Character.h"
#include "Race.h"

class Elf;
class Dwarf;
class Human;
class Halfling;

class CharacterFactory
{
    public:

    enum enumOfClass{WizardClass, RogueClass, FighterClass, ClericClass};
    enum enumOfRace{ElfRace, DwarfRace, HumanRace, HalflingRace};

    CharacterFactory();

    Character* CreateCharacter(enumOfClass classtype, enumOfRace racetype);

    virtual ~CharacterFactory() {};


    private:

    Race* getRace(enumOfRace enumOfRacetoRetrieve);

    Elf *m_elf;
    Dwarf *m_dwarf;
    Human *m_human;
    Halfling *m_halfling;

};