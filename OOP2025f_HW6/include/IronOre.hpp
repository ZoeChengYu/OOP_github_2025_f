#ifndef IRON_ORE_HPP
#define IRON_ORE_HPP

#include "ISmeltable.hpp"
#include "Ore.hpp"
#include "Ingot.hpp"
#include <memory>

class IronOre final : public ISmeltable,public Ore{
public:
    IronOre();
    ~IronOre();
    std::shared_ptr<Ingot> Smelt() override;
    bool BreakableBy(Pickaxe pickaxe) override;
};

#endif
