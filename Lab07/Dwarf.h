#pragma once
#include "Race.h"

class Dwarf : public Race
{
    public:
    Dwarf() : Race(3, 0, 4, 2)
    {

    }

    virtual ~Dwarf() {}
};