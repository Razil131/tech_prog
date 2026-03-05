#pragma once

#include <iostream>
#include "PreciousStone.hpp"

class Ruby: public PreciousStone
{
public:
    Ruby(double hardness, double cost, double carats, Rarity rarityLevel, std::string fluorescence)
        :PreciousStone(hardness, cost, carats, rarityLevel), Fluorescence(fluorescence){}
    ~Ruby() {}
protected:
    std::string Fluorescence;
};