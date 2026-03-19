#ifndef DIAMONDORE_HPP
#define DIAMONDORE_HPP

#include "Ore.hpp"

class DiamondOre : public Ore {
public:
    DiamondOre();
    ~DiamondOre() override = default;
    float GetBreakExp() override;
};

#endif