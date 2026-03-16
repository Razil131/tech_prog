#pragma once
#include <string>
#include "Enums.hpp"

struct StoneData {
    double hardness = 0.0;
    double cost = 0.0;
    double carats = 0.0;

    Rarity rarityLevel = Rarity::LOW;
    Transparensy transparensyLevel = Transparensy::TRANSPARENT;
    
    std::string fluorescence = "";
    std::string shade = "";
    std::string color = "";
};