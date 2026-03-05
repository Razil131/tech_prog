#pragma once
#include "Necklace.hpp"
#include <iostream>

class NecklacePrinter {
public:
    static void PrintSummary(Necklace& necklace) {
        std::cout << "--- Necklace Info ---" << std::endl;
        std::cout << "Total Weight: " << necklace.GetTotalWeight() << " carats" << std::endl;
        std::cout << "Total Cost: $" << necklace.GetTotalCost() << std::endl;
        std::cout << "----------------------" << std::endl;
    }
};
