#ifndef COPPER_ORE_HPP
#define COPPER_ORE_HPP

#include "ISmeltable.hpp"
#include "IConsumable.hpp"
#include "Ore.hpp"

class CopperOre final:public ISmeltable,public Ore,public IConsumable{
public:
    CopperOre();
    ~CopperOre();
    bool BreakableBy(Pickaxe pickaxe) override;
    std::shared_ptr<Ingot> Smelt() override;
    Material GetMaterial() const override;

};

#endif
