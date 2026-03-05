#include "StoneFactory.hpp"

std::shared_ptr<AbstractStone> StoneFactory::CreateRuby(double hardness, double cost, double carats, Rarity rarityLevel, std::string fluorescence) {
    return std::make_shared<Ruby>(hardness, cost, carats, rarityLevel, fluorescence);
}

std::shared_ptr<AbstractStone> StoneFactory::CreateAmethyst(double hardness, double cost, double carats, Transparensy transparensyLevel, std::string shade) {
    return std::make_shared<Amethyst>(hardness, cost, carats, transparensyLevel, shade);
}

std::shared_ptr<AbstractStone> StoneFactory::CreateSapphire(double hardness, double cost, double carats, Rarity rarityLevel, std::string color) {
    return std::make_shared<Sapphire>(hardness, cost, carats, rarityLevel, color);
}