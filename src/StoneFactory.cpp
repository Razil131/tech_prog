#include "StoneFactory.hpp"

std::shared_ptr<AbstractStone> StoneFactory::CreateRuby(StoneData& data) {
    return std::make_shared<Ruby>(
        data.hardness, data.cost, data.carats, 
        data.rarityLevel, data.fluorescence
    );
}

std::shared_ptr<AbstractStone> StoneFactory::CreateAmethyst(StoneData& data) {
    return std::make_shared<Amethyst>(
        data.hardness, data.cost, data.carats, 
        data.transparensyLevel, data.shade
    );
}

std::shared_ptr<AbstractStone> StoneFactory::CreateSapphire(StoneData& data) {
    return std::make_shared<Sapphire>(
        data.hardness, data.cost, data.carats, 
        data.rarityLevel, data.color
    );
}