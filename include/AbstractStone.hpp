#pragma once

class AbstractStone
{   
protected:
    double Hardness;
    double CostInDollarsPerCarat;
    double Carats;
public:
    AbstractStone(double hardness, double cost, double carats)
        :Hardness(hardness), CostInDollarsPerCarat(cost), Carats(carats) {}
    virtual ~AbstractStone() {}
    double GetWeight(){
        return Carats;
    }
    double GetCost(){
        return CostInDollarsPerCarat;
    }
};