#pragma once

#include "IRace.h"
#include "Iship.h"

#include <map>

//fwd declaration
class Human;
class Zerg;

class ShipFactory
{
public:


	enum enumOfTypeShip { BattleShipType, CruiserType };
	enum enumOfRace { ZergRace, HumanRace, ProtosRace };

	ShipFactory();

	IShip* CreateShip(enumOfTypeShip typeOfShip, enumOfRace race);

    virtual ~ShipFactory() {}

private:

	IRace* getRace(enumOfRace enumOfRaceToRetrieve);

	//std::map< enumOfRace, IRace*> m_raceMap;

	Human *m_human;
	Zerg *m_zerg;

};

