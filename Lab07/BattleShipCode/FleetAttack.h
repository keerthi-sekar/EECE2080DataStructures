#pragma once

#include "Fleet.h"


class FleetAttack
{
public:
	FleetAttack(Fleet<IShip*> *firstFleet, Fleet<IShip*> * secondFleet) 
    {
        m_done = false;
    }

    void Attack() ;

    ~FleetAttack() {}
protected:

    void printWinner();

    std::vector<IShip*>  determineOrderOfShips();

    bool m_done;
    Fleet<IShip*>  * m_firstFleet;
    Fleet<IShip*>  * m_secondFleet;


};

