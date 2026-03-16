#include "Necklace.hpp"


void Necklace::AddStone(std::shared_ptr<AbstractStone> stone){
    _Stones.push_back(stone);
    UpdateTotals();
}

void Necklace::RemoveStone(std::shared_ptr<AbstractStone> stone){
    auto it = std::find(_Stones.begin(), _Stones.end(), stone);
    if (it != _Stones.end()) {
        UpdateTotals();
        _Stones.erase(it);
    }
}

void Necklace::RemoveStoneAt(int index) {
    if (index >= 0 && index < static_cast<int>(_Stones.size())) {
        _Stones.erase(_Stones.begin() + index);
        UpdateTotals();
    }
}

void Necklace::ReplaceStoneAt(int index, std::shared_ptr<AbstractStone> newStone) {
    if (index >= 0 && index < static_cast<int>(_Stones.size())) {
        _Stones[index] = newStone;
        UpdateTotals();
    }
}

void Necklace::UpdateTotals(){
    TotalCost = 0;
    TotalWeight = 0;
    for (auto stone:_Stones){
        TotalCost+=stone->GetCost()*stone->GetWeight();
        TotalWeight+=stone->GetWeight();
    }
}