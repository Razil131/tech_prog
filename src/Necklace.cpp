#include "Necklace.hpp"


void Necklace::AddStone(std::shared_ptr<AbstractStone> stone){
    _Stones.push_back(stone);
    TotalWeight += stone->GetWeight();
    TotalCost += stone->GetWeight()*stone->GetCost();
}
void Necklace::RemoveStone(std::shared_ptr<AbstractStone> stone){
    auto it = std::find(_Stones.begin(), _Stones.end(), stone);
    if (it != _Stones.end()) {
        TotalWeight -= (*it)->GetWeight();
        TotalCost -= (*it)->GetWeight() * (*it)->GetCost();
        _Stones.erase(it);
    }
}