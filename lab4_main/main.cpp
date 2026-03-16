#include <iostream>
#include <memory>
#include <vector>
#include "Necklace.hpp"
#include "StoneFactory.hpp"
#include "NecklacePrinter.hpp"

int main() {
    Necklace myNecklace;

    StoneData rubyData;
    rubyData.hardness = 9.0;
    rubyData.cost = 500.0;
    rubyData.carats = 2.5;
    rubyData.rarityLevel = Rarity::VERY_HIGH;
    rubyData.fluorescence = "Strong Red";
    auto ruby = StoneFactory::CreateRuby(rubyData);

    StoneData sapphireData;
    sapphireData.hardness = 9.0;
    sapphireData.cost = 400.0;
    sapphireData.carats = 3.0;
    sapphireData.rarityLevel = Rarity::HIGH;
    sapphireData.color = "Royal Blue";
    auto sapphire = StoneFactory::CreateSapphire(sapphireData);

    StoneData amethystData;
    amethystData.hardness = 7.0;
    amethystData.cost = 50.0;
    amethystData.carats = 10.0;
    amethystData.transparensyLevel = Transparensy::TRANSPARENT;
    amethystData.shade = "Deep Purple";
    auto amethyst = StoneFactory::CreateAmethyst(amethystData);

    myNecklace.AddStone(ruby);
    myNecklace.AddStone(sapphire);
    myNecklace.AddStone(amethyst);

    NecklacePrinter::PrintSummary(myNecklace);
    myNecklace.RemoveStone(sapphire);
    NecklacePrinter::PrintSummary(myNecklace);

    return 0;
}