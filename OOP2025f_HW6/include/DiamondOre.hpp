#ifndef DIAMOND_ORE_HPP
#define DIAMOND_ORE_HPP

#include "Ore.hpp"
#include "IConsumable.hpp"

class DiamondOre final:public Ore,public IConsumable{
public:
    DiamondOre();
    ~DiamondOre();
    bool BreakableBy(Pickaxe pickaxe) override;
    Material GetMaterial() const override;
};

#endif
