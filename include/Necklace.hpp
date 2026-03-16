#pragma once

#include <vector>
#include <algorithm>
#include <memory>
#include "AbstractStone.hpp"

class Necklace
{
private:
    std::vector<std::shared_ptr<AbstractStone>> _Stones;
    double TotalWeight = 0;
    double TotalCost = 0;
public:
    void AddStone(std::shared_ptr<AbstractStone> stone);

    void RemoveStone(std::shared_ptr<AbstractStone> stone);
    
    void RemoveStoneAt(int index);

    void ReplaceStoneAt(int index, std::shared_ptr<AbstractStone> newStone);

    void UpdateTotals();
    
    double GetTotalWeight(){
        return TotalWeight;
    }

    double GetTotalCost(){
        return TotalCost;
    }
};