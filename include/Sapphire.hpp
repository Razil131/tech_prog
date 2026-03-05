#pragma once

#include <iostream>
#include "PreciousStone.hpp"

class Sapphire: public PreciousStone
{
public:
    Sapphire(double hardness, double cost, double carats, Rarity rarityLevel, std::string color)
        :PreciousStone(hardness, cost, carats, rarityLevel), Color(color){}
    ~Sapphire() {}
protected:
    std::string Color;
};