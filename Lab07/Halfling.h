#pragma once
#include "Race.h"

class Halfling : public Race
{
    public:
    Halfling() : Race(1, 1, 2, 4)
    {

    }

    virtual ~Halfling() {}
};