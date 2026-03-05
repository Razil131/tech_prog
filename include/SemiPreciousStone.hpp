#pragma once

#include "AbstractStone.hpp"
#include "Enums.hpp"

class SemiPreciousStone: public AbstractStone
{
public:
    SemiPreciousStone(double hardness, double cost, double carats, Transparensy transparensyLevel)
        :AbstractStone(hardness, cost, carats), TransparencyLevel(transparensyLevel){}
    ~SemiPreciousStone() {}
protected:
    Transparensy TransparencyLevel;
};