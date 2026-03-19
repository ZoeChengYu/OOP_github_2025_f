#ifndef GOLD_ORE_HPP
#define GOLD_ORE_HPP

#include "ISmeltable.hpp"
#include "Ore.hpp"

class GoldOre final:public ISmeltable,public Ore{
public:
    GoldOre();
    ~GoldOre();
    bool BreakableBy(Pickaxe pickaxe) override;
    std::shared_ptr<Ingot> Smelt() override;

};

#endif
