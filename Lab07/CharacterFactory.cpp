#include "CharacterFactory.h"

#include "Wizard.h"
#include "Rogue.h"
#include "Fighter.h"
#include "Cleric.h"

#include "Elf.h"
#include "Dwarf.h"
#include "Halfling.h"
#include "Human.h"

CharacterFactory::CharacterFactory()
{
    m_dwarf = new Dwarf();
    m_elf = new Elf();
    m_halfling = new Halfling();
    m_human = new Human();
}

Race* CharacterFactory::getRace(enumOfRace enumOfRaceToRetrieve)
{
    switch(enumOfRaceToRetrieve)
    {
        case CharacterFactory::HumanRace:
        return m_human;
        break;
        case CharacterFactory::DwarfRace:
        return m_dwarf;
        break;
        case CharacterFactory::ElfRace:
        return m_elf;
        break;
        case CharacterFactory::HalflingRace:
        return m_halfling;
        break;
        default:
        throw "Invalid Race";

    }
}

Character* CharacterFactory::CreateCharacter(enumOfClass classtype, enumOfRace racetype)
{
    Race * raceReference = getRace(racetype);

    Character * retVal = nullptr;
    if(classtype == WizardClass)
    {
        retVal = new Wizard(raceReference);
    }
    else if(classtype == ClericClass)
    {
        retVal = new Cleric(raceReference);
    }
    else if(classtype == RogueClass)
    {
        retVal = new Rogue(raceReference);
    }
    else if(classtype == FighterClass);
    {
        retVal = new Fighter(raceReference);
    }

    return retVal;
}