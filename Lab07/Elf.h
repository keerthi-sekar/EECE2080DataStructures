#pragma once
#include "Race.h"

class Elf : public Race
{
    public:
    Elf() : Race(0, 1, 3, 5)
    {

    }

    virtual ~Elf() {}
};