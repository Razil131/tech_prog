#pragma once

#include <memory>
#include "AbstractStone.hpp"
#include "Ruby.hpp"
#include "Sapphire.hpp"
#include "Amethyst.hpp"

class StoneFactory {
public:
    static std::shared_ptr<AbstractStone> CreateRuby(double hardness, double cost, double carats, Rarity rarityLevel, std::string fluorescence);
    static std::shared_ptr<AbstractStone> CreateAmethyst(double hardness, double cost, double carats, Transparensy transparensyLevel, std::string shade);
    static std::shared_ptr<AbstractStone> CreateSapphire(double hardness, double cost, double carats, Rarity rarityLevel, std::string color);
};