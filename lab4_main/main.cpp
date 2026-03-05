#include <iostream>
#include <memory>
#include <vector>
#include "Necklace.hpp"
#include "StoneFactory.hpp"
#include "NecklacePrinter.hpp"

int main() {
    Necklace myNecklace;

    auto ruby = StoneFactory::CreateRuby(9.0, 500.0, 2.5, Rarity::VERY_HIGH, "Strong Red");
    auto sapphire = StoneFactory::CreateSapphire(9.0, 400.0, 3.0, Rarity::HIGH, "Royal Blue");
    auto amethyst = StoneFactory::CreateAmethyst(7.0, 50.0, 10.0, Transparensy::TRANSPARENT, "Deep Purple");

    myNecklace.AddStone(ruby);
    myNecklace.AddStone(sapphire);
    myNecklace.AddStone(amethyst);

    NecklacePrinter::PrintSummary(myNecklace);

    myNecklace.RemoveStone(sapphire);

    NecklacePrinter::PrintSummary(myNecklace);

    return 0;
}
