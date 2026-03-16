#pragma once

#include <memory>
#include "AbstractStone.hpp"
#include "StoneData.hpp"
#include "Ruby.hpp"
#include "Sapphire.hpp"
#include "Amethyst.hpp"

class StoneFactory {
public:
    static std::shared_ptr<AbstractStone> CreateRuby(StoneData& data);
    static std::shared_ptr<AbstractStone> CreateAmethyst(StoneData& data);
    static std::shared_ptr<AbstractStone> CreateSapphire(StoneData& data);
};
