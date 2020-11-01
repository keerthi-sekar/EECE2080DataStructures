// FleetAttack.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stack>
#include "Fleet.h"
#include "Iship.h"
#include "BattleShip.h"
#include "Cruiser.h"
#include "ShipFactory.h"
#include "Zerg.h"
#include "IRace.h"
#include "FleetAttack.h"


void FleetAttack::Attack()
{
    while(!m_done)
    {
        std::vector<IShip*> ships = determineOrderOfShips();

        for (auto it = ships.begin(); it < ships.end(); it++)
        {
            IShip *ship = *it;

            //isAlive
            if(ship->IsAlive())
            {
                //Attack

                //Need pick a target (and that alive)

                // Attack the target

                    // Apply the damage

            }

        }


    }
    printWinner();


}

std::vector<IShip*>  FleetAttack::determineOrderOfShips()
{
    std::vector<IShip*> retVal;

    IShip * temp1 = m_secondFleet->getFlagShip();

    retVal.push_back(temp1);

    auto flotilla = m_secondFleet->getFlotilla();

    retVal.push_back(flotilla[0]);


    IShip * temp3 = m_firstFleet->getFlagShip();

    retVal.push_back(temp3);

    return retVal;
}

void FleetAttack::printWinner()
{


}


int main()
{
	std::stack<int> myStack;


	Fleet<double> numberBox(5.4);
	Fleet<std::string> nameBox("ship");

	ShipFactory shipFactory;


	IShip* val = shipFactory.CreateShip(ShipFactory::BattleShipType, ShipFactory::ZergRace);

	BattleShip* battleShip = dynamic_cast<BattleShip*>(val);

    Cruiser* cruiserBad = dynamic_cast<Cruiser*>(val);

    Cruiser* cruiserBad2 = (Cruiser*)val;

    Fleet<IShip*> *fleet1 = new Fleet<IShip*>(battleShip);

    val = shipFactory.CreateShip(ShipFactory::CruiserType, ShipFactory::HumanRace);

    Cruiser* cruiser = dynamic_cast<Cruiser*>(val);

    Fleet<IShip*> *fleet2 = new Fleet<IShip*>(cruiser);

    val = shipFactory.CreateShip(ShipFactory::CruiserType, ShipFactory::HumanRace);

    fleet2->addFlotilla(val);

    std::vector<IShip*> flotilla = fleet2->getFlotilla();


    FleetAttack fleetAttack(fleet1,fleet2);
    fleetAttack.Attack();

    std::cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
