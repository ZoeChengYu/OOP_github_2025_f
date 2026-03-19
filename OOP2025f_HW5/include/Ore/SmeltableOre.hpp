#ifndef SMELTABLEORE_HPP
#define SMELTABLEORE_HPP

#include "Ore.hpp"
#include "SmeltExp.hpp"

class SmeltableOre : public Ore {
public:
    explicit SmeltableOre(Product product, int durabilityCost);
    virtual ~SmeltableOre();

    float virtual  GetSmeltExp();
};

#endif
