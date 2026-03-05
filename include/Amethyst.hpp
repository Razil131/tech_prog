#pragma once

#include <iostream>
#include "SemiPreciousStone.hpp"

class Amethyst: public SemiPreciousStone{
public:
    Amethyst(double hardness, double cost, double carats, Transparensy transparensyLevel, std::string shade)
        :SemiPreciousStone(hardness, cost, carats, transparensyLevel), Shade(shade){}
    ~Amethyst() {}
protected:
    std::string Shade;
};