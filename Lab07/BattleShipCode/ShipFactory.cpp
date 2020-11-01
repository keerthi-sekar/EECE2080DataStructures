#include "ShipFactory.h"

#include "BattleShip.h"
#include "Cruiser.h"

#include "Zerg.h"
#include "Human.h"

ShipFactory::ShipFactory()
{
	//m_raceMap[ShipFactory::enumOfRace::ZergRace] = new Zerg();
	//m_raceMap[ShipFactory::enumOfRace::HumanRace] = new Human();

	m_zerg = new Zerg();
	m_human = new Human();

}

IRace* ShipFactory::getRace(enumOfRace enumOfRaceToRetrieve)
{
	switch(enumOfRaceToRetrieve) 
	{
		case ShipFactory::ZergRace:
			return m_zerg;
			break;
		case ShipFactory::HumanRace:
			return m_human;
			break;
		default:
			throw "NIY";
	}
}


IShip* ShipFactory::CreateShip(enumOfTypeShip enumOfTypeShipType, enumOfRace race)
{



	IRace * raceReference = getRace(race); //m_raceMap[race];

	IShip* retVal = nullptr;
	if (enumOfTypeShipType == BattleShipType)
	{
		retVal = new BattleShip(raceReference);
	}
    else if (enumOfTypeShipType == CruiserType)
    {
        retVal = new Cruiser(raceReference);
    }

	return retVal;
}
