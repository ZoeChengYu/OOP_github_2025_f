#ifndef COALORE_HPP
#define COALORE_HPP

#include "Ore.hpp"

class CoalOre : public Ore {
public:
    CoalOre();
    ~CoalOre() override = default;
    float GetBreakExp() override;
};

#endif