#pragma once

#include "AbstractStone.hpp"
#include "Enums.hpp"

class PreciousStone: public AbstractStone
{
public:
    PreciousStone(double hardness, double cost, double carats, Rarity rarityLevel)
        :AbstractStone(hardness, cost, carats), RarityLevel(rarityLevel){}
    ~PreciousStone() {}
protected:
    Rarity RarityLevel;
};